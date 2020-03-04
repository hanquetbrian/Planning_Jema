#include "employee.h"

Employee::Employee(const std::string& name)
    : m_name(name){

}

std::string Employee::getName() const {
    return m_name;
}
