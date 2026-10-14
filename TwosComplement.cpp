#include <iostream>
#include "TwosComplement.h"
#include "inputValidator.h"

void TwosComplement::run() {
    while (true) {
        std::cout << std::endl;
        std::cout << "2's Complement\n";
        std::cout << "  1. Find 2's Complement of a Binary Number\n";
        std::cout << "  2. Back\n";

        std::string choiceInput;
        std::cout << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choiceInput;

        // Input Validation
        if (choiceInput != "1" && choiceInput != "2") {
            std::cout << "Invalid Choice!\n";
            continue;
        }

        int intChoiceInput = choiceInput[0] - '0';

        if (intChoiceInput == 1) {
            std::cout << std::endl;
            std::cout << "Finding 2's Complement Selected\n";
            std::cout << "Enter a binary number: ";
            std::string inputInBinary;
            std::cin >> inputInBinary;

            // checks if the number is 0 or 1
            if (!isBinary(inputInBinary)) {
                std::cout << "Invalid binary number!\n";
                continue;
            }

            std::string invertedBits;
            for (int i = 0; i < inputInBinary.size(); i++) {
                if (inputInBinary[i] == '0') {
                    invertedBits = invertedBits + '1';
                } else {
                    invertedBits = invertedBits + '0';
                }
            }

            for (int i = invertedBits.size() - 1; i >= 0; i--) {
                if (invertedBits[i] == '0') {
                    invertedBits[i] = '1';
                    break;
                } else {
                    invertedBits[i] = '0';
                }
            }

            std::cout << inputInBinary << ", 2's complement -> " << invertedBits << std::endl;

        } else {
            return;
        }
   }
}
 