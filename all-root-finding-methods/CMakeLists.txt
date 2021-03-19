cmake_minimum_required(VERSION 3.17)
project(Parcial_1_wil)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Parcial_1_wil
        biseccion.h
        main.cpp
        muller.h
        newtonraphson.h
        reglafalsa.h
        secante.h colormod.h)
