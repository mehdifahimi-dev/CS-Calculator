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
    std::cout << "  5. Decimal to Octal\n";
    std::cout << "  6. Binary to Octal\n";
    std::cout << "  7. Octal to Binary\n";
    std::cout << "  8. Back\n";
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

    // Decimal to binary
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
    
    // Binary to decimal
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

    // Decimal to hexadecimal
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

    // Hexadecimal to decimal
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
    
    // Decimal to Octal
    } else if (option == 5) {
        std::cout << "Decimal to Octal Selected\n";
        std::string decNum;
        std::cout << "Enter a non-negative integer: ";
        std::cin >> decNum;
        
        for (int i = 0; i < decNum.size(); i++) {
            if (decNum[i] < '0' || decNum[i] > '9') {
                std::cout << "Invalid input!\n";
                return;
            }
        }
        unsigned long long decToOc;
        try {
            decToOc = std::stoull(decNum);
        }
        catch (const std::out_of_range& e) {
            std::cout << "Number is too large!\n";
            return;
        }

        if (decToOc == 0) {
            std::cout << "0\n";
            return;
        }

        std::vector<int> octal;

        while (decToOc > 0) {
            int remainderResult;
            remainderResult = decToOc % 8;
            octal.push_back(remainderResult);
            decToOc = decToOc / 8;
        }

        for (int i = octal.size() -1 ; i >= 0; i--) {
            std::cout << octal[i];
        }
        std::cout << std::endl;

     // Binary to Octal
    } else if (option == 6) {
        std::cout << "Binary to Octal Selected\n";
        std::cout << "Enter a binary number: ";

        std::string binaryNum;
        std::cin >> binaryNum;

        for (int i = 0; i < binaryNum.size(); i++) {
            if (binaryNum[i] != '0' && binaryNum[i] != '1') {
                std::cout << "Invalid binary number!\n";
                return;
            }
        }

        int extraBits = binaryNum.size() % 3;
        if (extraBits == 1) {
            binaryNum = "00" + binaryNum;
        } else if (extraBits == 2) {
            binaryNum = "0" + binaryNum;
        }

        std::string octalResult;
        for (int i = 0; i < binaryNum.size(); i+=3) {
            int octalDigit = 0;
            octalDigit += (binaryNum[i] - '0') * 4;
            octalDigit += (binaryNum[i + 1] - '0') * 2;
            octalDigit += (binaryNum[i + 2] - '0') * 1;
            octalResult += octalDigit + '0';
        }
        while (octalResult.size() > 1 && octalResult[0] == '0') {
            octalResult.erase(0, 1);
        }
        std::cout << "Binary (" << binaryNum << ") to octal is: ";
        std::cout << octalResult;
        std::cout << std::endl;

     // Octal to Binary
    } else if (option == 7) {
        std::cout << "Octal to Binary Selected\n";
    } else if (option == 8) {
        return;
    } else {
        std::cout << "Invalid Choice!\n";
    }

}