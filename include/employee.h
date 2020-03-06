#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <memory>
#include "employeeabstractdata.h"
#include "sqliteemployee.h"

class Employee {
public:
    explicit Employee(const std::string& name, EmployeeAbstractData* data_connection);

    std::string getName() const;

private:
    std::string m_name;
    int m_nbAbsence;
    EmployeeAbstractData* m_data_connection;
};

std::ostream & operator<<(std::ostream & Str, Employee const & v);

#endif // EMPLOYEE_H
