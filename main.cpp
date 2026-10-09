#include <iostream>
#include <limits>
#include "BasicCalculator.h"
#include "NumberConverter.h"
#include "BitwiseCalculator.h"

int main () {

    BasicCalculator basicCalculator;
    NumberConverter numConverter;
    BitwiseCalculator bitWise;

    std::cout << std::endl;
    std::cout<< "CS Calculator" << std::endl;
    std::cout << std::endl;

    int choice;

    do {
        std::cout << "MENU" << std::endl;
        std::cout << "1. Basic Calculator\n";
        std::cout << "2. Number System Converter\n";
        std::cout << "3. Bitwise Calculator\n";
        std::cout << "4. 2's Complement\n";
        std::cout << "5. Exit\n";
        std::cout << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Invalid input!\n";
            std::cout << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        
        if (choice == 1) {
            basicCalculator.run();
        } else if (choice == 2) {
            numConverter.run();
        } else if (choice == 3) {
            bitWise.run();
        } else if (choice == 4) {
            std::cout << "2's Complement Selected\n";
        } else if (choice == 5) {
            std::cout << "Exit Selected\n";
        } else {
            std::cout << "*Invalid Choice*\n";
        }
        std::cout << std::endl;
    } while (choice != 5);

    return 0;
}