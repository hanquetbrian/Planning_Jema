#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <String>
class Employee {
public:
    explicit Employee(const std::string& name);

    std::string getName() const;
private:
    std::string m_name;
    int m_nbAbsence;
};

#endif // EMPLOYEE_H
