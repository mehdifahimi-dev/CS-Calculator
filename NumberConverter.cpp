#include <iostream>
#include <limits>
#include <vector>
#include <string>
#include <stdexcept>
#include "NumberConverter.h"

void NumberConverter::run() {

    std::cout << std::endl;
    std::cout << "Number System Converter\n";
    std::cout << "  1. Decimal to Binary\n";
    std::cout << "  2. Binary to Decimal\n";
    std::cout << "  3. Decimal to Hexadecimal\n";
    std::cout << "  4. Hexadecimal to Decimal\n";
    std::cout << "  5. Back\n";
    std::cout << std::endl;

    int option;
    std::cout << "Enter your choice: ";
    std::cin >> option;

    if (std::cin.fail()) {
        std::cout << "Invalid input!\n";
        std::cout << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

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
        std::cout << "Decimal to Hexadecimal Selected\n";

        std::string nonNegativeNum1;
        std::cout << "Enter a non-negative integer: ";
        std::cin >> nonNegativeNum1;
        for (int i = 0; i < nonNegativeNum1.size(); i++) {
            if (nonNegativeNum1[i] < '0' || nonNegativeNum1[i] > '9') {
                std::cout << "Invalid input!\n";
                return;
            }
        }
        int convertedString;
        try {
            convertedString = std::stoi(nonNegativeNum1);
        }
        catch (const std::out_of_range& e) {
            std::cout << "Number is too large!\n";
            return;
        }
        int dec = convertedString;

        std::vector <char> hexDecimal;

        if (convertedString == 0) {
        std::cout << "0\n";
        return;
        }
        while(convertedString > 0) {
            int remainder1;
            remainder1 = convertedString % 16;
            convertedString = convertedString / 16;

            char character;
            if (remainder1 < 10) {
                character = '0' + remainder1;
            } else {
                character = 'A' + (remainder1 - 10);
            }

            hexDecimal.push_back(character);
        }
        std::cout << "The decimal (" << dec << ") to hexadecimal is: ";
        for (int i = hexDecimal.size() - 1; i >= 0; i--) {
            std::cout << hexDecimal[i];
        }
        std::cout << std::endl; 

    } else if (option == 4) {
        std::cout << "Hexadecimal to Decimal Selected\n";
        std::cout << "Enter a hexadecimal number: ";
        std::string hexa;
        std::cin >> hexa;

        for (int i = 0; i < hexa.size(); i++) {
            if (!((hexa[i] >= '0' && hexa[i] <= '9') || (hexa[i] >= 'A' && hexa[i] <= 'F') || (hexa[i] >= 'a' && hexa[i] <= 'f'))) {
                std::cout << "Invalid hexadecimal number!\n";
                return;
            }
        }
        unsigned long long hexToDecResult = 0;
        unsigned long long maxValue = std::numeric_limits<unsigned long long>::max();

        for (int i = 0; i < hexa.size(); i++) {
            int digitValue;
            if (hexa[i] >= '0' && hexa[i] <= '9') {
                digitValue = hexa[i] - '0';
            } else if (hexa[i] == 'A' || hexa[i] == 'a') {
                digitValue = 10;
            } else if (hexa[i] == 'B' || hexa[i] == 'b') {
                digitValue = 11;
            } else if (hexa[i] == 'C' || hexa[i] == 'c') {
                digitValue = 12;
            } else if (hexa[i] == 'D' || hexa[i] == 'd') {
                digitValue = 13;
            } else if (hexa[i] == 'E' || hexa[i] == 'e') {
                digitValue = 14;
            } else {
                digitValue = 15;
            }

            if (hexToDecResult > (maxValue - digitValue) / 16) {
                std::cout << "Number is too large!\n";
                return;
            }
            hexToDecResult = (hexToDecResult * 16) + digitValue;
        }
        std::cout << hexToDecResult;
        std::cout << std::endl;
    } else if (option == 5) {
        return;
    } else {
        std::cout << "Invalid Choice!\n";
    }

}