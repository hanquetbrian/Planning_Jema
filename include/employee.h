#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <String>
#include <iostream>

class Employee {
public:
    explicit Employee(const std::string& name);

    std::string getName() const;

private:
    std::string m_name;
    int m_nbAbsence;
};

std::ostream & operator<<(std::ostream & Str, Employee const & v);

#endif // EMPLOYEE_H
