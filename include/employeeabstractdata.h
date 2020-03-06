#ifndef EMPLOYEEABSTRACTDATA_H
#define EMPLOYEEABSTRACTDATA_H

#include <string>
class EmployeeAbstractData
{
public:
    EmployeeAbstractData(std::string connect_info);
    virtual bool connect() = 0;
    virtual bool close() = 0;
    virtual bool update() = 0;
    virtual bool write() = 0;

protected:
    std::string m_conect_info;
};

#endif // EMPLOYEEABSTRACTDATA_H
