#ifndef SQLITEPLANNING_H
#define SQLITEPLANNING_H

#include <list>
#include <string>

#include "sqlite3.h"
#include "employee.h"
#include "planningabstractdata.h"
#include "mssqlhandler.h"

class SqlitePlanning: public PlanningAbstractData
{
public:
    SqlitePlanning(std::string connect_info = "planning.db");

    bool connect() override;
    bool close() override;
    std::list<Employee> getListEmployee() const override;
    bool addEmployee(const Employee& employee) override;
    bool addTaskSO(std::string title, int so_id, int wo_id, std::string date_from, std::string date_to, std::string hour_from, std::string hour_to, std::string comment, int state) override;
    bool addTaskTest(std::string name, int wo_id, std::string testDate, std::string comment, int state) override;

private:
    sqlite3 *m_db;
    MssqlHandler mssqlHandler;
    bool m_isConnected;
    bool m_first_creation;

    bool _createDefaultDataBase();
};

#endif // SQLITEPLANNING_H
