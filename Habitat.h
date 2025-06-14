//
// Created by aldot on 6/10/2025.
//

#ifndef HABITAT_H
#define HABITAT_H
#include <string>
#include <iostream>

class Habitat {
public:
    std::string nombre, tipo;
    double tamaño;

    Habitat(std::string nombre = "Sin Nombre", std::string tipo = "Desconocido", double tamaño = 0.0)
        : nombre(nombre), tipo(tipo), tamaño(tamaño) {}

    void limpiar() {
        std::cout << "El hábitat '" << nombre << "' está siendo limpiado.\n";
    }

    void inspeccionar() {
        std::cout << "El hábitat '" << nombre << "' está siendo inspeccionado.\n";
    }
};


#endif //HABITAT_H
