#pragma once

#include <iostream>
#include <cassert>

#include "testMutableSequence.h"
#include "testImmutableSequence.h"
#include "testDynamicArray.h"
#include "testLinkedList.h"

#include "ImmutableListSequence.h"
#include "ImmutableArraySequence.h"
#include "MutableListSequence.h"
#include "MutableArraySequence.h"

class Test {
public:
    void testDynamicArray();

    void testLinkedList();

    void testMutableArraySequence();

    void testMutableListSequence();

    void testImmutableArraySequence();

    void testImmutableListSequence();

    void TestAll();

};