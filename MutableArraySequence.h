
#ifndef MUTABLEARRAYSEQUENCE_H
#define MUTABLEARRAYSEQUENCE_H


#include "DynamicArray.h"
#include "LinkedList.h"
#include "MutableSequence.h"
#include "Exceptions.h"

//IMMUTABLE
template <class T>
class MutableArraySequence:public virtual MutableSequence<T>{
private:
    DynamicArray<T> *seq_array;
public:
    //constructors
    MutableArraySequence(): seq_array(new DynamicArray<T>()){};
    MutableArraySequence(T* items, int count): seq_array(new DynamicArray<T>(items, count)){};

    explicit MutableArraySequence(const int count):seq_array(new DynamicArray<T>(count)){};
    explicit MutableArraySequence(const DynamicArray<T> &other): seq_array(new DynamicArray<T>(other)){};
    MutableArraySequence(const MutableArraySequence<T>& other): seq_array(new DynamicArray<T>(*(other.seq_array))){};
    explicit MutableArraySequence(const Sequence<T>& other): seq_array(new DynamicArray<T>(other)) {};

    //destructor
    ~MutableArraySequence() override{
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

    void print() const override{
        seq_array->print();
    }
    void set(int index,const T& item) override{
        this->seq_array->set(index, item);
    }

    Sequence<T>* getSubSequence(int startIndex, int endIndex) override{
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

    void append(const T& item) override{
        seq_array->resize(seq_array->getSize()+1);
        seq_array->set(seq_array->getSize() - 1, item);

    }

    void prepend(const T& item) override {
        seq_array->resize(seq_array->getSize()+1);
        for (int i = seq_array->getSize() - 1; i > 0; i--){
            seq_array->set(i, seq_array->get(i - 1));
        }
        seq_array->set(0, item);

    }

    void insertAt(const T& item,int index) override {
        if(index < 0 || index >= seq_array->getSize() && getLength() != 0) throw IndexOutOfRange();

        seq_array->resize(seq_array->getSize() + 1);
        for (int i = seq_array->getSize() - 1; i > index; i--){
            seq_array->set(i, seq_array->get(i - 1));
        }
        seq_array->set(index, item);

    }

    Sequence<T>* concat(const Sequence<T> &other) override{
        auto *new_seq = new MutableArraySequence<T>(*this); // to make mutable change seq_array to this*
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

    bool operator==(const MutableSequence<T>& other) override {
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

#endif //MUTABLEARRAYSEQUENCE_H
