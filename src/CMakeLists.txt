
# Header
set(HEADER_LIST
    ../include/employee.h
    ../include/sqliteplanning.h
    ../include/planningabstractdata.h
    ../include/wo.h
    ../mssqlhandler.h
)

set(SOURCE_LIST
    employee.cpp
    sqliteplanning.cpp
    planningabstractdata.cpp
    wo.cpp
    mssqlhandler.cpp
)
set(Boost_ARCHITECTURE -x64)
set(BOOST_ROOT C:/Boost)
set(BOOST_INCLUDEDIR C:/Boost/include)
set(BOOST_LIBRARYDIR C:/Boost/lib)

set(SQLite3_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/lib/sqlite3/inc)
set(SQLite3_LIBRARY ${PROJECT_SOURCE_DIR}/lib/sqlite3/lib)

#set(Boost_DEBUG 1)
find_package(Boost 1.72.0 COMPONENTS system filesystem)
find_package(SQLite3)
if(Boost_FOUND AND SQLite3_FOUND)
    add_library(planning_lib STATIC ${SOURCE_LIST} ${HEADER_LIST})
    target_include_directories(planning_lib PUBLIC ${Boost_INCLUDE_DIRS})
    target_include_directories(planning_lib PUBLIC ${SQLite3_INCLUDE_DIRS})
endif()

target_include_directories(planning_lib PUBLIC ../include)

target_link_libraries(planning_lib PRIVATE ${Boost_LIBRARIES} ${SQLite3_LIBRARY}/sqlite3.dll)

source_group(TREE "${PROJECT_SOURCE_DIR}/include" PREFIX "Header Files" FILES ${HEADER_LIST})
