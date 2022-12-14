cmake_minimum_required(VERSION 3.25)
project(untitled)

set(CMAKE_CXX_STANDARD 23)

add_executable(untitled main.cpp src/Deck.cpp headers/Deck.h headers/Structs.h)
