cmake_minimum_required(VERSION 3.28)
project(LAB2)

set(CMAKE_CXX_STANDARD 17)

add_executable(LAB2 main.cpp
        DynamicArray.h
        LinkedList.h
        Sequence.h
        ImmutableArraySequence.h
        ImmutableListSequence.h
        MutableArraySequence.h
        MutableListSequence.h
        Exceptions.h
        Test.h
        MutableSequence.h
        ImmutableSequence.h
        Interface.h
        testDynamicArray.h
        testLinkedList.h
        testImmutableSequence.h
        "testMutableSequence.h"
 "testDynamicArray.cpp" "Test.cpp" "testLinkedList.cpp"  "UI.h" "UI.cpp")
