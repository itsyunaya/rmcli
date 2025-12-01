cmake_minimum_required(VERSION 4.0)
project(rmcli)

set(CMAKE_CXX_STANDARD 26)

add_executable(rmcli main.cpp
        registermachine.cpp
        registermachine.h)
