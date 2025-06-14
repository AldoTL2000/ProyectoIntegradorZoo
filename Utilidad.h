//
// Created by aldot on 6/10/2025.
//

#ifndef UTILIDAD_H
#define UTILIDAD_H



#include <iostream>
#include <string>
#include <limits>
#include <locale>

void clearInputBuffer();
int getValidatedIntInput(const std::string& prompt, int minVal = -1, int maxVal = -1);
std::string getLineInput(const std::string& prompt);
std::string getWordInput(const std::string& prompt);



#endif //UTILIDAD_H
