#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <memory>
#include "planningabstractdata.h"
#include "sqliteplanning.h"

class Employee {
public:
    explicit Employee(const std::string& name, PlanningAbstractData* data_connection);

    std::string getName() const;

private:
    std::string m_name;
    int m_nbAbsence;
    PlanningAbstractData* m_data_connection;
};

std::ostream & operator<<(std::ostream & Str, Employee const & v);

#endif // EMPLOYEE_H
