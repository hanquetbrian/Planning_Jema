#ifndef PLANNINGABSTRACTDATA_H
#define PLANNINGABSTRACTDATA_H

#include <string>
class PlanningAbstractData
{
public:
    PlanningAbstractData(std::string connect_info);
    virtual bool connect() = 0;
    virtual bool close() = 0;
    virtual bool update() = 0;
    virtual bool write() = 0;

protected:
    std::string m_conect_info;
};

#endif // PLANNINGABSTRACTDATA_H
