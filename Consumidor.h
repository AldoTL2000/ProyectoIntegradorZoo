//
// Created by aldot on 6/10/2025.
//

#ifndef CONSUMIDOR_H
#define CONSUMIDOR_H
#include <iostream>
#include <vector>
#include <string>

class Visitante {
public:
    int id, edad;
    std::string nombre;

    Visitante(int id = 0, int edad = 0, std::string nombre = "Visitante Anónimo")
        : id(id), edad(edad), nombre(nombre) {}

    void comprar_boleto() {
        std::cout << nombre << " ha comprado un boleto.\n";
    }

    void recorrer() {
        std::cout << nombre << " está recorriendo el zoológico.\n";
    }
};

class Boleto {
public:
    int id;
    std::string tipo;
    double precio;

    Boleto(int id = 0, std::string tipo = "General", double precio = 0.0)
        : id(id), tipo(tipo), precio(precio) {}

    void validar() {
        std::cout << "El boleto ha sido validado.\n";
    }
};


class Producto {
public:
    int id;
    std::string nombre;
    double precio;
    int stock;

    Producto(int id = 0, std::string nombre = "Sin Nombre", double precio = 0.0, int stock = 0)
        : id(id), nombre(nombre), precio(precio), stock(stock) {}

    void descontar_stock(int cantidad) {
        if (stock >= cantidad) {
            stock -= cantidad;
            std::cout << "Se han descontado " << cantidad << " unidades de " << nombre << ". Stock restante: " << stock << "\n";
        } else {
            std::cout << "No hay suficiente stock de " << nombre << ". Stock actual: " << stock << "\n";
        }
    }
    void ver_stock() const {
        if (stock > 0) {
            std::cout << "Hay " << stock << " unidades de " << nombre << " disponibles.\n";
        } else {
            std::cout << "¡No hay stock de " << nombre << "!\n";
        }
    }
};

class Snack : public Producto {
public:
    Snack(int id = 0, std::string nombre = "Snack generico", double precio = 0.0, int stock = 0)
        : Producto(id, nombre, precio, stock) {}
};

class ComidaAnimal : public Producto {
public:
    ComidaAnimal(int id = 0, std::string nombre = "Comida para animales", double precio = 0.0, int stock = 0)
        : Producto(id, nombre, precio, stock) {}
};

class Tienda {
public:
    std::string nombre;
    std::vector<Producto> inventario;

    Tienda(std::string name = "Tienda del Zoo") : nombre(name) {}

    void agregar_producto(const Producto& producto) {
        inventario.push_back(producto);
        std::cout << producto.nombre << " añadido al inventario de la tienda " << nombre << ".\n";
    }

    void vender_producto(int producto_id, int cantidad) {
        for (auto& p : inventario) {
            if (p.id == producto_id) {
                p.descontar_stock(cantidad);
                return;
            }
        }
        std::cout << "Producto con ID " << producto_id << " no encontrado en la tienda " << nombre << ".\n";
    }
};


#endif //CONSUMIDOR_H
