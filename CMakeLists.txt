cmake_minimum_required(VERSION 3.31)
project(rmcli)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(rmcli
        src/main.cpp
        src/registermachine.cpp
        include/registermachine.h
        src/Util.cpp
        include/Util.h
        src/InputLogic.cpp
        include/InputLogic.h)

# include libs
target_link_libraries(rmcli PRIVATE readline ncurses)

target_compile_options(rmcli PRIVATE
        -O2
        -Wall
        -Wextra
)