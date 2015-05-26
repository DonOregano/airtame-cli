cmake_minimum_required(VERSION 2.8)

project("airtame-cli")

option(BUILD_DEBUG "Build for debug" OFF)

# set global cmake  variables
set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(DEPS_DIR ${ROOT_DIR}/deps)
set(DEPS_OUT_DIR ${DEPS_DIR}/out)
if (${BUILD_DEBUG})
    set(CMAKE_BUILD_TYPE Debug)
    add_definitions(-DA_DEBUG)
    set(CMAKE_C_FLAGS_DEBUG "-O0 -ggdb -std=gnu99")
else()
    set(CMAKE_BUILD_TYPE Release)
    set(CMAKE_C_FLAGS_RELEASE "-O3 -std=gnu99")
endif()

link_directories(${DEPS_OUT_DIR}/lib)
include_directories(${DEPS_OUT_DIR}/include)

add_subdirectory(${DEPS_DIR})
add_subdirectory(src)
