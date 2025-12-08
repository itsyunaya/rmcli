cmake_minimum_required(VERSION 3.31)
project(rmcli)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(rmcli main.cpp
        registermachine.cpp
        registermachine.h
        modes/InteractiveMode.h
        modes/InteractiveMode.cpp
        modes/Fileinput.cpp
        modes/Fileinput.h
        util/Util.cpp
        util/Util.h)

# include libs
target_link_libraries(rmcli PRIVATE readline ncurses)

target_compile_options(rmcli PRIVATE
        -O2
        -Wall
        -Wextra
)