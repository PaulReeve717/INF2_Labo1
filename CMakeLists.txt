cmake_minimum_required(VERSION 3.15)
project(INF2_Labo1)

set(CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wconversion -Wextra -Wsign-conversion -pedantic")

add_executable(INF2_Labo1 Labo1_Bourcoud_Maziero_Reeve.cpp Temps.cpp Temps.h )