#ifndef SQLITEPLANNING_H
#define SQLITEPLANNING_H

#include "sqlite3.h"
#include "planningabstractdata.h"

class SqlitePlanning: public PlanningAbstractData
{
public:
    SqlitePlanning(std::string connect_info = "planning.db");

    bool connect() override;
    bool close() override;
    bool update() override;
    bool write() override;

private:
    sqlite3 *m_db;
    bool m_isConnected;

    bool createDefaultDataBase();

};

#endif // SQLITEPLANNING_H
