PROJECT(sqlite3)
cmake_minimum_required(VERSION 2.8)

add_library(sqlite3 STATIC src/sqlite3.c src/sqlite3.h)
target_include_directories(sqlite3 PUBLIC src)
#add_executable(sqlite src/sqlite3.c src/shell.c src/sqlite3.h src/sqlite3ext.h)

add_definitions(-DSQLITE_ENABLE_RTREE)
add_definitions(-DSQLITE_ENABLE_FTS4)
add_definitions(-DSQLITE_ENABLE_FTS5)
add_definitions(-DSQLITE_ENABLE_JSON1)
add_definitions(-DSQLITE_ENABLE_RBU)
add_definitions(-DSQLITE_ENABLE_STAT4)
