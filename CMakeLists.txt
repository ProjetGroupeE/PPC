cmake_minimum_required(VERSION 3.7)
project(Cripto)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Ace/Ace.cpp Ace/Ace.h Ace/convert.cpp Ace/convert.h)
add_executable(Cripto ${SOURCE_FILES} Ace/Ace.cpp Ace/Ace.h Ace/convert.cpp Ace/convert.h)