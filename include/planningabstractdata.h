#ifndef PLANNINGABSTRACTDATA_H
#define PLANNINGABSTRACTDATA_H

#include <list>
#include <string>

#include "employee.h"

class PlanningAbstractData
{
public:
    PlanningAbstractData(std::string connect_info);
    virtual bool connect() = 0;
    virtual bool close() = 0;
    virtual std::list<Employee> getListEmployee() const = 0;
    virtual bool addEmployee(const Employee&) = 0;

protected:
    std::string m_conect_info;
};

#endif // PLANNINGABSTRACTDATA_H
