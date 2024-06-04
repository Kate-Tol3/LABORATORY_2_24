#pragma once

#include "Sequence.h"
#include "MutableListSequence.h"
#include "MutableArraySequence.h"
#include "MutableSequence.h"

class UserSequence {

private:
    MutableSequence<int>* user_sequence_int = nullptr;
    MutableSequence<double>* user_sequence_double = nullptr;
    MutableSequence<std::string>* user_sequence_string = nullptr;
public:
    //destructor
    ~UserSequence() {
        delete user_sequence_int;
        delete user_sequence_double;
        delete user_sequence_string;
    }
    //constructor
    UserSequence(int seq_type, int el_type, const int length) {
        if (seq_type == 1 && el_type == 1) {
            user_sequence_int = new MutableArraySequence<int>(length);
        } else if (seq_type == 2 && el_type == 1) {
            user_sequence_int = new MutableListSequence<int>(length);
        } else if (seq_type == 1 && el_type == 2) {
            user_sequence_double = new MutableArraySequence<double>(length);
        } else if (seq_type == 2 && el_type == 2) {
            user_sequence_double = new MutableListSequence<double>(length);
        } else if (seq_type == 1 && el_type == 3) {
            user_sequence_string = new MutableArraySequence<std::string>(length);
        } else if (seq_type == 2 && el_type == 3) {
            user_sequence_string = new MutableListSequence<std::string>(length);
        }
    }

    void printFirst() {
        std::cout << "first element is:";
        if (user_sequence_int != nullptr) {
            std::cout << user_sequence_int->getFirst();
        }
        else if (user_sequence_double != nullptr) {
            std::cout << user_sequence_double->getFirst();
        }
        else if (user_sequence_string != nullptr) {
            std::cout << user_sequence_string->getFirst();
        }
        std::cout << "\n\n";
    }

    void printLast() {
        std::cout << "last element is:";
        if (user_sequence_int != nullptr) {
            std::cout << user_sequence_int->getLast();
        }
        else if (user_sequence_double != nullptr) {
            std::cout << user_sequence_double->getLast();
        }
        else if (user_sequence_string != nullptr) {
            std::cout << user_sequence_string->getLast();
        }
        std::cout << "\n\n";
    }

    void printSequence() {
        std::cout << "Your Sequence:\n";
        if (user_sequence_int != nullptr) {
            user_sequence_int->print();
        }
        else if (user_sequence_double != nullptr) {
            user_sequence_double->print();
        }
        else if (user_sequence_string != nullptr) {
            user_sequence_string->print();
        }
        std::cout << "\n\n";
    }

    void printValue() {
        int index;
        std::string s_index;
        std::cout << "Enter index of element:";
        std::cin >> s_index;
        try {
            index = std::stoi(s_index);
        }
        catch (std::invalid_argument& ex) {
            std::cout << "Invalid type. Must be number. Try again.";
        }
        try {
            if (user_sequence_int != nullptr) {
                std::cout << user_sequence_int->get(index) << std::endl << std::endl;
            }
            else if (user_sequence_double != nullptr) {
                std::cout << user_sequence_double->get(index) << std::endl << std::endl;
            }
            else if (user_sequence_string != nullptr) {
                std::cout << user_sequence_string->get(index) << std::endl << std::endl;
            }
        }
        catch (IndexOutOfRange& ex) {
            std::cout << "Invalid index. Try Again.\n\n";
            printValue();
        }
        catch (EmptyListException& ex) {
            std::cout << "sequence is empty\n\n";
        }
    }

    void getLength() {
        std::cout << "Length of sequence is ";
        if (user_sequence_int != nullptr) {
            std::cout << user_sequence_int->getLength();
        }
        else if (user_sequence_double != nullptr) {
            std::cout << user_sequence_double->getLength();
        }
        else if (user_sequence_string != nullptr) {
            std::cout << user_sequence_string->getLength();
        }
        std::cout << "\n\n";
    }

    void insertValue() {
        int index;
        std::string s_index;
        std::cout << "Enter index where insert:";
        std::cin >> s_index;
        try {
            index = std::stoi(s_index);
        }
        catch (std::invalid_argument& ex) {
            std::cout << "Invalid type. Must be number. Try again.";
        }

        std::cout << "Enter the value:";
        try {
            if (user_sequence_int != nullptr) {
                int item;
                std::cin >> item;
                user_sequence_int->insertAt(item, index);
            }
            else if (user_sequence_double != nullptr) {
                double item;
                std::cin >> item;
                user_sequence_double->insertAt(item, index);
            }
            else if (user_sequence_string != nullptr) {
                std::string item;
                std::cin >> item;
                user_sequence_string->insertAt(item, index);
            }
        }
        catch (IndexOutOfRange& ex) {
            std::cout << "Invalid index. Try Again.\n\n";
            insertValue();
        }
        catch (EmptyListException& ex) {
            std::cout << "sequence is empty\n\n";
        }

        std::cout << "\n\n";
    }

    void appendValue() {
        std::cout << "Enter the value of element:";

        if (user_sequence_int != nullptr) {
            int item;
            std::cin >> item;
            user_sequence_int->append(item);
        }
        else if (user_sequence_double != nullptr) {
            double item;
            std::cin >> item;
            user_sequence_double->append(item);
        }
        else if (user_sequence_string != nullptr) {
            std::string item;
            std::cin >> item;
            user_sequence_string->append(item);
        }
        std::cout << "\nThe value was successfully added\n\n";
    }

    void prependValue() {
        std::cout << "Enter the value of element:";
        if (user_sequence_int != nullptr) {
            int item;
            std::cin >> item;
            user_sequence_int->prepend(item);
        }
        else if (user_sequence_double != nullptr) {
            double item;
            std::cin >> item;
            user_sequence_double->prepend(item);
        }
        else if (user_sequence_string != nullptr) {
            std::string item;
            std::cin >> item;
            user_sequence_string->prepend(item);
        }
        std::cout << "\nThe value was successfully added\n\n";
    }

    void printSubsequence() {
        int start;
        int end;
        std::string s_index;

        std::cout << "Enter start index of your subsequence:";
        std::cin >> s_index;
        try {
            start = std::stoi(s_index);
        }
        catch (std::invalid_argument& ex) {
            std::cout << "Invalid type. Must be number. Try again.";
        }

        std::cout << "Enter end index of your subsequence:";
        std::cin >> s_index;
        try {
            end = std::stoi(s_index);
        }
        catch (std::invalid_argument& ex) {
            std::cout << "Invalid type. Must be number. Try again.";
        }


        try {
            if (user_sequence_int != nullptr) {
                Sequence<int>* subsequence_int = user_sequence_int->getSubSequence(start, end);
                subsequence_int->print();
                delete subsequence_int;

            }
            else if (user_sequence_double != nullptr) {
                Sequence<double>* subsequence_double = user_sequence_double->getSubSequence(start, end);
                subsequence_double->print();
                delete subsequence_double;

            }
            else if (user_sequence_string != nullptr) {
                Sequence<std::string>* subsequence_string = user_sequence_string->getSubSequence(start, end);
                subsequence_string->print();
                delete subsequence_string;
            }
        }
        catch (IndexOutOfRange& ex) {
            std::cout << "Invalid index. Try Again.\n\n";
            printSubsequence();
        }
        catch (EmptyListException& ex) {
            std::cout << "sequence is empty\n\n";
        }
        std::cout << "\n\n";
    }

    int getValueInt() {
        int item = 0;
        bool flag = false;
        std::string s_item;
        while (!flag) {
            std::cin >> s_item;
            try {
                item = std::stoi(s_item);
                flag = true;
            }
            catch (std::invalid_argument& ex) {
                std::cout << "Invalid type. Element must be int. Try again" << std::endl;
                flag = false;
            }
        }
        return item;
    }

    double getValueDouble() {
        double item = 0;
        bool flag = false;
        std::string s_item;
        while (!flag) {
            std::cin >> s_item;
            try {
                item = std::stof(s_item);
                flag = true;
            }
            catch (std::invalid_argument& ex) {
                std::cout << "Invalid type. Element must be double. Try again" << std::endl;
                flag = false;
            }
        }
        return item;
    }

    void fillSequence() {
        std::cout << "Enter values to fill your sequence:\n";

        if (user_sequence_int != nullptr) {
            int item;
            int length = user_sequence_int->getLength();
            for (int i = 0; i < length; ++i) {
                //std::cin >> s_item;
                item = getValueInt();
                user_sequence_int->set(i, item);
            }
        }
        else if (user_sequence_double != nullptr) {
            int length = user_sequence_double->getLength();
            double item;
            for (int i = 0; i < length; ++i) {

                item = getValueDouble();
                user_sequence_double->set(i, item);
            }
        }
        else if (user_sequence_string != nullptr) {
            std::string item;
            int length = user_sequence_string->getLength();
            for (int i = 0; i < length; ++i) {
                std::cin >> item;
                user_sequence_string->set(i, item);
            }
        }

        std::cout << "\n\n";
    }

};



    