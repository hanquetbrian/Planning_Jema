#ifndef SQLITEPLANNING_H
#define SQLITEPLANNING_H

#include <list>
#include <string>

#include "sqlite3.h"
#include "employee.h"
#include "planningabstractdata.h"

class SqlitePlanning: public PlanningAbstractData
{
public:
    SqlitePlanning(std::string connect_info = "planning.db");

    bool connect() override;
    bool close() override;
    std::list<Employee> getListEmployee() const override;
    bool addEmployee(const Employee& employee) override;

private:
    sqlite3 *m_db;
    bool m_isConnected;
    bool m_first_creation;

    bool _createDefaultDataBase();
};

#endif // SQLITEPLANNING_H
