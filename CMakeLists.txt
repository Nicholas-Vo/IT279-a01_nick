cmake_minimum_required(VERSION 3.21)
project(a01_nick)

set(CMAKE_CXX_STANDARD 14)

include_directories(q01)

add_executable(a01_nick
        #q01/a01_q1_app.cpp
#        q01/List.cpp
#        q01/List.h
        q02/List.h
        q02/List.cpp
        q02/a02_q2_app.cpp)
        #q03/a01_q3.cpp
        #q03/a01_q3.h
        #q04/a01_q4.cpp q04/a01_q4.h)
