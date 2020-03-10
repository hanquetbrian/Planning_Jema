
# Header
set(HEADER_LIST
    ../include/planning.hpp
    ../include/employee.h
    ../include/sqliteplanning.h
    ../include/planningabstractdata.h
)

set(SOURCE_LIST
    planning.cpp
    employee.cpp
    sqliteplanning.cpp
    planningabstractdata.cpp
)
set(Boost_ARCHITECTURE -x64)
set(BOOST_ROOT C:/Boost)
set(BOOST_INCLUDEDIR C:/Boost/include/boost-1_72)
set(BOOST_LIBRARYDIR C:/Boost/lib)

#set(Boost_DEBUG 1)
find_package(Boost 1.72.0 COMPONENTS system filesystem)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_library(planning_lib STATIC ${SOURCE_LIST} ${HEADER_LIST})
endif()

target_include_directories(planning_lib PUBLIC ../include)

target_link_libraries(planning_lib PRIVATE ${Boost_LIBRARIES} sqlite3)

source_group(TREE "${PROJECT_SOURCE_DIR}/include" PREFIX "Header Files" FILES ${HEADER_LIST})
