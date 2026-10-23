#include "binaryHelper.h"

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