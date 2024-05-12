
#ifndef LAB2_MUTABLELISTSEQUENCE_H
#define LAB2_MUTABLELISTSEQUENCE_H

#include "LinkedList.h"
#include "Sequence.h"
#include "Exceptions.h"

template <class T>
class MutableListSequence:public virtual Sequence<T> {
private:
    LinkedList<T> *seq_list;
public:
    //constructors
    MutableListSequence(): seq_list(new LinkedList<T>()){};
    MutableListSequence(T* items, int count): seq_list(new LinkedList<T>(items, count)){};
    explicit MutableListSequence(const LinkedList<T> &list): seq_list(new LinkedList<T>(list)){};


    //destructor
    virtual ~MutableListSequence() {
        delete seq_list;
    }

    //methods

    T getFirst() const override {
        if (seq_list->getLength() == 0) throw IndexOutOfRange();
        return seq_list->getFirst();
    }

    T getLast() const override {
        if (seq_list->getLength() == 0) throw IndexOutOfRange();
        return seq_list->getLast();
    }

    T get(int index) const override {
        if (seq_list->getLength() == 0 || seq_list->getLength() <= index || index < 0) throw IndexOutOfRange();
        return seq_list->get(index);
    }

    int getLength() const override {
        return seq_list->getLength();
    }

    MutableListSequence<T> *getSubSequence(int startIndex, int endIndex) override {
        if (startIndex < 0 || endIndex < 0 || startIndex > endIndex || startIndex >= seq_list->getLength()
        || endIndex >= seq_list->getLength()) throw IndexOutOfRange();

        this->seq_list = seq_list->getSubList(startIndex, endIndex);
        return this;
    }

    MutableListSequence<T> *append(T item) override {
        auto *new_list = new MutableListSequence<T>(*this);
        new_list->seq_list->append(item);
        return new_list;
    }

    MutableListSequence<T> *prepend(T item) override {
        auto *new_list = new MutableListSequence<T>(*this);
        new_list->seq_list->prepend(item);
        return new_list;
    }

    MutableListSequence<T> * insertAt(T item, int index) override {
        auto *new_list = new MutableListSequence<T>(*this);
        new_list->seq_list->insertAtBefore(item,index);
        return new_list;
    }

    MutableListSequence<T> *concat(Sequence<T> *list) override {
        auto *new_list = new MutableListSequence<T>(*this);
        int size1 = new_list->getLength(), size2 =  list->getLength();
        int len = size1 + size2;
        for (int i = size1; i < len; i++){
            new_list->seq_list->append(list->get(i - size1));
        }
        return  new_list;
    }


    void print(){
        this->seq_list->print();
    }
};

#endif //LAB2_MUTABLELISTSEQUENCE_H
