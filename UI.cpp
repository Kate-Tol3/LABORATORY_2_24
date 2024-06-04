#include "UI.h"

//UIFunc

void UI::getArgument(int* i_arg) {
    std::string s_arg;
    std::cin >> s_arg;
    try {
        *i_arg = std::stoi(s_arg);
    }
    catch (std::invalid_argument& ex) {
        *i_arg = -10000000;
        // std::cout << "Invalid type. Must be number. Try again.";
    }
}

int UI::getElemsType() {
    std::string s_type;
    int i_type;
    std::cout << "Select type of elements in new Sequence\n"
        "1: int\n"
        "2: double\n"
        "3:string\n"
        "Enter type:";
    getArgument(&i_type);

    while (i_type < 1 || i_type > 3) {
        std::cout << "\nInvalid element type. Try again.\n\n";
        getArgument(&i_type);
    }
    return i_type;
}

int UI::getSequenceLength() {
    std::string s_len;
    int i_len;
    std::cout << "Type length of you new sequence" << std::endl;
    std::cout << "Length:";
    getArgument(&i_len);
    while (i_len <= 0) {
        std::cout << "\nInvalid length. Try again.\n\n";
        getArgument(&i_len);
    }
    return i_len;
}

int UI::getSequenceType() {
    std::string s_type;
    int i_type;
    std::cout << "Select type of your new Sequence\n"
        "1:MutableArraySequence\n"
        "2:MutableListSequence\n"
        "Enter type:";
    getArgument(&i_type);

    while (i_type < 1 || i_type > 2) {
        std::cout << "\nInvalid sequence type. Try again.\n\n";
        getArgument(&i_type);
    }
    return i_type;
}

void UI::showList() {
    std::cout << "Select action:\n"
        << "1 *** print Sequence\n"
        << "2 *** print Element\n"
        << "3 *** printFirst\n"
        << "4 *** printLast\n"
        << "5 *** insert Value\n"
        << "6 *** append Value\n"
        << "7 *** prepend Value\n"
        << "8 *** Print SubSequence\n"
        << "9 *** get length of Sequence\n"
        << "0 *** exit.\n"
        << "\nEnter action number from list:";
}

void UI::menu() {

    int seq_type = getSequenceType();
    int el_type = getElemsType();
    int length = getSequenceLength();

    UserSequence user_sequence(seq_type, el_type, length);
    user_sequence.fillSequence();

    showList();

    int action;
    getArgument(&action);
    std::string s_action;
    std::cin >> s_action;

    try {
        action = std::stoi(s_action);
    }
    catch (std::invalid_argument& ex) {
        std::cout << "Invalid type.Must be number. Try again.\n";
        std::cin >> s_action;
    }

    while (action != 0) {
        switch (action) {
        case 1:
            user_sequence.printSequence();
            break;
        case 2:
            user_sequence.printValue();
            break;
        case 3:
            user_sequence.printFirst();
            break;
        case 4:
            user_sequence.printLast();
            break;
        case 5:
            user_sequence.insertValue();
            break;
        case 6:
            user_sequence.appendValue();
            break;
        case 7:
            user_sequence.prependValue();
            break;
        case 8:
            user_sequence.printSubsequence();
            break;
        case 9:
            user_sequence.getLength();
            break;
        case 0:
            break;
        default:
            std::cout << "Not an action from list! Try again." << std::endl;
            action = 0;
            break;
        }
        showList();
        std::cin >> s_action;
        try {
            action = std::stoi(s_action);
        }
        catch (std::invalid_argument& ex) {
            std::cout << "Invalid type.Must be number. Try again.\n";
            action = -10;
            showList();
        }
    }
}

void UI::showMenu() {
    std::cout << "Hello user!! This program allows you to operate Sequences\n\n";
    std::string s_action;
    int action = 0;
    do {
        menu();
        std::cout << "To exit program enter -1.\n" << "To create new sequence enter any other number:\n";
        std::cin >> s_action;

        try {
            action = std::stoi(s_action);
        }
        catch (std::invalid_argument& ex) {
            std::cout << "Invalid type.Must be number. Try again.\n";
        }

    } while (action != -1);

    std::cout << "\n Bye!\n";
}