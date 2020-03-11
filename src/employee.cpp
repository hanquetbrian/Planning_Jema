#include "employee.h"

Employee::Employee(const std::string& name, bool display, int nb_absence)
    : m_name(name), m_display(display), m_nbAbsence(nb_absence), m_responsible(nullptr) {

}

std::string Employee::getName() const {
    return m_name;
}

bool Employee::is_display() const {
    return m_display;
}

int Employee::getNbAbsence() const {
    return m_nbAbsence;
}


void Employee::setName(const std::string& name) {
    m_name = name;
}

void Employee::setName(std::string&& name) {
    m_name = name;
}

void Employee::setDisplay(bool display) {
    m_display = display;
}

void Employee::setNbAbsence(int nbAbsence) {
    m_nbAbsence = nbAbsence;
}


std::ostream & operator<<(std::ostream & os, Employee const & val) {
    os << "Name: " << val.getName() << " isDisplay: " << std::boolalpha << val.is_display() << " Nb Absence: " << val.getNbAbsence();
    return os;
}
