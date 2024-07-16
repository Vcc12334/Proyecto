#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "Peliculas.h"
#include "CSV.h"
#include "Buscador.h"


std::unordered_map<std::string, Pelicula> peliculasLike;
std::unordered_map<std::string, Pelicula> peliculasVerMasTarde;

void agregarLike(const Pelicula& pelicula) {
    peliculasLike[pelicula.imdb_id] = pelicula;
}

void agregarVerMasTarde(const Pelicula& pelicula) {
    peliculasVerMasTarde[pelicula.imdb_id] = pelicula;
}


void mostrarPeliculas( std::unordered_map<std::string, Pelicula>::iterator inicio, std::unordered_map<std::string, Pelicula>::iterator final ){
    for (auto it = inicio; it!= final; ++it) {
        std::cout <<  it->second.title << " (" << it->second.imdb_id << ")\n";
    }
}
void mostrarPeliculas( std::vector<Pelicula>::iterator inicio, std::vector<Pelicula>::iterator final ){
    for (auto it = inicio; it!= final; ++it) {
        std::cout << it->title << " (" << it->imdb_id << ")\n";
    }
}

int main() {
    std::unordered_map<std::string, Pelicula> peliculas = cargarCSV("mpst_full_data.csv");

    std::cout << "Administrador de Peliculas\n";
    std::cout << "Lista de 5 Peliculas Anhadidas a (Ver mas tarde):\n\n";

    mostrarPeliculas(peliculasVerMasTarde.begin(), peliculasVerMasTarde.end());

    std::string opcion1;
    int opcion1_int;
    do {
        std::cout << "LISTA DE ACCIONES A REALIZAR:\n";
        std::cout << "1-Buscar Pelicula\n2-Entrar en Lista de Ver mas tarde\n3-Salir\n";
        std::cout << "Escriba la Opcion a Escoger: ";
        std::cin >> opcion1;
        opcion1_int = std::stoi(opcion1);

        if (opcion1_int > 3 || opcion1_int < 1) {
            std::cout << "Valor incorrecto\n";
        } else if (opcion1_int == 1) {
            std::string query;
            std::cout << "Ingrese el nombre o tag de la pelicula: ";
            std::cin >> query;

            std::vector<Pelicula> resultados = buscarPeliculas(peliculas, query);
            if (resultados.empty()) {
                resultados = buscarPorTag(peliculas, query);
            }

            mostrarPeliculas(resultados.begin(),resultados.end());
        } else if (opcion1_int == 2) {
            mostrarPeliculas(peliculasVerMasTarde.begin(), peliculasVerMasTarde.end());
        } else if (opcion1_int == 3) {
            std::cout << "Adios...\n";
            break;
        }
    } while (true);

    return 0;
}