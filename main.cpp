#include <iostream>

int main () {

    std::cout << std::endl;
    std::cout<< "CS Calculator" << std::endl;
    std::cout << std::endl;

    int choice;

    std::cout << "MENU" << std::endl;
    std::cout << "1. Basic Calculator\n";
    std::cout << "2. Number System Converter\n";
    std::cout << "3. Bitwise Calculator\n";
    std::cout << "4. 2's Complement\n";
    std::cout << "5. Exit\n";
    std::cout << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    if (choice == 1) {
        std::cout << "Basic Calculator Selected\n";
    } else if (choice == 2) {
        std::cout << "Number System Converter Selected\n";
    } else if (choice == 3) {
        std::cout << "Bitwise Calculator Selected\n";
    } else if (choice == 4) {
        std::cout << "2's Complement Selected\n";
    } else if (choice == 5) {
        std::cout << "Exit Selected\n";
    } else {
        std::cout << "*Invalid Choice*\n";
    }

    std::cout << std::endl;

    return 0;
}