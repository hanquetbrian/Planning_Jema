cmake_minimum_required(VERSION 3.10)

project(planning_software
        VERSION "0.5"
	DESCRIPTION "Planning Jema"
        LANGUAGES CXX)

# Only execute this if it's the main project
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
        set(CMAKE_CXX_STANDARD 17)
	set(CMAKE_CXX_STANDARD_REQUIRED ON)
	set(CMAKE_INCLUDE_CURRENT_DIR ON)
        set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "cmake/")
endif()
include(FindSQLite3)
set(Boost_DEBUG 1)
configure_file(version_config.h.in include/version_config.h @ONLY)

# compiled library
add_subdirectory(src)

# executable
add_subdirectory(apps)

add_subdirectory(lib/sqlite3)

# Testing only available if this is the main app
# Emergency override MODERN_CMAKE_BUILD_TESTING provided as well
#if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR MODERN_CMAKE_BUILD_TESTING) AND BUILD_TESTING)
#    add_subdirectory(tests)
#endif()
