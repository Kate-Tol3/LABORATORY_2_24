
#ifndef SEQUENCE_H
#define SEQUENCE_H


template <class T>
class Sequence {
public:
    //destructor
    virtual ~Sequence() = default;

    //methods
    virtual T& getFirst() const = 0;
    virtual T& getLast() const = 0;

    virtual T& get(int index) const = 0;
    virtual int getLength() const = 0;

    virtual Sequence<T>* concat(const Sequence <T>&) = 0;
    virtual Sequence<T>* getSubSequence(int startIndex, int endIndex) = 0;
    virtual void print() const = 0;
    virtual T& operator[](int index) const = 0;

};

#endif //SEQUENCE_H
