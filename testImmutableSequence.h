
#ifndef TESTIMMUTABLESEQUENCE_H
#define TESTIMMUTABLESEQUENCE_H

#include "Exceptions.h"
#include "Sequence.h"
#include "ImmutableSequence.h"

template<template<class> class ImmutableSequence>
class ImmutableSequenceTest {
public:

    void testConstructors() {

        ImmutableSequence<double> immut_seq;
        assert(immut_seq.getLength() == 0);

        ImmutableSequence<double> immut_seq1(8);
        assert(immut_seq1.getLength() == 8);
        try {
            ImmutableSequence<double> immut_seq_(-1);
            ;
        } catch (IndexOutOfRange &ex) {}
        catch (EmptyListException &ex) {}

        double elems[8] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
        ImmutableSequence<double> immut_seq2(elems, 8);
        assert(immut_seq2.getLength() == 8);
        for (int i = 0; i < immut_seq2.getLength(); ++i) {
            assert(immut_seq2.get(i) == elems[i]);
        }
        try {
            ImmutableSequence<double> immut_seq_(elems, -1);
        } catch (IndexOutOfRange &ex) {}
        catch (EmptyListException &ex) {}

        ImmutableSequence<double> immut_seq3(immut_seq2);
        assert(immut_seq3.getLength() == immut_seq2.getLength());
        for (int i = 0; i < immut_seq3.getLength(); ++i) {
            assert(immut_seq3.get(i) == immut_seq2.get(i));
        }

    }

    void testGet() {

        double elems[8] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
        ImmutableSequence<double> immut_seq(elems, 8);
        for (int i = 0; i < 8; ++i) {
            assert(immut_seq.get(i) == elems[i]);
        }
        try {
            immut_seq.get(-1);
            ;
        } catch (IndexOutOfRange &ex) {}
        catch (EmptyListException &ex) {}
        try {
            immut_seq.get(8);
            ;
        } catch (IndexOutOfRange &ex) {}
        catch (EmptyListException &ex) {}
    }

    void testGetFirst() {
        double elems[8] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
        ImmutableSequence<double> immut_seq(elems, 8);
        assert(immut_seq.getFirst() == 0.0);
        try {
            ImmutableSequence<double> immut_seq_;
            immut_seq_.getFirst();
            ;
        } catch (IndexOutOfRange &ex) {}
        catch (EmptyListException &ex) {}
    }

    void testGetLast() {
        int length = 7;
        double elems[8] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
        ImmutableSequence<double> immut_seq(elems, 8);
        assert(immut_seq.getLast() == 7.0);
        try {
            ImmutableSequence<double> immut_seq_;
            immut_seq_.getLast();
            ;
        } catch (IndexOutOfRange &ex) {}
        catch (EmptyListException &ex) {}
    }

    void testGetLength() {
        double elems[8] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
        ImmutableSequence<double> immut_seq(elems, 8);
        assert(immut_seq.getLength() == 8);
    }

    void testAppend() {
        double elems[8] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
        ImmutableSequence<double> immut_seq(elems, 8);
        double val = 100;

        ImmutableSequence<double>* immut_seq2 = immut_seq.append(val);
        assert(immut_seq2->getLength() == 9);

        for (int i = 0; i < 8; ++i) {
            assert(immut_seq2->get(i) == elems[i]);
        }
        assert(immut_seq2->get(8) == val);
        delete immut_seq2;

        ImmutableSequence<double> immut_seq3;
        immut_seq2 = immut_seq3.append(val);
        assert(immut_seq2->getLength() == 1);
        assert(immut_seq2->getFirst() == val);
        assert(immut_seq2->getLast() == val);
    }

    void testPrepend() {
        double elems[8] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
        ImmutableSequence<double> immut_seq1(elems, 8);
        double val = 100;
        Sequence<double>* immut_seq2 = immut_seq1.prepend(val);
        assert(immut_seq2->getLength() == 9);
        assert(immut_seq2->get(0) == val);
        for (int i = 1; i < 9; ++i) {
            assert(immut_seq1.get(i - 1) == elems[i - 1]);
            assert(immut_seq2->get(i) == elems[i - 1]);
        }
        delete immut_seq2;

        ImmutableSequence<double> immut_seq3;
        immut_seq2 = immut_seq3.prepend(val);
        assert(immut_seq2->getLength() == 1);
        assert(immut_seq2->getFirst() == val);
        assert(immut_seq2->getLast() == val);
    }

    void testInsertAt() {
        double elems[8] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
        ImmutableSequence<double> immut_seq1(elems, 8);

        ImmutableSequence<double>* immut_seq2;
        double val = 100;
        int ind1 = 0, ind2 = 4, ind3 = 7;
        immut_seq2 = immut_seq1.insertAt(val, ind1);
        assert(immut_seq2->getLength() == 9);
        assert(immut_seq2->get(ind1) == val);

        immut_seq2 = immut_seq1.insertAt(val, ind2);
        assert(immut_seq2->getLength() == 9);
        assert(immut_seq2->get(ind2) == val);

        immut_seq2 = immut_seq1.insertAt(val, ind3);
        assert(immut_seq2->getLength() == 9);
        assert(immut_seq2->get(ind3) == val);

        delete immut_seq2;
        double ins_val;
        try {
            ins_val = -1;
            immut_seq1.insertAt(ins_val, val);
            ;
        } catch (IndexOutOfRange &ex) {}
        catch (EmptyListException &ex) {}

        try {
            ins_val = 9;
            immut_seq1.insertAt(ins_val, val);
            ;
        } catch (IndexOutOfRange &ex) {}
        catch (EmptyListException &ex) {}


        ImmutableSequence<double> immut_seq3;
        immut_seq2 = immut_seq3.insertAt(val, 0);
        assert(immut_seq2->getLength() == 1);
        assert(immut_seq2->getFirst() == val);
        assert(immut_seq2->getLast() == val);
    }

    void testGetSubsequence() {
        double elems[8] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
        ImmutableSequence<double> immut_seq(elems, 8);
        int startIndex = 3;
        int endIndex = 6;
        ImmutableSequence<double>* result = immut_seq.getSubSequence(startIndex, endIndex);
        for (int i = startIndex; i <= endIndex; ++i) {
            assert(result->get(i - startIndex) == elems[i]);
        }
        try {
            immut_seq.getSubSequence(0, 8);
            ;
        } catch (IndexOutOfRange &ex) {}
        catch (EmptyListException &ex) {}
        try {
            immut_seq.getSubSequence(-1, 0);
            ;
        } catch (IndexOutOfRange &ex) {}
        catch (EmptyListException &ex) {}
        try {
            immut_seq.getSubSequence(1, 0);
            ;
        } catch (IndexOutOfRange &ex) {}
        catch (EmptyListException &ex) {}
    }

    void testConcat() {
        double elems1[7] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
        ImmutableSequence<double> immut_seq1(elems1, 7);
        double elems2[3] = {7.0, 8.0, 9.0};
        double elems3[10] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
        ImmutableSequence<double> immut_seq2(elems2, 3);
        ImmutableSequence<double>* result = immut_seq1.concat(immut_seq2);
        assert(result->getLength() == 10);
        for (int i = 0; i < 10; i++){
            assert(result->get(i) == elems3[i]);
        }
    }

    void testOperatorAccess() {
        double elems[6] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0};
        ImmutableSequence<double> immut_seq(elems, 6);
        assert(immut_seq[2] == immut_seq.get(2));
    }

    void testOperatorEqual() {
        double elems[6] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0};
        ImmutableSequence<double> immut_seq1(elems, 6);
        ImmutableSequence<double> immut_seq2(elems, 6);
        assert(immut_seq1 == immut_seq2);
    }

    void test() {
        testConstructors();
        testGet();
        testGetLength();
        testAppend();
        testPrepend();
        testInsertAt();
        testConcat();
        testGetSubsequence();
        testGetFirst();
        testGetLast();
        testOperatorAccess();
        testOperatorEqual();
    }
};

#endif //TESTIMMUTABLESEQUENCE_H
