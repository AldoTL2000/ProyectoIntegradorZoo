//
// Created by aldot on 6/10/2025.
//

#ifndef STAFF_H
#define STAFF_H
#include <string>
#include<iostream>
#include "Animal.h"
#include <vector>

class Cuidador {
public:
    int id;
    std::string nombre, especialidad;

    Cuidador(int id = 0, std::string nombre = "Desconocido", std::string especialidad = "General")
        : id(id), nombre(nombre), especialidad(especialidad) {}

    void alimentar_animal(Animal& animal) {
        std::cout << nombre << " está alimentando a " << animal.getNombre() << ".\n";
    }

    void revisar_animal(Animal& animal) {
        std::cout << nombre << " está revisando a " << animal.getNombre() << ".\n";
    }
};

class Veterinario : public Cuidador {
public:
    Veterinario(int id = 0, std::string nombre = "Dr. Desconocido", std::string especialidad = "Veterinaria")
        : Cuidador(id, nombre, especialidad) {}
};


class Guia {
public:
    int id;
    std::string nombre;
    std::string idiomas;

    Guia(int id = 0, std::string nombre = "Guía Anónimo", std::string idiomas = "Español")
        : id(id), nombre(nombre), idiomas(idiomas) {}

    void ingresarDatos() {
        nombre = getLineInput("Ingresa el nombre del guía: ");
        id = getValidatedIntInput("Ingresa el ID del guía: ", 1);
        idiomas = getLineInput("Ingresa los idiomas que habla (separados por coma): ");
    }

    void guiar_visita() {
        std::cout << nombre << " (ID: " << id << ") está guiando una visita.\n";
    }
     void guiar_visita_a_animal(Animal& animal) {
        std::cout << nombre << " (ID: " << id << ") está guiando una visita hacia el hábitat de " << animal.getNombre() << ".\n";
    }
};



class Seguridad {
public:
    int id;
    std::string nombre, horario;

    Seguridad(int id = 0, std::string nombre = "Oficial Desconocido", std::string horario = "Rotativo")
        : id(id), nombre(nombre), horario(horario) {}

    void patrullar() {
        std::cout << nombre << " está patrullando las instalaciones.\n";
    }
};

class ServMedicos : public Seguridad {
public:
    bool lesiones_menores_disponibles;
    bool requiere_ambulancia;

    ServMedicos(bool lesiones_menores = true, bool urgencia = false, int id = 0, std::string nombre = "Médico", std::string horario = "24/7")
        : Seguridad(id, nombre, horario), lesiones_menores_disponibles(lesiones_menores), requiere_ambulancia(urgencia) {}

    void evaluar_emergencia() {
        std::string respuesta = getWordInput("¿Hay una urgencia médica grave que requiera ambulancia? (si/no): ");
        requiere_ambulancia = (respuesta == "si");

        if (requiere_ambulancia) {
            std::cout << "Se está llamando a una ambulancia. Mantenga la calma y siga las instrucciones.\n";
        } else if (lesiones_menores_disponibles) {
            std::cout << "Se puede ofrecer atención para lesiones menores en el puesto de primeros auxilios.\n";
        } else {
            std::cout << "No se requiere atención especial de momento o la situación está bajo control.\n";
        }
    }
};


class Mantenimiento {
public:
    int id;
    std::string nombre;
    std::vector<std::string> areas_asignadas;

    Mantenimiento(int id = 0, std::string nombre = "Encargado Mantenimiento", std::vector<std::string> areas = {})
        : id(id), nombre(nombre), areas_asignadas(areas) {}

    void reparar(const std::string& area) {
        std::cout << nombre << " está reparando en el área de " << area << ".\n";
    }

    void limpiar(const std::string& area) {
        std::cout << nombre << " está limpiando en el área de " << area << ".\n";
    }
};


#endif //STAFF_H
