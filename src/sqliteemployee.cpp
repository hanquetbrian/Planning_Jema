#include "sqliteemployee.h"
#include "sqlite3.h"

#include <iostream>
sqliteEmployee::sqliteEmployee()
{

}

void sqliteEmployee::connect() {
    int rc = sqlite3_open("planning.db", &m_db);

    if(rc) {
        std::cout << "can't open it" << std::endl;
    } else {
        std::cout << "opened database successfully" << std::endl;

    }

}

void sqliteEmployee::close() {
    sqlite3_close(m_db);
}


void sqliteEmployee::createDefaultDataBase() {
    std::string sql = "CREATE TABLE COMPANY("  \
                       "ID INT PRIMARY KEY     NOT NULL," \
                       "NAME           TEXT    NOT NULL," \
                       "AGE            INT     NOT NULL," \
                       "ADDRESS        CHAR(50)," \
                       "SALARY         REAL );";
    rc = sqlite3_exec(m_db, sql, )
}
