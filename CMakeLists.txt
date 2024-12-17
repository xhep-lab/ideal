cmake_minimum_required(VERSION 3.15...3.26)
project(${SKBUILD_PROJECT_NAME} LANGUAGES CXX)

set(PYBIND11_NEWPYTHON ON)
find_package(pybind11 CONFIG REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/include)

pybind11_add_module(ideal "${PROJECT_SOURCE_DIR}/src/ideal.cpp")

install(TARGETS ideal LIBRARY DESTINATION .)

add_executable(minimal "${PROJECT_SOURCE_DIR}/examples/minimal.cpp")