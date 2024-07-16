cmake_minimum_required(VERSION 3.24)
project(tarea)

set(CMAKE_CXX_STANDARD 17)

add_executable(tarea main.cpp Buscador.cpp CSV.h CSV.cpp Peliculas.h Buscador.h)
