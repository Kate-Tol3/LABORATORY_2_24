#include <iostream>

#include "ImmutableArraySequence.h"
#include "MutableArraySequence.h"
#include <string>

int main() {
   // std::string a[4] = {'0', '4', '5', '7'};
    //std::string *ptr = a;
    ImmutableArraySequence<std::string> list1{};
    MutableArraySequence<std::string> list2{};
    list1.print();
    std:: cout << std::endl;
    list2.print();
    std:: cout << std::endl;
    (list1.concat(&list1))->print();
    std:: cout << std::endl;
    list2.concat(&list2)->print();
    std:: cout << std::endl;
    list1.print();
    std:: cout << std::endl;
    list2.print();

    return 0;
}
