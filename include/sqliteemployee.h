#ifndef SQLITEEMPLOYEE_H
#define SQLITEEMPLOYEE_H

#include "sqlite3.h"

class sqliteEmployee
{
public:
    sqliteEmployee();

    void connect();

private:
    sqlite3 *db;
};

#endif // SQLITEEMPLOYEE_H
