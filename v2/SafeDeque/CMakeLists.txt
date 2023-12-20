cmake_minimum_required(VERSION 3.26)
project(SafeDeque)

set(CMAKE_CXX_STANDARD 17)

add_executable(SafeDeque main.cpp SafeDequeue.h SafeDequeue.inl)
