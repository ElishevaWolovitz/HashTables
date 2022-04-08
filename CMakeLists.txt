cmake_minimum_required(VERSION 3.20)
project(Q2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Q2 main.cpp
        volunteer.h
        client.h
        Repository.h
        HashVolunteer.h
        HashClient.h
        HashTbls.h
        hashint.h
        )
