#include <iostream>
#include "BitwiseCalculator.h"

void BitwiseCalculator::run() {
    while (true) {
        std::cout << std::endl;
        std::cout << "Bitwise Calculator\n";
        std::cout << "  1. AND\n";
        std::cout << "  2. OR\n";
        std::cout << "  3. XOR\n";
        std::cout << "  4. NOT\n";
        std::cout << "  5. Left Shift\n";
        std::cout << "  6. Logical Right Shift\n";
        std::cout << "  7. Arithmetic Right Shift\n";
        std::cout << "  8. Back\n";
        std::cout << std::endl;

        std::string menuOption;
        std::cout << "Enter your choice: ";
        std::cin >> menuOption;

        // Input Validation
        if (menuOption.size() != 1 || menuOption[0] < '1' || menuOption[0] > '8') {
            std::cout << "Invalid Choice!\n";
            continue;
        }

        int selectOption = menuOption[0] - '0';
        
        // AND Operation
        if (selectOption == 1) {
            std::cout << std::endl;
            std::cout << "AND Operation Selected\n";
            std::cout << "Enter first binary number: ";
            std::string firstBinary;
            std::cin >> firstBinary;

            bool validBinary = true;

            // checks if the number is 0 or 1
            for (int i = 0; i < firstBinary.size(); i++) {
                if (firstBinary[i] != '0' && firstBinary[i] != '1') {
                    std::cout << "Invalid binary number!\n";
                    validBinary = false;
                    break;
                }
            }
            if (!validBinary) {
                continue;
            }

            std::cout << "Enter second binary number: ";
            std::string secondBinary;
            std::cin >> secondBinary;

            bool validSecondBinary = true;

            // checks if the number is 0 or 1
            for (int i = 0; i < secondBinary.size(); i++) {
                if (secondBinary[i] != '0' && secondBinary[i] != '1') {
                    std::cout << "Invalid binary number!\n";
                    validSecondBinary = false;
                    break;
                }
            }
            if (!validSecondBinary) {
                continue;
            }

            // makes the two binary number the same length by adding leading 0 if one is shorter
            if (firstBinary.size() > secondBinary.size()) {
                while (secondBinary.size() != firstBinary.size()) {
                    secondBinary = '0' + secondBinary;
                }
            } else {
                while (firstBinary.size() != secondBinary.size()) {
                    firstBinary = '0' + firstBinary;
                }
            }

            std::string andResult;      // result of the AND operation

            // do AND operation
            for (int i = 0; i < firstBinary.size(); i++) {
                if (firstBinary[i] == '1' && secondBinary[i] == '1') {
                    andResult = andResult + '1';
                } else {
                    andResult = andResult + '0';
                }
            }

            // Prints the result
            std::cout << std::endl;
            std::cout << "      " << firstBinary << std::endl;
            std::cout << "AND" << std::endl;
            std::cout << "      " << secondBinary << std::endl;
            std::cout << "-----------------------" << std::endl;
            std::cout << "      " << andResult << std::endl;

        // OR Operation
        } else if (selectOption == 2) {
            std::cout << std::endl;
            std::cout << "OR Operation Selected\n";
            std::cout << "Enter first binary number: ";
            std::string binaryNum1;
            std::cin >> binaryNum1;

            bool validBinary = true;

            // checks if the number is 0 or 1
            for (int i = 0; i < binaryNum1.size(); i++) {
                if (binaryNum1[i] != '0' && binaryNum1[i] != '1') {
                    std::cout << "Invalid binary number!\n";
                    validBinary = false;
                    break;
                }
            }
            if (!validBinary) {
                continue;
            }

            std::cout << "Enter second binary number: ";
            std::string binaryNum2;
            std::cin >> binaryNum2;

            bool validSecondBinary = true;

            // checks if the number is 0 or 1
            for (int i = 0; i < binaryNum2.size(); i++) {
                if (binaryNum2[i] != '0' && binaryNum2[i] != '1') {
                    std::cout << "Invalid binary number!\n";
                    validSecondBinary = false;
                    break;
                }
            }
            if (!validSecondBinary) {
                continue;
            }

            // makes the two binary number the same length by adding leading 0 if one is shorter
            if (binaryNum1.size() > binaryNum2.size()) {
                while (binaryNum2.size() != binaryNum1.size()) {
                    binaryNum2 = '0' + binaryNum2;
                }
            } else {
                while (binaryNum1.size() != binaryNum2.size()) {
                    binaryNum1 = '0' + binaryNum1;
                }
            }

            std::string orResult;      // result of the OR operation

            // do OR operation
            for (int i = 0; i < binaryNum1.size(); i++) {
                if (binaryNum1[i] == '1' || binaryNum2[i] == '1') {
                    orResult = orResult + '1';
                } else {
                    orResult = orResult + '0';
                }
            }

            // Prints the result
            std::cout << std::endl;
            std::cout << "      " << binaryNum1 << std::endl;
            std::cout << "OR" << std::endl;
            std::cout << "      " << binaryNum2 << std::endl;
            std::cout << "-----------------------" << std::endl;
            std::cout << "      " << orResult << std::endl;

        } else if (selectOption == 3) {
            std::cout << std::endl;
            std::cout << "XOR Operation Selected\n";
        } else if (selectOption == 4) {
            std::cout << std::endl;
            std::cout << "NOT Operation Selected\n";
        } else if (selectOption == 5) {
            std::cout << std::endl;
            std::cout << "Left Shift Selected\n";
        } else if (selectOption == 6) {
            std::cout << std::endl;
            std::cout << "Logical Right Shift Selected\n";
        } else if (selectOption == 7) {
            std::cout << std::endl;
            std::cout << "Arithmetic Right Shift Selected\n";
        } else if (selectOption == 8) {
            return;
        } else {
            std::cout << "Invalid Choice!\n";
        }
    }
} 