
#ifndef LAB2_MUTABLELISTSEQUENCE_H
#define LAB2_MUTABLELISTSEQUENCE_H

#include "LinkedList.h"
#include "MutableSequence.h"
#include "Exceptions.h"

template <class T>
class MutableListSequence:public virtual MutableSequence<T> {
private:
    LinkedList<T> *seq_list;
public:
    //constructors
    MutableListSequence(): seq_list(new LinkedList<T>()){};
    MutableListSequence(T* items, int count): seq_list(new LinkedList<T>(items, count)){};
    explicit MutableListSequence(const int count):seq_list(new LinkedList<T>(count)){};
    explicit MutableListSequence(const LinkedList<T> &list): seq_list(new LinkedList<T>(list)){};
    MutableListSequence(const MutableListSequence<T>& other): seq_list(new LinkedList<T>(*(other.seq_list))){};
    explicit MutableListSequence(const Sequence<T>& other): seq_list(new LinkedList<T>(other)) {}

    //destructor
    ~MutableListSequence() override{
        delete seq_list;
    }

    //methods
    T& getFirst() const override {
        if (seq_list->getLength() == 0) throw IndexOutOfRange();
        return seq_list->getFirst();
    }

    T& getLast() const override {
        if (seq_list->getLength() == 0) throw IndexOutOfRange();
        return seq_list->getLast();
    }

    T& get(int index) const override {
        if (seq_list->getLength() == 0 || seq_list->getLength() <= index || index < 0) throw IndexOutOfRange();
        return seq_list->get(index);
    }

    int getLength() const override {
        return seq_list->getLength();
    }

    Sequence<T>* getSubSequence(int startIndex, int endIndex) override {
        if (startIndex < 0 || endIndex < 0 || startIndex > endIndex || startIndex >= seq_list->getLength()
        || endIndex >= seq_list->getLength()) throw IndexOutOfRange();

        this->seq_list = seq_list->getSubList(startIndex, endIndex);
        return this;

    }

    void append(const T& item) override {
        this->seq_list->append(item);
    }

    void prepend(const T& item) override {
        this->seq_list->prepend(item);

    }

    void insertAt(const T& item, int index) override {
        this->seq_list->insertAt(item,index);

    }

    void set(int index,const T& item) override{
        this->seq_list->set(index, item);
    }

    Sequence<T>* concat(const Sequence<T> &list) override {
        auto *new_list = new MutableListSequence<T>(*this);
        int size1 = new_list->getLength(), size2 =  list.getLength();
        int len = size1 + size2;
        for (int i = size1; i < len; i++){
            new_list->seq_list->append(list.get(i - size1));
        }
        return new_list;

    }

    T& operator[](int index) const override{
        return (seq_list->get(index));
    }

    bool operator==(const MutableSequence<T>& other) override{
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

    void print() const override{
        this->seq_list->print();
    }
};

#endif //LAB2_MUTABLELISTSEQUENCE_H
