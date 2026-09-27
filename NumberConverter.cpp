#include <iostream>
#include <limits>
#include <vector>
#include "NumberConverter.h"

void NumberConverter::run() {
    std::cout << "Number System Converter Selected\n";

    int nonNegativeNum;
    std::cout << "Enter a non-negative integer: ";
    std::cin >> nonNegativeNum;

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

    for (int i = binary.size() - 1; i >= 0; i--) {
        std::cout << binary[i];
    }
    std::cout << std::endl;
}