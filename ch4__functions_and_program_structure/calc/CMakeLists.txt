cmake_minimum_required(VERSION 3.20)
project(calc C)

set(CMAKE_C_STANDARD 11)

add_executable(calc main.c calc.h getch.c getop.c stack.c)
add_executable(getint getint.c calc.h getch.c)