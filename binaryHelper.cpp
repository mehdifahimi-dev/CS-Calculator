#include "binaryHelper.h"
#include <stdexcept>

void padBinaryStrings(std::string& first, std::string& second) {
    if (first.size() > second.size()) {
        while (second.size() != first.size()) {
            second = '0' + second;
        }
    } else {
        while (first.size() != second.size()) {
            first = '0' + first;
        }
    }
}

bool parseShiftAmount(const std::string& input, unsigned long long& shiftAmount) {
    try {
        shiftAmount = std::stoull(input);
    }
    catch (const std::out_of_range& e) {
        return false;
    }

    const unsigned long long MAX_SHIFT = 1024;

    if (shiftAmount > MAX_SHIFT) {
        return false;
    }
    return true;
}

std::string invertBinary(const std::string& input) {
    std::string invertResult;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '0') {
            invertResult = invertResult + '1';
        } else {
            invertResult = invertResult + '0';
        }
    }
    return invertResult;
}