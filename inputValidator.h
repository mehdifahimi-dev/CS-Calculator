#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H
#include <string>

bool isBinary(const std::string& input);
bool isNonNegativeInteger(const std::string& input);
bool parseUnsignedInteger(const std::string& input, unsigned long long& value);
#endif
