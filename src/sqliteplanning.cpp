#include <iostream>
#include <fstream>
#include <cstdint>
#include <boost/filesystem.hpp>


#include "sqliteplanning.h"
#include "sqlite3.h"


SqlitePlanning::SqlitePlanning(std::string connect_info):
    PlanningAbstractData(connect_info), m_isConnected(false)
{
    std::cout << "file size: " << boost::filesystem::file_size(connect_info) << std::endl;
    {};
}

bool SqlitePlanning::connect() {
    int rc = sqlite3_open(m_conect_info.c_str(), &m_db);

    if(rc != SQLITE_OK || m_isConnected) {
        return false;
    }

    createDefaultDataBase();
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

bool SqlitePlanning::update() {
    return false;
}

bool SqlitePlanning::write() {
    return false;
}

static int callback(void*, int, char **, char **) {

    return 0;
};

bool SqlitePlanning::createDefaultDataBase() {
    std::string sql = R"sql(
            create table IF NOT EXISTS Employee
            (
                id             INTEGER PRIMARY KEY AUTOINCREMENT,
                name           VARCHAR(50) not null,
                display        BOOLEAN default true,
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

            create table IF NOT EXISTS Task
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

            create table IF NOT EXISTS Employee_Task
            (
                id          INTEGER PRIMARY KEY AUTOINCREMENT,
                employee_id INTEGER not null,
                task_id     INTEGER not null,
                foreign key (employee_id) references Employee
                    on update restrict on delete restrict,
                foreign key (task_id) references Task
                    on update restrict on delete restrict
            );

            create table IF NOT EXISTS User
            (
                id       INTEGER PRIMARY KEY AUTOINCREMENT,
                username VARCHAR(30) not null,
                password VARCHAR(50) not null
            );

            INSERT INTO Task_state (label) VALUES ('In progress')
            [2020-03-09 11:26:18] 1 row affected in 8 ms
            main> INSERT INTO Task_state (label) VALUES ('Finished')

)sql";

    char *zErrMsg = 0;

    int rc = sqlite3_exec(m_db, sql.c_str(), callback, 0, &zErrMsg);
    if( rc != SQLITE_OK ){
        std::cerr << "Can't create the database: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
        return false;
    }
    return true;
}
