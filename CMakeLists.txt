cmake_minimum_required(VERSION 3.12)
project(Mancala)

set(CMAKE_CXX_STANDARD 14)

include_directories(Mancala/Mancala)

add_executable(Mancala
        Mancala/Mancala/AI.cpp
        Mancala/Mancala/AI.h
        Mancala/Mancala/Board.cpp
        Mancala/Mancala/Board.h
        Mancala/Mancala/Mancala.cpp
        Mancala/Mancala/pch.cpp
        Mancala/Mancala/pch.h Mancala/Mancala/MoveTree.cpp Mancala/Mancala/MoveTree.h)
