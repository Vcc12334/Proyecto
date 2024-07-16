//
// Created by raymo on 8/07/2024.
//

#include "CSV.h"
#include "Peliculas.h"
#include <fstream>
#include <sstream>
using namespace std;
unordered_map<string, Pelicula> cargarCSV(const string& nombreArchivo) {
    unordered_map<string, Pelicula> peliculas;
    ifstream archivo(nombreArchivo);

    string linea;
    while (getline(archivo, linea)) {
        istringstream stream(linea);
        string imdb_id, title, plot_synopsis, tags;
        getline(stream, imdb_id, ',');
        getline(stream, title, ',');
        getline(stream, plot_synopsis, ',');
        getline(stream, tags, ',');

        vector<string> tagList;
        istringstream tagStream(tags);
        string tag;
        while (getline(tagStream, tag, ';')) {
            tagList.push_back(tag);
        }

        peliculas[imdb_id] = Pelicula(imdb_id, title, plot_synopsis, tagList);
    }

    return peliculas;
}
