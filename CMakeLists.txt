cmake_minimum_required(VERSION 2.8)

project("airtame-cli")

option(BUILD_DEBUG "Build for debug" OFF)

# set global cmake  variables
set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
if (${BUILD_DEBUG})
    set(CMAKE_BUILD_TYPE Debug)
    add_definitions(-DA_DEBUG)
    set(CMAKE_C_FLAGS_DEBUG "-O0 -ggdb -std=gnu99")
else()
    set(CMAKE_BUILD_TYPE Release)
    set(CMAKE_C_FLAGS_RELEASE "-O3 -std=gnu99")
endif()


FIND_PATH(JSONRPCC_INCLUDE_DIRECTORY
  NAMES
    jsonrpc-c.h
  PATHS
    /usr/include/jsonrpc-c
    /usr/local/include/jsonrpc-c
    /usr/include
    /usr/local/include)

FIND_LIBRARY(JSONRPCC_LIBRARY
  NAMES
    jsonrpcc
  PATHS
    /usr/lib64
    /usr/lib
    /usr/local/lib64
    /usr/local/lib)

if (JSONRPCC_LIBRARY AND JSONRPCC_INCLUDE_DIRECTORY)
  MESSAGE(STATUS "Jsonrpc-c seems to be installed on this computer, will use the installed version.")

  include_directories(${JSONRPCC_INCLUDE_DIRECTORY})

  SET(USE_INTERNAL_JSONRPCC False)
else()
  MESSAGE(STATUS "Jsonrpc-c is not installed on this computer, will use git submodule.")

  set(DEPS_DIR ${ROOT_DIR}/deps)
  set(DEPS_OUT_DIR ${DEPS_DIR}/out)

  link_directories(${DEPS_OUT_DIR}/lib)
  include_directories(${DEPS_OUT_DIR}/include)
  set(JSONRPCC_LIBRARY jsonrpcc)
  add_subdirectory(${DEPS_DIR})
  SET(USE_INTERNAL_JSONRPCC True)
endif()

add_subdirectory(src)
