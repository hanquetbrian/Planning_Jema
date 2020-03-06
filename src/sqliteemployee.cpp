#include <iostream>
#include <fstream>

#include "sqliteemployee.h"
#include "sqlite3.h"


sqliteEmployee::sqliteEmployee(std::string connect_info):
    EmployeeAbstractData(connect_info), m_isConnected(false)
{

}

bool sqliteEmployee::connect() {
    int rc = sqlite3_open(m_conect_info.c_str(), &m_db);

    if(rc != SQLITE_OK || m_isConnected) {
        return false;
    }

    createDefaultDataBase();
    m_isConnected = true;
    return true;

}

bool sqliteEmployee::close() {
    int rc = sqlite3_close(m_db);
    if(rc == SQLITE_OK) {
        m_isConnected = false;
        return true;
    }
    return false;
}

bool sqliteEmployee::update() {
    return false;
}

bool sqliteEmployee::write() {
    return false;
}

static int callback(void*, int argc, char **argv, char **azColName) {
    std::cout << "nice" << std::endl;
    int i;
    for(i = 0; i<argc; i++) {
       std::cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << std::endl;
    }

    return 0;
};

void sqliteEmployee::createDefaultDataBase() {
    std::string defaultTableFilename = "test.txt";
    {
       std::ifstream istrm(defaultTableFilename, std::ios::out);
        std::string text;
        istrm >> text;
        std::cout << text << std::endl;
    }

//    char *zErrMsg = 0;
//    std::string sql = "CREATE TABLE COMPANY("  \
//                       "ID INT PRIMARY KEY     NOT NULL," \
//                       "NAME           TEXT    NOT NULL," \
//                       "AGE            INT     NOT NULL," \
//                       "ADDRESS        CHAR(50)," \
//                       "SALARY         REAL );";

//    int rc = sqlite3_exec(m_db, sql.c_str(), callback, 0, &zErrMsg);
//    if( rc != SQLITE_OK ){
//         fprintf(stderr, "SQL error: %s\n", zErrMsg);
//         sqlite3_free(zErrMsg);
//      } else {
//         fprintf(stdout, "Table created successfully\n");
//      }
}
