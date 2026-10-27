#ifndef BINARYHELPER_H
#define BINARYHELPER_H
#include <string>

void padBinaryStrings(std::string& first, std::string& second);

bool parseShiftAmount(const std::string& input, unsigned long long& shiftAmount);

#endif