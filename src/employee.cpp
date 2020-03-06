#include "employee.h"

Employee::Employee(const std::string& name, EmployeeAbstractData* data_connection)
    : m_name(name), m_data_connection(data_connection) {

}

std::string Employee::getName() const {
    return m_name;
}

std::ostream & operator<<(std::ostream & os, Employee const & val) {
    os << val.getName();
    return os;
}
