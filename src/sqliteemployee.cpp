#include "sqliteemployee.h"
#include "sqlite3.h"

#include <iostream>
sqliteEmployee::sqliteEmployee()
{

}

void sqliteEmployee::connect() {
    int rc = sqlite3_open("planning.db", &db);

    if(rc) {
        std::cout << "can't open it" << std::endl;
    } else {
        std::cout << "opened database successfully" << std::endl;
    }
}
