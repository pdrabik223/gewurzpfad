cmake_minimum_required(VERSION 3.10)
project(gewurzpfad)

set(CMAKE_CXX_STANDARD 17)

include_directories(lib)

set(SOURCES lib/console_tools/console_tools.cpp
)

add_executable(gewurzpfad main.cpp ${SOURCES})
