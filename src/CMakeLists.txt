
# Header
set(HEADER_LIST "../include/planning.hpp")

add_library(planning_lib STATIC planning.cpp ${HEADER_LIST})

target_include_directories(planning_lib PUBLIC ../include)

source_group(TREE "${PROJECT_SOURCE_DIR}/include" PREFIX "Header Files" FILES ${HEADER_LIST})
