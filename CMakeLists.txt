cmake_minimum_required(VERSION 3.26)
project(DataStructures2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(DataStructures2
        BST.cpp
        BST.h
        Heap.h
        Item.h
        main.cpp
        AVLTree.cpp
        AVLTree.h)
