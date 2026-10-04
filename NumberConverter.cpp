#include <iostream>
#include <limits>
#include <vector>
#include <string>
#include <stdexcept>
#include "NumberConverter.h"

void NumberConverter::run() {

    while(true) {

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

        std::string option;
        std::cout << "Enter your choice: ";
        std::cin >> option;

        if (option.size() != 1 || option[0] < '1' || option[0] > '8') {
            std::cout << "Invalid Choice!\n";
            continue;
        }

        int optionNumber = option[0] - '0';

        // Decimal to binary
        if (optionNumber == 1) {
            std::cout << "Decimal to Binary Selected\n";
            
            std::string decimalInput;
            std::cout << "Enter a non-negative integer: ";
            std::cin >> decimalInput;

            bool validDecimalToBinary = true;

            for (int i = 0; i < decimalInput.size(); i++) {
                if (decimalInput[i] < '0' || decimalInput[i] > '9') {
                    std::cout << "Invalid input!\n";
                    validDecimalToBinary = false;
                    break;
                }
            }
            if (!validDecimalToBinary) {
                continue;
            }

            unsigned long long decToBinary;
            try {
                decToBinary = std::stoull(decimalInput);
            }
            catch (const std::out_of_range& e) {
                std::cout << "Number is too large!\n";
                continue;
            }

            if (decToBinary == 0) {
                std::cout << "0\n";
                continue;
            }

            std::vector<int> binary;

            while(decToBinary > 0) {
                int remainder;
                remainder = decToBinary % 2;
                binary.push_back(remainder);
                decToBinary = decToBinary / 2;
            }
            std::cout << "Decimal (" << decimalInput << ") to binary is: ";
            for (int i = binary.size() - 1; i >= 0; i--) {
                std::cout << binary[i];
            }
            std::cout << std::endl;
        
        // Binary to decimal
        } else if (optionNumber == 2) {
            std::cout << "Binary to Decimal Selected\n";
            std::string binary;
            std::cout << "Enter a binary number: ";
            std::cin >> binary;

            bool validBinaryToDecimal = true;

            // checks if the number is 0 or 1
            for (int i = 0; i < binary.size(); i++) {
                if (binary[i] != '0' && binary[i] != '1') {
                    std::cout << "Invalid binary number!\n";
                    validBinaryToDecimal = false;
                    break;
                }
            }
            
            if (!validBinaryToDecimal) {
                continue;
            }

            unsigned long long result = 0;
            unsigned long long maxValue = std::numeric_limits<unsigned long long>::max();

            bool binaryOverflow = false;
            for (int i = 0; i < binary.size(); i++) {
                int digitValue = binary[i] - '0';

                if (result > (maxValue - digitValue) / 2) {
                    std::cout << "Number is too large!\n";
                    binaryOverflow = true;
                    break;
                }
                result = (result * 2) + digitValue;
            }
            if (binaryOverflow) {
                continue;
            }
            std::cout << result << std::endl;

        // Decimal to hexadecimal
        } else if (optionNumber == 3) {
            std::cout << "Decimal to Hexadecimal Selected\n";

            std::string nonNegativeNum1;
            std::cout << "Enter a non-negative integer: ";
            std::cin >> nonNegativeNum1;

            bool validDecimalToHex = true;

            for (int i = 0; i < nonNegativeNum1.size(); i++) {
                if (nonNegativeNum1[i] < '0' || nonNegativeNum1[i] > '9') {
                    std::cout << "Invalid input!\n";
                    validDecimalToHex = false;
                    break;
                }
            }

            if (!validDecimalToHex) {
                continue;
            }

            int convertedString;
            try {
                convertedString = std::stoi(nonNegativeNum1);
            }
            catch (const std::out_of_range& e) {
                std::cout << "Number is too large!\n";
                continue;
            }
            int dec = convertedString;

            std::vector <char> hexDecimal;

            if (convertedString == 0) {
            std::cout << "0\n";
            continue;
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
            std::cout << "The decimal (" << dec << ") to hexadecimal is: 0x";
            for (int i = hexDecimal.size() - 1; i >= 0; i--) {
                std::cout << hexDecimal[i];
            }
            std::cout << std::endl; 

        // Hexadecimal to decimal
        } else if (optionNumber == 4) {
            std::cout << "Hexadecimal to Decimal Selected\n";
            std::cout << "Enter a hexadecimal number: ";
            std::string hexa;
            std::cin >> hexa;

            bool validHexaToDecimal = true;

            // validation for hexadecimal number
            for (int i = 0; i < hexa.size(); i++) {
                if (!((hexa[i] >= '0' && hexa[i] <= '9') || (hexa[i] >= 'A' && hexa[i] <= 'F') || (hexa[i] >= 'a' && hexa[i] <= 'f'))) {
                    std::cout << "Invalid hexadecimal number!\n";
                    validHexaToDecimal = false;
                    break;
                }
            }
            if (!validHexaToDecimal) {
                continue;
            }

            unsigned long long hexToDecResult = 0;
            unsigned long long maxValue = std::numeric_limits<unsigned long long>::max();

            bool hexOverflow = false;

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
                    hexOverflow = true;
                    break;
                }
                hexToDecResult = (hexToDecResult * 16) + digitValue;
            }
            if (hexOverflow) {
                continue;
            }
            std::cout << hexToDecResult;
            std::cout << std::endl;
        
        // Decimal to Octal
        } else if (optionNumber == 5) {
            std::cout << "Decimal to Octal Selected\n";
            std::string decNum;
            std::cout << "Enter a non-negative integer: ";
            std::cin >> decNum;
            
            bool validDecimalToOctal = true;

            for (int i = 0; i < decNum.size(); i++) {
                if (decNum[i] < '0' || decNum[i] > '9') {
                    std::cout << "Invalid input!\n";
                    validDecimalToOctal = false;
                    break;
                }
            }
            if (!validDecimalToOctal) {
                continue;
            }

            unsigned long long decToOc;
            try {
                decToOc = std::stoull(decNum);
            }
            catch (const std::out_of_range& e) {
                std::cout << "Number is too large!\n";
                continue;
            }

            if (decToOc == 0) {
                std::cout << "0\n";
                continue;
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
        } else if (optionNumber == 6) {
            std::cout << "Binary to Octal Selected\n";
            std::cout << "Enter a binary number: ";

            std::string binaryNum;
            std::cin >> binaryNum;

            bool validBinary = true;

            // checks if the number is 0 or 1
            for (int i = 0; i < binaryNum.size(); i++) {
                if (binaryNum[i] != '0' && binaryNum[i] != '1') {
                    std::cout << "Invalid binary number!\n";
                    validBinary = false;
                    break;
                }
            }
            if (!validBinary) {
                continue;
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
        } else if (optionNumber == 7) {
            std::cout << "Octal to Binary Selected\n";
            std::cout << "Enter an octal number: ";
            std::string octalNum;
            std::cin >> octalNum;

            bool validOctal = true;

            // check if the number is between 0 and 7
            for (int i = 0; i < octalNum.size(); i++) {
                if (octalNum[i] < '0' || octalNum[i] > '7') {
                    std::cout << "Invalid octal number!\n";
                    validOctal = false;
                    break;
                }
            }

            if (validOctal == false) { 
                continue;
            }

            std::string binaryResult;

            // convert the octal number into its numeric value
            for (int i = 0; i < octalNum.size(); i++) {
                int intNumber;
                intNumber = octalNum[i] - '0';
                std::string octBinaryNum;

                if (intNumber >= 4) {
                    octBinaryNum = octBinaryNum + '1';
                    intNumber = intNumber - 4;
                } else {
                    octBinaryNum = octBinaryNum + '0';
                }

                if (intNumber >= 2) {
                    octBinaryNum = octBinaryNum + '1';
                    intNumber = intNumber - 2;
                } else {
                    octBinaryNum = octBinaryNum + '0';
                }

                if (intNumber >= 1) {
                    octBinaryNum = octBinaryNum + '1';
                    intNumber = intNumber - 1;
                } else {
                    octBinaryNum = octBinaryNum + '0';
                }
                binaryResult = binaryResult + octBinaryNum;

            }
            while (binaryResult.size() > 1 && binaryResult[0] == '0') {
                binaryResult.erase(0, 1);
            }
            std::cout << "Octal (" << octalNum << ") to binary is: ";
            std::cout << binaryResult;
            std::cout << std::endl;
                
        } else if (optionNumber == 8) {
            return;
        } else {
            std::cout << "Invalid Choice!\n";
        }

    }

}