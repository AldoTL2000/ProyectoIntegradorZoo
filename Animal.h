//
// Created by aldot on 6/10/2025.
//

#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
#include <iostream>
#include "Utilidad.h"


class Animal {
protected:
    int id;
    int edad;
    std::string nombre;
    std::string especie;
    std::string salud;

public:
    Animal() : id(0), edad(0), nombre("Desconocido"), especie("Desconocida"), salud("Desconocido") {}

    Animal(int id, int edad, const std::string& nombre, const std::string& especie, const std::string& salud)
        : id(id), edad(edad), nombre(nombre), especie(especie), salud(salud) {}

    virtual ~Animal() = default;

    virtual void ingresarDatos() {
        nombre = getLineInput("Ingresa el nombre del animal: ");
        especie = getLineInput("Ingresa la especie: ");
        id = getValidatedIntInput("Ingresa el ID del animal: ", 1);
        edad = getValidatedIntInput("Ingresa la edad en años: ", 0);
        salud = getWordInput("Ingresa el estado de salud del animal (saludable/enfermo): ");
    }

    virtual void mostrarDatos() const {
        std::cout << "\n--- Datos del Animal ---\n";
        std::cout << "Nombre: " << nombre << "\n";
        std::cout << "Especie: " << especie << "\n";
        std::cout << "ID: " << id << "\n";
        std::cout << "Edad: " << edad << " años\n";
        std::cout << "Salud: " << salud << "\n";
    }

    std::string getSalud() const {
        return salud;
    }
    std::string getNombre() const {
        return nombre;
    }
    std::string getEspecie() const {
        return especie;
    }

    void alimentar() {
        std::cout << nombre << " está siendo alimentado.\n";
    }

    void mover() {
        std::cout << nombre << " está moviéndose.\n";
    }
};

class Mamifero : public Animal {
private:
    int periodo_gestacion;
    std::string pelaje;

public:
    Mamifero() : Animal(), periodo_gestacion(0), pelaje("Desconocido") {}

    Mamifero(int id, int edad, const std::string& nombre, const std::string& especie, const std::string& salud,
             int gestacion, const std::string& pelaje)
        : Animal(id, edad, nombre, especie, salud),
          periodo_gestacion(gestacion), pelaje(pelaje) {}

    void ingresarDatos() override {
        Animal::ingresarDatos();
        pelaje = getWordInput("Ingresa el tipo de pelaje (corto/medio/largo): ");
        periodo_gestacion = getValidatedIntInput("Ingresa el periodo de gestación en meses: ", 1);
    }

    void mostrarDatos() const override {
        Animal::mostrarDatos();
        std::cout << "Pelaje: " << pelaje << "\n";
        std::cout << "Periodo de gestación: " << periodo_gestacion << " meses\n";
    }

    void amamantar() {
        std::cout << nombre << " está amamantando a sus crías.\n";
    }
};

class Ave : public Animal {
public:
    std::string tipo_plumas;
    bool capacidad_de_volar;

    Ave() : Animal(), tipo_plumas("Desconocido"), capacidad_de_volar(true) {}

    Ave(int id, int edad, const std::string& nombre, const std::string& especie, const std::string& salud,
        const std::string& tipo_plumas, bool capacidad_volar)
        : Animal(id, edad, nombre, especie, salud),
          tipo_plumas(tipo_plumas), capacidad_de_volar(capacidad_volar) {}

    void ingresarDatos() override {
        Animal::ingresarDatos();
        tipo_plumas = getLineInput("Ingresa el tipo de plumas: ");
        capacidad_de_volar = (getValidatedIntInput("¿Puede volar? (1 para sí / 0 para no): ", 0, 1) == 1);
    }

    void mostrarDatos() const override {
        Animal::mostrarDatos();
        std::cout << "Tipo de plumas: " << tipo_plumas << "\n";
        std::cout << "Capacidad de volar: " << (capacidad_de_volar ? "Sí" : "No") << "\n";
    }

    void volar() {
        if (capacidad_de_volar) {
            std::cout << nombre << " está volando.\n";
        } else {
            std::cout << nombre << " no puede volar.\n";
        }
    }
};

class Reptil : public Animal {
public:
    double temperatura_cuerpo;
    std::string tipo_escamas;

    Reptil() : Animal(), temperatura_cuerpo(0.0), tipo_escamas("Desconocido") {}

    Reptil(int id, int edad, const std::string& nombre, const std::string& especie, const std::string& salud,
           double temp_cuerpo, const std::string& tipo_escamas)
        : Animal(id, edad, nombre, especie, salud),
          temperatura_cuerpo(temp_cuerpo), tipo_escamas(tipo_escamas) {}

    void ingresarDatos() override {
        Animal::ingresarDatos();
        temperatura_cuerpo = getValidatedIntInput("Ingresa la temperatura en grados Celsius: ", -50, 100); // sensible range
        tipo_escamas = getLineInput("Ingresa el tipo de escamas: ");
    }

    void mostrarDatos() const override {
        Animal::mostrarDatos();
        std::cout << "Temperatura del cuerpo: " << temperatura_cuerpo << "°C\n";
        std::cout << "Tipo de escamas: " << tipo_escamas << "\n";
    }

    void mudar_piel() {
        std::cout << nombre << " está mudando su piel.\n";
    }
};

class Pez : public Animal {
public:
    std::string tipo_agua;

    Pez() : Animal(), tipo_agua("Desconocido") {}

    Pez(int id, int edad, const std::string& nombre, const std::string& especie, const std::string& salud,
        const std::string& tipo_agua)
        : Animal(id, edad, nombre, especie, salud),
          tipo_agua(tipo_agua) {}

    void ingresarDatos() override {
        Animal::ingresarDatos();
        tipo_agua = getWordInput("Ingresa el tipo de agua del pez (dulce/salada): ");
    }

    void mostrarDatos() const override {
        Animal::mostrarDatos();
        std::cout << "Tipo de agua: " << tipo_agua << "\n";
    }

    void nadar() {
        if (tipo_agua == "salada") {
            std::cout << nombre << " está en un tanque de agua salada.\n";
        } else if (tipo_agua == "dulce") {
            std::cout << nombre << " está en un tanque de agua dulce.\n";
        } else {
            std::cout << nombre << " está nadando en su hábitat.\n";
        }
    }
};

class Anfibio : public Animal {
public:
    int periodo_renacuajo_meses;

    Anfibio() : Animal(), periodo_renacuajo_meses(0) {}

    Anfibio(int id, int edad, const std::string& nombre, const std::string& especie, const std::string& salud,
            int periodo_renacuajo)
        : Animal(id, edad, nombre, especie, salud),
          periodo_renacuajo_meses(periodo_renacuajo) {}

    void ingresarDatos() override {
        Animal::ingresarDatos();
        periodo_renacuajo_meses = getValidatedIntInput("Ingresa cuántos meses dura el animal en etapa de renacuajo: ", 0);
    }

    void mostrarDatos() const override {
        Animal::mostrarDatos();
        std::cout << "Tiempo en etapa de renacuajo: " << periodo_renacuajo_meses << " meses\n";
    }

    void etapa_vida() {
        std::cout << "El anfibio " << nombre << " se encuentra en una etapa de crecimiento o metamorfosis.\n";
    }
};


#endif //ANIMAL_H
