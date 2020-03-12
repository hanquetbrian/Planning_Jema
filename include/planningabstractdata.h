#ifndef PLANNINGABSTRACTDATA_H
#define PLANNINGABSTRACTDATA_H

#include <list>
#include <string>

#include "employee.h"

class PlanningAbstractData
{
public:
    PlanningAbstractData(std::string connect_info);

    // Virtual function
    virtual bool connect() = 0;
    virtual bool close() = 0;
    virtual std::list<Employee> getListEmployee() const = 0;
    virtual bool addEmployee(const Employee&) = 0;

    // public function


protected:
    std::string m_conect_info;
};

#endif // PLANNINGABSTRACTDATA_H
