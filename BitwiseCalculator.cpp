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
        
        // XOR Operation
        } else if (selectOption == 3) {
            std::cout << std::endl;
            std::cout << "XOR Operation Selected\n";
            std::cout << "Enter first binary number: ";
            std::string binaryOne;
            std::cin >> binaryOne;

            bool validBinary = true;

            // checks if the number is 0 or 1
            for (int i = 0; i < binaryOne.size(); i++) {
                if (binaryOne[i] != '0' && binaryOne[i] != '1') {
                    std::cout << "Invalid binary number!\n";
                    validBinary = false;
                    break;
                }
            }
            if (!validBinary) {
                continue;
            }

            std::cout << "Enter second binary number: ";
            std::string binaryTwo;
            std::cin >> binaryTwo;

            bool validSecondBinary = true;

            // checks if the number is 0 or 1
            for (int i = 0; i < binaryTwo.size(); i++) {
                if (binaryTwo[i] != '0' && binaryTwo[i] != '1') {
                    std::cout << "Invalid binary number!\n";
                    validSecondBinary = false;
                    break;
                }
            }
            if (!validSecondBinary) {
                continue;
            }

            // makes the two binary number the same length by adding leading 0 if one is shorter
            if (binaryOne.size() > binaryTwo.size()) {
                while (binaryTwo.size() != binaryOne.size()) {
                    binaryTwo = '0' + binaryTwo;
                }
            } else {
                while (binaryOne.size() != binaryTwo.size()) {
                    binaryOne = '0' + binaryOne;
                }
            }

            std::string xorResult;      // result of the XOR operation

            // do XOR operation
            for (int i = 0; i < binaryOne.size(); i++) {
                if (binaryOne[i] != binaryTwo[i]) {
                    xorResult = xorResult + '1';
                } else {
                    xorResult = xorResult + '0';
                }
            }

            // Prints the result
            std::cout << std::endl;
            std::cout << "      " << binaryOne << std::endl;
            std::cout << "XOR" << std::endl;
            std::cout << "      " << binaryTwo << std::endl;
            std::cout << "-----------------------" << std::endl;
            std::cout << "      " << xorResult << std::endl;

        // NOT Operation
        } else if (selectOption == 4) {
            std::cout << std::endl;
            std::cout << "NOT Operation Selected\n";
            std::cout << "Enter a binary number: ";
            
            std::string number;
            std::cin >> number;

            bool validBinary = true;

            // checks if the number is 0 or 1
            for (int i = 0; i < number.size(); i++) {
                if (number[i] != '0' && number[i] != '1') {
                    std::cout << "Invalid binary number!\n";
                    validBinary = false;
                    break;
                }
            }
            if (!validBinary) {
                continue;
            }

            std::string notResult;

            for (int i = 0; i < number.size(); i++) {
                if (number[i] == '0') {
                    notResult = notResult + '1';
                } else {
                    notResult = notResult + '0';
                }
            }

            // Prints the result
            std::cout << std::endl;
            std::cout << "NOT(" << number << ") -> " << notResult;
            std::cout << std::endl;

        // Shift Left Operation
        } else if (selectOption == 5) {
            std::cout << std::endl;
            std::cout << "Left Shift Selected\n";
            std::cout << "Enter a binary number: ";

            std::string binaryNumber;       // binary number to be shifted
            std::cin >> binaryNumber;

            bool validBinary = true;

            // checks if the number is 0 or 1
            for (int i = 0; i < binaryNumber.size(); i++) {
                if (binaryNumber[i] != '0' && binaryNumber[i] != '1') {
                    std::cout << "Invalid binary number!\n";
                    validBinary = false;
                    break;
                }
            }
            if (!validBinary) {
                continue;
            }

            std::string shiftInput;
            std::cout << "Enter shift amount: ";
            std::cin >> shiftInput;

            bool validShiftInput = true;

            for (int i = 0; i < shiftInput.size(); i++) {
                if (shiftInput[i] < '0' || shiftInput[i] > '9') {
                    std::cout << "Invalid input!\n";
                    validShiftInput = false;
                    break;
                }
            }
            if (!validShiftInput) {
                continue;
            }

            // Converting the input into a number
            unsigned long long shiftAmount;
            try {
                shiftAmount = std::stoull(shiftInput);
            }
            catch (const std::out_of_range& e) {
                std::cout << std::endl;
                std::cout << "Shift amount is too large!\n";
                continue;
            }

            if (shiftAmount == 0) {
                std::cout << std::endl;
                std::cout << binaryNumber << ", left shift (" << shiftAmount << ") -> " << binaryNumber << std::endl;
                continue;
            }

            // Put a limit for the shift amount
            const unsigned long long MAX_SHIFT = 1024;
            if (shiftAmount > MAX_SHIFT) {
                std::cout << "Shift amount is too large! Maximum is 1024.\n";
                continue;
            }

            // add zeros to the end of the shift result based on the shift amount
            std::string shiftResult = binaryNumber;
            for (unsigned long long i = 0; i < shiftAmount; i++) {
                shiftResult = shiftResult + '0';
            }

            // Prints the result
            std::cout << std::endl;
            std::cout << binaryNumber << ", left shift (" << shiftAmount << ") -> " << shiftResult << std::endl;

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