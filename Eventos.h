//
// Created by aldot on 6/10/2025.
//

#ifndef EVENTOS_H
#define EVENTOS_H
#include <iostream>
#include <string>
#include "Utilidad.h"

class Evento {
public:
    std::string nombre, fecha, descripcion;

    Evento(std::string nombre = "Evento Nuevo", std::string fecha = "Sin Fecha", std::string descripcion = "Sin Descripción")
        : nombre(nombre), fecha(fecha), descripcion(descripcion) {}

    void organizar() {
        std::cout << "El evento '" << nombre << "' ha sido organizado para el " << fecha << ".\n";
    }
};


class Donacion {
public:
    int id;
    std::string donante;
    double cantidad;
    std::string tipo; // "monetaria", "especie"

    Donacion(int id = 0, std::string donante = "Anónimo", double cantidad = 0.0, std::string tipo = "monetaria")
        : id(id), donante(donante), cantidad(cantidad), tipo(tipo) {}


    void registrar() {
        donante = getLineInput("Ingresa el nombre del donante: ");
        tipo = getWordInput("Tipo de donativo (monetaria): ");

        if (tipo == "monetaria") {
            cantidad = getValidatedIntInput("Ingresa la cantidad monetaria (incluyendo centavos): ", 1); // Permitimos decimales
            std::cout << "Donación monetaria de $" << cantidad << " de " << donante << " ha sido registrada.\n";
        } else {
            std::cout << "Tipo de donación no reconocido.\n";
        }
    }

    // Sobrecarga para donaciones de horas (voluntarios)
    void registrar(int horas) {
        donante = getLineInput("Ingresa el nombre del voluntario: ");
        tipo = "tiempo"; // Especificamos que es una donación de tiempo

        if (horas > 0) {
            std::cout << "Donación de " << horas << " horas de trabajo por parte de " << donante << " ha sido registrada.\n";
        } else {
            std::cout << "Tipo de donación no reconocido.\n";
        }
    }

    // Sobrecarga para donaciones de especies
    void registrar(const std::string& especie) {
        donante = getLineInput("Ingresa el nombre del donante: ");
        tipo = "especie"; // Especificamos que es una donación de especie

        if (!especie.empty()) {
            std::cout << "Donación de especie (" << especie << ") de " << donante << " ha sido registrada.\n";
        } else {
            std::cout << "Tipo de donación no reconocido.\n";
        }
    }
};



class ProgramaEducativo {
public:
    std::string nombre, publico_objetivo;
    int duracion_horas;

    ProgramaEducativo(std::string nombre = "Programa Genérico", std::string publico = "General", int duracion = 1)
        : nombre(nombre), publico_objetivo(publico), duracion_horas(duracion) {}

    void inscribir_participante() {
        std::cout << "Un participante ha sido inscrito en el programa '" << nombre << "'.\n";
    }
};



#endif //EVENTOS_H
