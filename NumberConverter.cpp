#include <iostream>
#include <limits>
#include <vector>
#include <string>
#include "NumberConverter.h"

void NumberConverter::run() {

    std::cout << std::endl;
    std::cout << "Number System Converter\n";
    std::cout << "  1. Decimal to Binary\n";
    std::cout << "  2. Binary to Decimal\n";
    std::cout << "  3. Back\n";
    std::cout << std::endl;

    int option;
    std::cout << "Enter your choice: ";
    std::cin >> option;

    if (option == 1) {
        std::cout << "Decimal to Binary Selected\n";
        
        int nonNegativeNum;
        std::cout << "Enter a non-negative integer: ";
        std::cin >> nonNegativeNum;
        int enteredNum = nonNegativeNum;

        if (std::cin.fail() || nonNegativeNum < 0) {
            std::cout << "Invalid input!\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }

        std::vector<int> binary;

        if (nonNegativeNum == 0) {
            std::cout << "0\n";
            return;
        }
        while(nonNegativeNum > 0) {
            int remainder;
            remainder = nonNegativeNum % 2;
            binary.push_back(remainder);
            nonNegativeNum = nonNegativeNum / 2;
        }
        std::cout << "The decimal (" << enteredNum << ") to binary is: ";
        for (int i = binary.size() - 1; i >= 0; i--) {
            std::cout << binary[i];
        }
        std::cout << std::endl;
    } else if (option == 2) {
        std::cout << "Binary to Decimal Selected\n";
        std::string binary;
        std::cout << "Enter a binary number: ";
        std::cin >> binary;
        for (int i = 0; i < binary.size(); i++) {
            if (binary[i] != '0' && binary[i] != '1') {
                std::cout << "Invalid binary number!\n";
                return;
            }
        }
        int result = 0;
        for (int i = 0; i < binary.size(); i++) {
            result = (result * 2) + (binary[i] - '0');
        }
        std::cout << result;
        std::cout << std::endl;
        
    } else if (option == 3) {
        return;
    } else {
        std::cout << "Invalid Choice!\n";
    }

    
}