//
// Created by aldot on 6/10/2025.
//

#include "Utilidad.h"

void clearInputBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getValidatedIntInput(const std::string& prompt, int minVal, int maxVal) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail()) {
            std::cout << "Entrada inválida. Por favor, ingresa un número.\n";
            std::cin.clear();
            clearInputBuffer();
        } else if ((minVal != -1 && value < minVal) || (maxVal != -1 && value > maxVal)) {
            std::cout << "El número debe estar entre " << minVal << " y " << maxVal << ".\n";
            clearInputBuffer();
        }
        else {
            clearInputBuffer();
            return value;
        }
    }
}

std::string getLineInput(const std::string& prompt) {
    std::string value;
    std::cout << prompt;
    std::getline(std::cin, value);
    return value;
}

std::string getWordInput(const std::string& prompt) {
    std::string value;
    std::cout << prompt;
    std::cin >> value;
    clearInputBuffer(); // Clear buffer after single word input
    return value;
}