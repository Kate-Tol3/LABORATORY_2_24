#include <iostream>
#include "Test.h"
#include "Interface.h"
#include "UI.h"

#include "LinkedList.h"


int main() {
    Test test;
    test.TestAll();
    UI ui;
    ui.showMenu();
    return 0;
}
