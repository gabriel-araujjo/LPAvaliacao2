cmake_minimum_required(VERSION 3.3)
project(LPAvaliacao2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp delimitadores.cpp delimitadores.h lista.cpp lista.h fila_circular.cpp fila_circular.h dicionario.cpp dicionario.h)
add_executable(LPAvaliacao2 ${SOURCE_FILES} delimitadores.cpp delimitadores.h)