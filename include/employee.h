#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

class Employee {
public:
    explicit Employee(const std::string& name, bool display = true, int nb_absence = 0);

    std::string getName() const;
    bool is_display() const;
    int getNbAbsence() const;

    void setName(const std::string& name);
    void setName(std::string&& name);

    void setDisplay(bool display);
    void setNbAbsence(int nbAbsence);

private:
    std::string m_name;
    bool m_display;
    int m_nbAbsence;
    Employee* m_responsible; //Not implemented yet
};

std::ostream & operator<<(std::ostream & Str, Employee const & v);

#endif // EMPLOYEE_H
