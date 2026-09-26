#include <iostream>
#include <limits>
#include "BasicCalculator.h"

void BasicCalculator::run() {
    double num1, num2, total;
    char operation;

    std::cout << "Enter the first number, the operation, and the second number: ";
    std::cin >> num1 >> operation >> num2;
    if (std::cin.fail()) {
        std::cout << "Invalid input!\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    if (operation == '+') {
        total = num1 + num2;
        std::cout << num1 << " " << operation << " " << num2 << " = " << total << std::endl;
    } else if (operation == '-') {
        total = num1 - num2;
        std::cout << num1 << " " << operation << " " << num2 << " = " << total << std::endl;
    } else if (operation == '*') {
        total = num1 * num2;
        std::cout << num1 << " " << operation << " " << num2 << " = " << total << std::endl;
    } else if (operation == '/') {
        if (num2 == 0) {
            std::cout << "Undefined\n";
        } else {
            total = num1 / num2;
            std::cout << num1 << " " << operation << " " << num2 << " = " << total << std::endl;
        }
    } else {
        std::cout << "Invalid Operation\n";
    }
}
