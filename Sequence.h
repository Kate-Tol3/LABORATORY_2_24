
#ifndef SEQUENCE_H
#define SEQUENCE_H


template <class T>
class Sequence {
public:
    //destructor
    virtual ~Sequence() = default;

    //methods
    //all IM!!! mutable sequece methods are const
    virtual T getFirst() const = 0;
    virtual T getLast() const = 0;
    //make get const method
    virtual T get(int index) const = 0;
    virtual int getLength() const = 0;
    //add set return type

    virtual Sequence<T> *getSubSequence(int startIndex, int endIndex) = 0  ;
    virtual Sequence<T> *append(T item) = 0;
    virtual Sequence<T> *prepend(T item) = 0;
    virtual Sequence<T> *insertAt(T item, int index) = 0;
    virtual Sequence<T> *concat(Sequence <T> *list) = 0;
protected:

};



#endif //SEQUENCE_H
