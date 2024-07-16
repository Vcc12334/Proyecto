#include "Buscador.h"
#include <algorithm>
#include <string>
#include "Peliculas.h"
using namespace std;
vector<Pelicula> buscarPeliculas(const unordered_map<string, Pelicula>& peliculas, const string& query) {
    vector<Pelicula> resultados;

    for (const auto& par : peliculas) {
        const Pelicula& pelicula = par.second;

        string titulo = pelicula.title;
        string queryLower = query;
        transform(titulo.begin(), titulo.end(), titulo.begin(), ::tolower);
        transform(queryLower.begin(), queryLower.end(), queryLower.begin(), ::tolower);

        if (titulo.find(queryLower) != string::npos) {
            resultados.push_back(pelicula);
        }
    }

    return resultados;
}

vector<Pelicula> buscarPorTag(const unordered_map<string, Pelicula>& peliculas, const string& tag) {
    vector<Pelicula> resultados;

    for (const auto& par : peliculas) {
        const Pelicula& pelicula = par.second;

        if (find(pelicula.tags.begin(), pelicula.tags.end(), tag) != pelicula.tags.end()) {
            resultados.push_back(pelicula);
        }
    }

    return resultados;
}

vector<Pelicula> buscarSimilares(const Pelicula& pelicula, const unordered_map<string, Pelicula>& peliculas) {
    vector<Pelicula> similares;

    for (const auto& par : peliculas) {
        const Pelicula& p = par.second;

        if (p.imdb_id != pelicula.imdb_id) {
            for (const auto& tag : pelicula.tags) {
                if (find(p.tags.begin(), p.tags.end(), tag) != p.tags.end()) {
                    similares.push_back(p);
                    break;
                }
            }
        }
    }

    return similares;
}
