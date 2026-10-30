cmake_minimum_required(VERSION 4.3)
project(firtst C)

set(CMAKE_C_STANDARD 11)

add_executable(firtst main.c
        str.h
        str.c)
