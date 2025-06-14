//
// Created by aldot on 6/10/2025.
//

#ifndef ZOO_H
#define ZOO_H
#include <string>
#include <iostream>

class Zoo {
private:
    std::string nombre;
    std::string ubicacion;
    int apertura;
    int cierre;

public:
    Zoo(std::string nombre = "Zoo", std::string ubicacion = "Desconocida", int apertura = 8, int cierre = 18)
        : nombre(nombre), ubicacion(ubicacion), apertura(apertura), cierre(cierre) {}

    void setNombre(const std::string& newNombre) {
        nombre = newNombre;
    }

    void setUbicacion(const std::string& newUbicacion) {
        ubicacion = newUbicacion;
    }

    void setHorario(int newApertura, int newCierre) {
        if (newApertura >= 0 && newApertura <= 23 && newCierre >= 0 && newCierre <= 24 && newApertura < newCierre) {
            apertura = newApertura;
            cierre = newCierre;
        } else {
            std::cout << "La hora de apertura debe ser menor a la de cierre y debe estar entre 0-24.\n";
        }
    }

    std::string getNombre() const {
        return nombre;
    }

    std::string getUbicacion() const {
        return ubicacion;
    }

    int getApertura() const {
        return apertura;
    }

    int getCierre() const {
        return cierre;
    }

    void verificar_apertura(int horaActual) const {
        if (horaActual >= apertura && horaActual < cierre) {
            std::cout << "El zoológico '" << nombre << "' está abierto en este momento!\n";
        } else {
            std::cout << "El zoológico '" << nombre << "' está cerrado en este momento.\n";
        }
    }
};



#endif //ZOO_H
