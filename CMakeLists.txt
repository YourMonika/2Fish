cmake_minimum_required(VERSION 3.15)
project(2Fish C)

set(CMAKE_C_STANDARD 11)

add_executable(2Fish main.c twofish.c twofish.h)