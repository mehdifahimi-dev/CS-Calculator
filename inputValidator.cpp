#include "inputValidator.h"

// if the character is not '0' or '1' then it returns false.
// It returns true if the loop does not find any invalid character
bool isBinary(const std::string& input) {
    for (int i = 0; i < input.size(); i++) {
        if (input[i] != '0' && input[i] != '1') {
            return false;
        }
    }
    return true;
}