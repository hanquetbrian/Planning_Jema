#include "employee.h"

Employee::Employee(const std::string& name, bool hide, int nb_absence)
    : m_name(name), m_hide(hide), m_nbAbsence(nb_absence), m_responsible(nullptr) {

}

std::string Employee::getName() const {
    return m_name;
}

bool Employee::is_hide() const {
    return m_hide;
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

void Employee::setHide(bool hide) {
    m_hide = hide;
}

void Employee::setNbAbsence(int nbAbsence) {
    m_nbAbsence = nbAbsence;
}


std::ostream & operator<<(std::ostream & os, Employee const & val) {
    os << "Name: " << val.getName() << " isHide: " << std::boolalpha << val.is_hide() << " Nb Absence: " << val.getNbAbsence();
    return os;
}
