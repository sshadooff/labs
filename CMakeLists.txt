cmake_minimum_required(VERSION 3.23)
project(Vector C)

set(CMAKE_C_STANDARD 17)

add_executable(Vector main.c libs/data_structures/vector/vector.c libs/data_structures/vector/vector.h
        libs/data_structures/vector/vectorVoid.c libs/data_structures/vector/vectorVoid.h)
