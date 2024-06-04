
#ifndef ARRAYSEQUENCE_H
#define ARRAYSEQUENCE_H

#include "DynamicArray.h"
#include "ImmutableSequence.h"
#include "Exceptions.h"


template <class T>
class ImmutableArraySequence: public virtual ImmutableSequence<T>{
private:
    DynamicArray<T> *seq_array;
public:

    //constructors
    ImmutableArraySequence(): seq_array(new DynamicArray<T>()){};
    explicit ImmutableArraySequence(const int count):seq_array(new DynamicArray<T>(count)){};
    ImmutableArraySequence(T* items, int count): seq_array(new DynamicArray<T>(items, count)){};
    explicit ImmutableArraySequence(const DynamicArray<T> &other): seq_array(new DynamicArray<T>(other)){};
    ImmutableArraySequence(const ImmutableArraySequence<T>& other): seq_array(new DynamicArray<T>(*(other.seq_array))){};
    explicit ImmutableArraySequence(const Sequence<T>& other): seq_array(new DynamicArray<T>(other)) {}

    //destructor
    virtual ~ImmutableArraySequence() {
        delete seq_array;
    }

    //methods

    T& getFirst() const override {
        return seq_array->get(0);
    }

    T& getLast() const override {
        return seq_array->get(seq_array->getSize() - 1);
    }

    T& get(int index) const override {
        return seq_array->get(index);
    }

    int getLength() const override{
        return seq_array->getSize();
    }

    void print() const {
        seq_array->print();
    }

    ImmutableArraySequence<T> *set(int index,const T& item) override{
        auto *new_array = new ImmutableArraySequence<T>(*seq_array);
        new_array->seq_array->set(item,index);
        return new_array;
    }

    ImmutableArraySequence<T> *getSubSequence(int startIndex, int endIndex) override{
        if (startIndex < 0 || endIndex < 0 || startIndex > endIndex|| seq_array->getSize() <= startIndex || seq_array->getSize() <= endIndex) throw IndexOutOfRange();
        int len = endIndex - startIndex + 1;
        T *items = new T[len];
        for (int i = startIndex; i < endIndex + 1; i++) {
            items [i - startIndex] = seq_array->get(i);
        }
        return new ImmutableArraySequence<T>(items, len);
    }

    ImmutableArraySequence<T> *append(const T& item) override{
        int len = seq_array->getSize() + 1;
        T* new_array = new T[len];
        for (int i = 0; i < (len - 1); ++i) {
            new_array[i] = seq_array->get(i);

        }
        new_array[len - 1] = item;
        return new ImmutableArraySequence<T>(new_array, len);
    }

    ImmutableArraySequence<T> *prepend(const T& item) override {
        int len = seq_array->getSize() + 1;
        T* new_array = new T[len];
        new_array[0] = item;
        for (int i = 1; i < (len); ++i) {
            new_array[i]  = seq_array->get(i - 1);
        }
        return new ImmutableArraySequence<T>(new_array, len);
    }

    ImmutableArraySequence<T> *insertAt(const T& item, int index) override {
        if(index < 0 || index >= seq_array->getSize() && getLength() != 0) throw IndexOutOfRange();

        int len = seq_array->getSize() + 1;
        auto *new_seq_array = new DynamicArray<T>(*seq_array);
        new_seq_array->resize(len);
        for (int i = len - 1; i > index; i--){
            new_seq_array->set(i, new_seq_array->get(i - 1));
        }
        new_seq_array->set(index, item);
        return (new ImmutableArraySequence(*new_seq_array));
    }

    ImmutableArraySequence<T> *concat(const Sequence <T> &other) override{
        auto *new_seq = new ImmutableArraySequence<T>(*seq_array); // to make mutable change seq_array to this*
        int size1 = this->getLength(), size2 = other.getLength();
        int nsize = size1 + size2;
        new_seq->seq_array->resize(nsize);
        for (int i = size1; i < nsize; i++){
            new_seq->seq_array->set(i, other.get(i - size1));
        }
        return new_seq;

    }

    T& operator[](int index) const override{
        return (seq_array->get(index));
    }

    bool operator==(const ImmutableSequence<T>& other)override{
        if (this == &other) return true;
        if (this->getLength() == other.getLength()){
            for (int i = 0; i < this->getLength(); ++i) {
                if ((*this)[i] != (other)[i]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }

};

#endif //ARRAYSEQUENCE_H
