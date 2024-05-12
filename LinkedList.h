
#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include <iostream>
#include "Exceptions.h"

//inisialise null
//const link in constuctor ?
//
template <typename T>
class Node{
public:
        T value;
        Node<T> *prev;
        Node<T> *next;
public:
    explicit Node(const T &n_val = 0, Node<T> *n_prev = nullptr, Node<T> *n_next = nullptr):
        value(n_val), prev(n_prev), next(n_next){};
};

template <class T>
class LinkedList{
private:
    int length;
    Node<T>* head;
    Node<T>* tail;
public:
    Node<T>* get_Node (const int index) const{
        if (index<0 || index >=  length || head == nullptr) throw IndexOutOfRange();
        Node<T>* temp = head;
        for (int pos = 0; pos < index; ++pos, temp = temp->next);
        return temp;
    }

    bool checkIndex(const int index,const int len) const {
        if (index >= len || index < 0) throw IndexOutOfRange();
        return true;
    };

    bool listIsEmpty(const LinkedList &list) const{
        if (list.head == nullptr) throw EmptyListException();
        return true;
    }

public:
    //constructors
    LinkedList():  length(0), head(nullptr), tail(nullptr) {};

    LinkedList(T* items, const int count): length(0), head(nullptr), tail(nullptr){
        if (count > 0) {
            head = nullptr;
            tail = nullptr;
            for (int i = 0; i < count; ++i) {
                append(items[i]);
            }
            length = count;
        }
    }

    LinkedList(const LinkedList<T> &other): length(other.length), head(nullptr), tail(nullptr) {
        Node<T> *temp = other.head;
        while (temp != nullptr) {
            append(temp->value);
            temp = temp->next;
        }
    }

    //destructor
    ~LinkedList() {
        Node<T> *curr = head;
        while (curr) {
            Node<T> *temp = curr->next;
            delete curr;
            curr = temp;
        }
    }

    //methods
    T get(const int index) const{
        checkIndex(index, length);
        listIsEmpty(*this);
        //if (index<0 || index >=  length || head == nullptr) throw IndexOutOfRange;
        Node<T> *temp = head;
        //turn into for
        for (int pos = 0; pos < index; ++pos, temp = temp->next);
//        int pos = 0;
//        while (pos < index) {
//            temp = temp->next;
//            pos++;
//        }
        return temp->value;
    }


    T getFirst() const{
        listIsEmpty(*this);
        //if (head == nullptr) throw IndexOutOfRange;
        return head->value;
    }

    T getLast() const{
        listIsEmpty(*this);
        //if (head == nullptr) throw IndexOutOfRange;
        return tail->value;
    }

    LinkedList<T>* getSubList(int startIndex, int endIndex) const {
        listIsEmpty(*this);
        checkIndex(startIndex, length);
        checkIndex(endIndex, length);
        if (startIndex > endIndex) throw IndexOutOfRange();
        //if (startIndex > length || endIndex > length || head == nullptr || endIndex < 0 || startIndex < 0) throw IndexOutOfRange;

        auto *sublist = new LinkedList<T>();
        Node<T> *temp = get_Node(startIndex);
        for (int i = startIndex; i <= endIndex;i++) {
            sublist->append(temp->value);
            temp = temp->next;
        }
        return sublist;
    }

    int getLength() const{
        return length;
    }


    //may add node whatchman to make list loop and delete if
//mutable
    void append(const T item) {
        auto *el = new Node<T>(item, nullptr, nullptr);
        if(head == nullptr) {
            el->prev = nullptr;
            head = el;
            tail = el;
            length++;
            return ;
        }
        tail->next = el;
        el->prev = tail;
        tail = el;
        length++;
    }

    void prepend(const T item) {
        auto *el = new Node<T>(item, nullptr, head);
        if (head != nullptr) {
            head->prev = el;
        }
        head = el;
        length++;
    }

    // delete
    void insertAtAfter(const T item,const int index) { // inserts node on stated index after previous
        checkIndex(index, length);
        listIsEmpty(*this);

        //if (index<0 || index >=  length || head == nullptr) throw IndexOutOfRange;
        Node<T> *temp = head;
        int pos = 0;
        while (pos < index) {
            temp = temp->next;
            pos++;
        }
        auto *el = new Node<T>;
        el->next = temp->next;
        el->value = item;
        temp->next = el;
        el->prev = temp;
        if (el->next != NULL) el->next->prev = el;
        length++;
    }

    void insertAtBefore(const T item,const int index) { // inserts node on stated index before previous
        checkIndex(index, length);
        listIsEmpty(*this);
        //if (index<0 || index >=  length || head == nullptr) throw IndexOutOfRange;
        Node<T>* temp = head;
        int pos = 0;
        while (pos < index) {
            temp = temp->next;
            pos++;
        }
        auto *el = new Node<T>;
        el->prev= temp->prev;
        el->value = item;
        temp->prev = el;
        el->next = temp;
        if (el->prev != NULL) el->prev->next = el;
        else head = el;
        length++;
    }

    LinkedList<T>* concat(LinkedList<T> *list) {
        auto *new_list = new LinkedList<T>(*this);
        Node<T> *el1 = new_list->head;
        Node<T> *el2 = list->head;
        while (el1->next != nullptr) el1 = el1->next;

        while (el1->next!=nullptr) {
            el1->next = new Node<T>(el2->value);
            el1->next->prev = el1;
            el1 = el1->next;
            el2 = el2->next;
            ++new_list->length;
        }
        return new_list;

    }

    void print(){
        Node<T> *temp = head;
        int pos = 0;
        while (temp != nullptr){
            if (temp != head) std::cout<< " ";
            std::cout<< this->get(pos);
            temp = temp->next;
            pos++;
        }
        //std::cout << std::endl;
    }


    T operator [](const int index){
        return this->get(index);
    };

    bool operator == (const LinkedList& other){
        if (this->length != other.length) return false;
        for (int i = 0; i < length; i++){
            if (this[i] != other[i]) return false;
        }
        return true;
    };
};





#endif //LINKEDLIST_H
