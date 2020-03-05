#ifndef SQLITEEMPLOYEE_H
#define SQLITEEMPLOYEE_H

#include "sqlite3.h"

class sqliteEmployee
{
public:
    sqliteEmployee();

    void connect();
    void close();

private:
    sqlite3 *m_db;

    void createDefaultDataBase();
    int callback(void *NotUsed, int argc, char **argv, char **azColName) {
        int i;
        for(i = 0; i<argc; i++) {
           printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
        }
        printf("\n");
        return 0;
    }
};

#endif // SQLITEEMPLOYEE_H
