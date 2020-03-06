
# Header
set(HEADER_LIST
    ../include/planning.hpp
    ../include/employee.h
    ../include/sqliteemployee.h
    ../include/employeeabstractdata.h
)

set(SOURCE_LIST
    planning.cpp
    employee.cpp
    sqliteemployee.cpp
    employeeabstractdata.cpp
)

add_library(planning_lib STATIC ${SOURCE_LIST} ${HEADER_LIST})

target_include_directories(planning_lib PUBLIC ../include)

source_group(TREE "${PROJECT_SOURCE_DIR}/include" PREFIX "Header Files" FILES ${HEADER_LIST})

target_link_libraries(planning_lib PRIVATE sqlite3)
