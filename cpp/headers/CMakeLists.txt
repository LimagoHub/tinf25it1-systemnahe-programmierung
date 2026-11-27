cmake_minimum_required(VERSION 4.4)
project(headers C)

set(CMAKE_C_STANDARD 11)

add_executable(headers main.c
        myio.h
        myio.c)
