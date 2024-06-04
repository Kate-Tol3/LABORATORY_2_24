#include "Test.h"
#include "TestDynamicArray.h"
#include "TestLinkedList.h"
#include "TestMutableSequence.h"
#include "TestImmutableSequence.h"
#include "MutableArraySequence.h"
#include "MutableListSequence.h"
#include "ImmutableArraySequence.h"
#include "ImmutableListSequence.h"


void Test::testDynamicArray() {
    DynamicArrayTest tda;
    tda.test();
}

void Test::testLinkedList() {
    LinkedListTest tll;
    tll.test();
}

void Test::testMutableArraySequence() {
    MutableSequenceTest<MutableArraySequence> tmas;
    tmas.test();
}

void Test::testMutableListSequence() {
    MutableSequenceTest<MutableListSequence> tmls;
    tmls.test();
}

void Test::testImmutableArraySequence() {
    ImmutableSequenceTest<ImmutableArraySequence> tias;
    tias.test();
}

void Test::testImmutableListSequence() {
    ImmutableSequenceTest<ImmutableListSequence> tils;
    tils.test();
}

void Test::TestAll() {

    testDynamicArray();
    testLinkedList();
    testMutableArraySequence();
    testMutableListSequence();
    testImmutableArraySequence();
    testImmutableListSequence();

}