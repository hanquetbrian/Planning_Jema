cmake_minimum_required(VERSION 3.10)

project(planning_software
	VERSION 0.2
	DESCRIPTION "Planning Jema"
	LANGUAGES CXX)

# Only execute this if it's the main project
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
	set(CMAKE_CXX_STANDARD 11)
	set(CMAKE_CXX_STANDARD_REQUIRED ON)
	set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

# compiled library
add_subdirectory(src)

# executable
add_subdirectory(apps)

# Testing only available if this is the main app
# Emergency override MODERN_CMAKE_BUILD_TESTING provided as well
#if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR MODERN_CMAKE_BUILD_TESTING) AND BUILD_TESTING)
#    add_subdirectory(tests)
#endif()
