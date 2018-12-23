
# CMakeLists.txt

cmake_minimum_required(VERSION 3.10)
project(Dec)

set(CMAKE_CXX_STANDARD 11)

add_executable(Dec main.cpp Timer.h Worker.h Worker.cpp Student.h Teacher.h
        Person.h Cents.h Cents.cpp MyArray.h MyArray.cpp Storage.h Storage8.h)