#ifndef TESTDYNAMICARRAY_H
#define TESTDYNAMICARRAY_H

#include "Exceptions.h"
#include "DynamicArray.h"
#include <cassert>

class DynamicArrayTest {
public:

    void testConstructors();
    void testGet();
    void testSet();
    void testGetSize();
    void testResize();
    void testOperatorAccess();
    void testOperatorEqual();
    void test();    
};

#endif //TESTDYNAMICARRAY_H