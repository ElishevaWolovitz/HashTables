cmake_minimum_required(VERSION 3.20)
project(Q2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Q2 main.cpp
        client.h
        volunteer.h
        HashTbls.cpp
        HashTbls.h
        hashint.h
        HashClient.h
        HashVolunteer.h
        Repository.h
        )
