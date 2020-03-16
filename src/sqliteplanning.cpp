#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/function.hpp>
#include <boost/lexical_cast.hpp>

#include "sqliteplanning.h"


SqlitePlanning::SqlitePlanning(std::string connect_info):
    PlanningAbstractData(connect_info), m_isConnected(false), m_first_creation(false)
{
    if (!boost::filesystem::exists(connect_info)) {
        std::cout << "creation of the database..." << std::endl;
        m_first_creation = true;
    }
}

bool SqlitePlanning::connect() {
    int rc = sqlite3_open(m_conect_info.c_str(), &m_db);

    if(rc != SQLITE_OK || m_isConnected) {
        return false;
    }

    if(m_first_creation) {_createDefaultDataBase();}
    m_isConnected = true;
    return true;

}

bool SqlitePlanning::close() {
    int rc = sqlite3_close(m_db);
    if(rc == SQLITE_OK) {
        m_isConnected = false;
        return true;
    }
    return false;
}

std::list<Employee> SqlitePlanning::getListEmployee() const {
    std::list<Employee> listEmployee {};
    char *zErrMsg{0};
    std::string sql = "SELECT * FROM Employee";

    auto callback = [](void *data, int /*argc: nb column*/, char **argv, char ** /*azColName: column name*/) -> int {
        std::string name {argv[1]};
        bool hide = boost::lexical_cast<bool> (argv[2]);
        int nb_absence = atoi(argv[3]);
        Employee newEmployee(name, hide, nb_absence);
        static_cast<std::list<Employee>*>(data)->push_back(newEmployee);
        return 0;
    };

    int rc = sqlite3_exec(m_db, sql.c_str(), callback, &listEmployee, &zErrMsg);

    if( rc != SQLITE_OK ){
        std::cerr << "Error when getting the employees: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
        return std::list<Employee>{};
    }
    return listEmployee;
}

bool SqlitePlanning::addEmployee(const Employee& employee) {
    char *zErrMsg{0};
    std::stringstream sql;
    sql << "INSERT INTO Employee (name, is_hide) VALUES ('" << employee.getName() << "', " << employee.is_hide() << ");";

    int rc = sqlite3_exec(m_db, sql.str().c_str(), [](void*, int, char **, char **){return 0;}, 0, &zErrMsg);

    if( rc != SQLITE_OK ){
        std::cerr << "Error when inserting a new employee: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
        return false;
    }
    return true;
}

bool SqlitePlanning::_createDefaultDataBase() {
    std::string sql = R"sql(
            create table IF NOT EXISTS Employee
            (
                id             INTEGER PRIMARY KEY AUTOINCREMENT,
                name           VARCHAR(50) not null,
                is_hide        BOOLEAN default false,
                nb_absence     INTEGER,
                responsible_id INTEGER,
                foreign key (responsible_id) references Employee
                    on update restrict on delete set null
            );

            create table IF NOT EXISTS Leave
            (
                id          INTEGER PRIMARY KEY AUTOINCREMENT,
                employee_id INTEGER,
                label       VARCHAR(30) not null,
                date_from   DATE        not null,
                date_to     DATE        not null,
                foreign key (employee_id) references Employee
                    on update restrict on delete restrict
            );

            create table IF NOT EXISTS Post
            (
                id    INTEGER PRIMARY KEY AUTOINCREMENT,
                label VARCHAR not null
            );

            create table IF NOT EXISTS Employee_Post
            (
                id          INTEGER PRIMARY KEY AUTOINCREMENT,
                employee_id INTEGER not null,
                post_id     INTEGER not null,
                foreign key (employee_id) references Employee
                    on update restrict on delete restrict,
                foreign key (post_id) references Post
                    on update cascade on delete cascade
            );

            create table IF NOT EXISTS Skill
            (
                id    INTEGER PRIMARY KEY AUTOINCREMENT,
                label VARCHAR not null
            );

            create table IF NOT EXISTS Employee_Skill
            (
                id          INTEGER PRIMARY KEY AUTOINCREMENT,
                skill_id    INTEGER not null,
                employee_id INTEGER not null,
                foreign key (skill_id) references Skill
                    on update restrict on delete restrict,
                foreign key (employee_id) references Employee
                    on update restrict on delete restrict
            );

            create table IF NOT EXISTS Task_state
            (
                id    INTEGER PRIMARY KEY AUTOINCREMENT,
                label VARCHAR(30) not null
            );

            create table IF NOT EXISTS Task_type
            (
                id   INTEGER PRIMARY KEY AUTOINCREMENT,
                type VARCHAR(30) not null
            );

            create table IF NOT EXISTS Task_so
            (
                id        INTEGER PRIMARY KEY AUTOINCREMENT,
                label     VARCHAR(50),
                type_id   INTEGER         not null,
                wo_id     INTEGER,
                so_id     INTEGER,
                date_from DATE        not null,
                date_to   DATE        not null,
                hour_from TEXT,
                hour_to   TEXT,
                comment   TEXT,
                state_id  INTEGER,
                foreign key (type_id) references Task_type
                    on update restrict on delete restrict,
                foreign key (state_id) references Task_state
                    on update restrict on delete restrict
            );

            create table Task_test
            (
                id        INTEGER PRIMARY KEY AUTOINCREMENT,
                name      VARCHAR(50) not null,
                test_date DATE        not null,
                wo_id     INTEGER,
                Comment   VARCHAR(255),
                state_id  INTEGER default 2 not null
                    references Task_state
                        on update restrict on delete restrict
            );

            create table IF NOT EXISTS Employee_Task_so
            (
                id          INTEGER PRIMARY KEY AUTOINCREMENT,
                employee_id INTEGER not null,
                task_so_id     INTEGER not null,
                foreign key (employee_id) references Employee
                    on update restrict on delete restrict,
                foreign key (task_so_id) references Task_so
                    on update restrict on delete restrict
            );

            create table IF NOT EXISTS User
            (
                id       INTEGER PRIMARY KEY AUTOINCREMENT,
                username VARCHAR(30) not null,
                password VARCHAR(50) not null
            );

            INSERT INTO Task_state (id, label) VALUES (1, 'Finished');
            INSERT INTO Task_state (id, label) VALUES (2, 'In progress');
            INSERT INTO Task_state (id, label) VALUES (3, 'Waiting');

            INSERT INTO Task_type (id, type) VALUES (1, 'SO');
            INSERT INTO Task_type (id, type) VALUES (2, 'Test');
            INSERT INTO Task_type (id, type) VALUES (3, 'Other');

)sql";

    char *zErrMsg = 0;

    int rc = sqlite3_exec(m_db, sql.c_str(), [](void*, int, char **, char **){return 0;}, 0, &zErrMsg);
    if( rc != SQLITE_OK ){
        std::cerr << "Can't create the database: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
        return false;
    }
    return true;
}
