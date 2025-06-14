#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include "Utilidad.h"
#include "Zoo.h"
#include "Habitat.h"
#include "Animal.h"
#include "Staff.h"
#include "Consumidor.h"
#include "Eventos.h"


int main() {
    setlocale(LC_ALL, ""); // Configura el locale para caracteres especiales (ej. Ñ, tildes)

    Zoo miZoo("Zoológico", "CDMX", 8, 18);

    std::vector<Animal*> animales;
    Animal* animalSeleccionado = nullptr;

    Snack palomitas(1, "Palomitas", 50.0, 200);
    Snack refresco(2, "Refresco", 20.0, 100);

    Guia miGuia;

    int opcion;
    std::string grupoAnimal;

    while (true) {
        std::cout << "\n--- Menú Principal del Zoológico ---\n";
        std::cout << "1. Configurar datos del zoológico\n";
        std::cout << "2. Verificar si el zoológico está abierto\n";
        std::cout << "3. Ingresar un nuevo animal\n";
        std::cout << "4. Ver datos del animal seleccionado (o del último ingresado)\n";
        std::cout << "5. Gestionar snacks (ver/servir)\n";
        std::cout << "6. Ingresar datos del guía\n";
        std::cout << "7. Tomar tour con el guía\n";
        std::cout << "8. Registrar una donación\n";
        std::cout << "0. Salir\n";
        std::cout << "------------------------------------\n";
        opcion = getValidatedIntInput("Ingrese una opción: ", 0, 8); // Validate menu option

        switch (opcion) {
            case 1: {
                std::string nombreZoo = getLineInput("Ingresa el nombre del zoológico: ");
                std::string ubicacionZoo = getLineInput("Ingresa la ubicación del zoológico: ");
                int aperturaZoo = getValidatedIntInput("Ingresa la hora de apertura (0-23): ", 0, 23);
                int cierreZoo = getValidatedIntInput("Ingresa la hora de cierre (0-24): ", 0, 24);
                miZoo.setNombre(nombreZoo);
                miZoo.setUbicacion(ubicacionZoo);
                miZoo.setHorario(aperturaZoo, cierreZoo);
                std::cout << "Datos del zoológico actualizados: " << miZoo.getNombre() << "\n";
                std::cout << "Abre a las " << miZoo.getApertura() << " hrs y cierra a las " << miZoo.getCierre() << " hrs.\n";
                break;
            }
            case 2: {
                int horaActual = getValidatedIntInput("Escribe la hora actual (0-24): ", 0, 24);
                miZoo.verificar_apertura(horaActual);
                break;
            }
            case 3: {
                std::cout << "Selecciona el tipo de animal:\n";
                std::cout << "  (mamifero, ave, reptil, pez, anfibio): ";
                grupoAnimal = getWordInput("");

                Animal* nuevoAnimal = nullptr;

                if (grupoAnimal == "mamifero") {
                    nuevoAnimal = new Mamifero();
                } else if (grupoAnimal == "ave") {
                    nuevoAnimal = new Ave();
                } else if (grupoAnimal == "reptil") {
                    nuevoAnimal = new Reptil();
                } else if (grupoAnimal == "pez") {
                    nuevoAnimal = new Pez();
                } else if (grupoAnimal == "anfibio") {
                    nuevoAnimal = new Anfibio();
                } else {
                    std::cout << "Tipo de animal no válido.\n";
                    break;
                }

                if (nuevoAnimal) {
                    nuevoAnimal->ingresarDatos();
                    animales.push_back(nuevoAnimal);
                    animalSeleccionado = nuevoAnimal;
                    std::cout << "Animal ingresado con éxito.\n";
                }
                break;
            }
            case 4: {
                if (animales.empty()) {
                    std::cout << "No hay animales ingresados aún.\n";
                } else {
                    if (animales.size() > 1) {
                        std::cout << "Animales disponibles:\n";
                        for (size_t i = 0; i < animales.size(); ++i) {
                            std::cout << i + 1 << ". " << animales[i]->getNombre() << " (" << animales[i]->getEspecie() << ")\n";
                        }
                        int selection = getValidatedIntInput("Selecciona un número de animal para ver sus datos: ", 1, animales.size());
                        animalSeleccionado = animales[selection - 1];
                    } else {
                        animalSeleccionado = animales[0];
                    }

                    if (animalSeleccionado) {
                        animalSeleccionado->mostrarDatos();
                        if (Ave* ave = dynamic_cast<Ave*>(animalSeleccionado)) {
                            ave->volar();
                        } else if (Reptil* reptil = dynamic_cast<Reptil*>(animalSeleccionado)) {
                            reptil->mudar_piel();
                        } else if (Pez* pez = dynamic_cast<Pez*>(animalSeleccionado)) {
                            pez->nadar();
                        } else if (Anfibio* anfibio = dynamic_cast<Anfibio*>(animalSeleccionado)) {
                            anfibio->etapa_vida();
                        } else if (Mamifero* mamifero = dynamic_cast<Mamifero*>(animalSeleccionado)) {
                        }
                    }
                }
                break;
            }
            case 5: {
                int snackOption = getValidatedIntInput("1. Ver stock de un snack\n2. Servir snack\nIngrese opción: ", 1, 2);
                if (snackOption == 1) {
                    int snackId = getValidatedIntInput("Ingrese ID del snack (1 para Palomitas, 2 para Refresco): ", 1, 2);
                    if (snackId == 1) palomitas.ver_stock();
                    else if (snackId == 2) refresco.ver_stock();
                } else if (snackOption == 2) {
                    int snackId = getValidatedIntInput("Ingrese ID del snack a servir (1 para Palomitas, 2 para Refresco): ", 1, 2);
                    int cantidad = getValidatedIntInput("Ingrese la cantidad a servir: ", 1);
                    if (snackId == 1) palomitas.descontar_stock(cantidad);
                    else if (snackId == 2) refresco.descontar_stock(cantidad);
                }
                break;
            }
            case 6: {
                miGuia.ingresarDatos();
                std::cout << "Datos del guía registrados.\n";
                break;
            }
            case 7: {
                if (miGuia.nombre.empty()) {
                    std::cout << "Por favor, ingrese los datos del guía primero (Opción 6).\n";
                    break;
                }
                if (animales.empty()) {
                    std::cout << "No hay animales para guiar un tour aún. Ingrese un animal primero (Opción 3).\n";
                    break;
                }

                miGuia.guiar_visita();
                std::string respuestaGuia = getWordInput("¿Desea que el guía lo lleve al animal seleccionado? (si/no): ");

                if (respuestaGuia == "si") {
                    if (animalSeleccionado) {
                         miGuia.guiar_visita_a_animal(*animalSeleccionado);
                        if (animalSeleccionado->getSalud() == "saludable") {
                            std::cout << "Observa a " << animalSeleccionado->getNombre() << " en su hábitat.\n";
                        } else {
                            std::cout << animalSeleccionado->getNombre() << " se encuentra en el veterinario en este momento.\n";
                        }
                    } else {
                        std::cout << "No se ha seleccionado ningún animal. Por favor, ingrese o seleccione un animal primero.\n";
                    }
                } else {
                    std::cout << "Tour con guía finalizado.\n";
                }
                break;
            }
            case 8: {
                Donacion nuevaDonacion;
                nuevaDonacion.registrar();
                break;
            }
            case 0: {
                std::cout << "Saliendo del programa. ¡Gracias por usar el sistema del zoológico!\n";
                for (Animal* animal : animales) {
                    delete animal;
                }
                animales.clear();
                return 0;
            }
            default:
                std::cout << "Opción no válida. Por favor, intente de nuevo.\n";
                break;
        }
        std::cout << "------------------------------------\n";
    }

    return 0;
}
