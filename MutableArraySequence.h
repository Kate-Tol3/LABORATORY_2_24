
#ifndef MUTABLEARRAYSEQUENCE_H
#define MUTABLEARRAYSEQUENCE_H


#include "DynamicArray.h"
#include "LinkedList.h"
#include "Sequence.h"
#include "Exceptions.h"

//IMMUTABLE
template <class T>
class MutableArraySequence:public virtual Sequence<T>{
private:
    DynamicArray<T> *seq_array;
public:
    //constructors
    MutableArraySequence(): seq_array(new DynamicArray<T>()){};
    MutableArraySequence(T* items, int count): seq_array(new DynamicArray<T>(items, count)){};
    explicit MutableArraySequence(const DynamicArray<T> &other): seq_array(new DynamicArray<T>(other)){};

    //destructor
    virtual ~MutableArraySequence() {
        delete seq_array;
    }

    //methods

    T getFirst() const override {
        return seq_array->get(0);
    }

    T getLast() const override {
        return seq_array->get(seq_array->getSize() - 1);
    }

    T get(int index) const override {
        return seq_array->get(index);
    }

    int getLength() const override{
        return seq_array->getSize();
    }

    void print() const {
        seq_array->print();
    }

    MutableArraySequence<T> *getSubSequence(int startIndex, int endIndex) override{
        if (startIndex < 0 || endIndex < 0 || startIndex > endIndex|| seq_array->getSize() <= startIndex || seq_array->getSize() <= endIndex) throw IndexOutOfRange();

        int len = endIndex - startIndex + 1;
        T *items = new T[len];
        for (int i = startIndex; i < endIndex + 1; i++) {
            items [i - startIndex] = seq_array->get(i);
        }
        seq_array->resize(len);
        for (int i = 0; i < len ; i++){
            seq_array->set(i, items[i]);
        }
        return this;
    }

    MutableArraySequence<T> *append(T item) override{
        seq_array->resize(seq_array->getSize()+1);
        seq_array->set(seq_array->getSize() - 1, item);
        return this;
    }

    MutableArraySequence<T> *prepend(T item) override {
        seq_array->resize(seq_array->getSize()+1);
        for (int i = seq_array->getSize() - 1; i > 0; i--){
            seq_array->set(i, seq_array->get(i - 1));
        }
        seq_array->set(0, item);
        return this;
    }

    MutableArraySequence<T> *insertAt(const T item,const int index) override {
        if(index < 0 || index >= seq_array->getSize()) throw IndexOutOfRange();

        seq_array->resize(seq_array->getSize() + 1);
        for (int i = seq_array->getSize() - 1; i > index; i--){
            seq_array->set(i, seq_array->get(i - 1));
        }
        seq_array->set(index, item);
        return this;
    }

    MutableArraySequence<T> *concat(Sequence <T> *other) override{
        auto *new_seq = new MutableArraySequence<T>(*this); // to make mutable change seq_array to this*
        int size1 = this->getLength(), size2 = other->getLength();
        int nsize = size1 + size2;
        new_seq->seq_array->resize(nsize);
        for (int i = size1; i < nsize; i++){
            //new_seq_array[i] = other[i];
            new_seq->seq_array->set(i, other->get(i - size1));
        }
        return new_seq;

    }



};

#endif //MUTABLEARRAYSEQUENCE_H
