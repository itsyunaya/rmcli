cmake_minimum_required(VERSION 4.0)
project(rmcli)

set(CMAKE_CXX_STANDARD 26)

add_executable(rmcli main.cpp
        registermachine.cpp
        registermachine.h
        modes/InteractiveMode.cpp
        modes/InteractiveMode.h
        modes/InteractiveMode.cpp
        modes/Fileinput.cpp
        modes/Fileinput.h
        util/Util.cpp
        util/Util.h)

# include libs
target_link_libraries(rmcli PRIVATE readline ncurses)