#include <iostream>
#include <string>
#include <algorithm>
#include <limits>

bool isValidInput(const std::string& input) {
    for (char c : input) {
        if (!isdigit(c)) {
            return false;
        }
    }
    try {
        unsigned long long value = std::stoull(input);
        if (value > 4294967295ULL) {
            return false;
        }
    } catch (...) {
        return false;
    }
    return true;
}

std::string convTen2Two(unsigned int baseTenValue) {
    if (baseTenValue == 0) {
        return "0";
    }
    
    std::string binary;
    while (baseTenValue > 0) {
        binary.push_back((baseTenValue % 2) + '0');
        baseTenValue /= 2;
    }
    std::reverse(binary.begin(), binary.end());
    return binary;
}

int main() {
    std::cout << "Enter a non-negative base 10 integer between 0 and 4294967295 (with no commas) and hit Enter/Return: ";
    std::string input;
    std::cin >> input;

    if (!isValidInput(input)) {
        std::cout << "Invalid input!" << std::endl;
        return 1;
    }

    unsigned int value = std::stoul(input);
    std::string binaryValue = convTen2Two(value);
    std::cout << binaryValue << std::endl;

    return 0;
}
