cmake_minimum_required(VERSION 4.3)
project(second C)

set(CMAKE_C_STANDARD 11)

add_executable(second main.c
        MyIo.c
        MyIo.h)
