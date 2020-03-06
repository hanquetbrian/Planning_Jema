#ifndef SQLITEEMPLOYEE_H
#define SQLITEEMPLOYEE_H

#include "sqlite3.h"
#include "employeeabstractdata.h"

class sqliteEmployee: public EmployeeAbstractData
{
public:
    sqliteEmployee(std::string connect_info = "planning.db");

    bool connect() override;
    bool close() override;
    bool update() override;
    bool write() override;

private:
    sqlite3 *m_db;
    bool m_isConnected;

    void createDefaultDataBase();

};

#endif // SQLITEEMPLOYEE_H
