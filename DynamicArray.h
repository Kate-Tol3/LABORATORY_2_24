
#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H


#include <iostream>
#include "Exceptions.h"

template<class T> void copyArray(T*, T*, int);
//make zero template parameter so we can use it if string[i] appears
//make override operatirs and return FAlse


template <class T>// ??
class DynamicArray {
private:
    T *array;
    int arr_size;
    int el_size;

public:

    //constructors
    DynamicArray(T* items, const int count): arr_size(0), el_size(0),  array(nullptr) {
        if (count > 0) {
            arr_size = count;
            array = new T[count];
            for(int i = 0 ; i < arr_size; ++i) {
                array[i] = items[i];
            }
        }
    };

    explicit DynamicArray(const int new_size) : arr_size(0), el_size(0), array(nullptr) {
        if (new_size > 0) {
            arr_size= new_size;
        }
    };

    DynamicArray(const DynamicArray<T> &other): arr_size(other.arr_size), el_size(other.el_size), array(nullptr){
       if (other.arr_size > 0 && other.array!=nullptr) {
           array = new T[other.arr_size];
           for (int i = 0; i < other.arr_size; ++i) {
               array[i] = other.array[i];
           }
       }
    };

    DynamicArray(): array(nullptr), arr_size(0), el_size(0){};

    //destructor
    ~DynamicArray() {
        delete[] array;
    }


    //methods

    T get(const int index) {
        if (abs(index) >= arr_size) {
            throw IndexOutOfRange();
        }
        return (index < 0) ? array[arr_size + index]: array[index];
    }

    int getSize() const {
        return arr_size;
    }

    void set(const int index, const T value) {
        if (abs(index) >= arr_size ) throw IndexOutOfRange();
         array[index] = value;
    }

    void resize(const int new_size) {
        if (new_size < 0) throw IndexOutOfRange();
        if (new_size==arr_size) return;
        if (new_size == 0) {
            if (array != nullptr) delete[] array;
            arr_size = 0;
            el_size = 0;
            array = nullptr;
        }

        // using more memory than we need to make resize more efficient
        if (new_size > el_size) {
            if (el_size == 0) el_size = 1;
            while (el_size <= new_size + 1) el_size *= 2;
            T *new_array = new T[el_size];
            if (array != nullptr) {
                copyArray<T>(new_array, array, arr_size);
                delete[] array;
            }
            array = new_array;
        }
        else if (new_size < el_size / 3) {
            while (el_size / 3 > new_size + 1) el_size /= 2;
            T *new_array = new T[el_size];
            if (array != nullptr) {
                copyArray<T>(new_array, array, new_size);
                delete[] array;
            }
            array = new_array;
        }
        arr_size = new_size;
    }

    void print(){
        for (int i = 0; i < arr_size;i++){
            if (i != arr_size - 1) std::cout << this->get(i) << " ";
            else std::cout << this->get(i);
        }
    }
};

template <typename T>
void copyArray(T *new_arr, T* old_arr,const int new_size) {
    for(int i = 0; i < new_size; ++i) {
        new_arr[i] = old_arr[i];
    }
};

#endif //DYNAMICARRAY_H
