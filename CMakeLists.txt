cmake_minimum_required(VERSION 3.5)
project(structures)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp DVector.h LinkedListElement.h LinkedList.h HashTableObject.cpp HashTableObject.h)
add_executable(structures ${SOURCE_FILES})