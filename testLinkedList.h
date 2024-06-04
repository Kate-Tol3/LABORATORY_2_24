
#ifndef TESTLINKEDLIST_H
#define TESTLINKEDLIST_H

#include "Exceptions.h"
#include "LinkedList.h"

class LinkedListTest {
public:

    void testConstructors();

    void testGet();

    void testGetSize();

    void testGetFirst();

    void testGetLast();

    void testAppend();

    void testPrepend();

    void testInsertAt();

    void testGetSubList();

    void testConcat();

    // void testOperatorAccess() {
    //     double elems[6] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0};
    //     LinkedList<double> list(elems, 6);
    //     assert(list[2] == list.get(2));
    // }

    void testOperatorEqual();

    void test();
};

#endif //TESTLINKEDLIST_H
