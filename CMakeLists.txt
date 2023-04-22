cmake_minimum_required(VERSION 3.25)
project(Projet_C)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Projet_C
        README.md
        Vector.c
        Vector.h funtion.c id.h id.c)
