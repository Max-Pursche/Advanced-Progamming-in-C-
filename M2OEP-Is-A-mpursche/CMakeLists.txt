cmake_minimum_required(VERSION 3.20)
project(M2OEP_Is_A_mpursche)

set(CMAKE_CXX_STANDARD 14)

add_executable(main main.cpp Vehicle.cpp Airplane.cpp)
add_executable(Vehicle_Testing Vehicle-Testing.cpp Vehicle.cpp Airplane.cpp)
