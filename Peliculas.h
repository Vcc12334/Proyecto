//
// Created by raymo on 8/07/2024.
//


#ifndef TAREA_PELICULAS_H
#define TAREA_PELICULAS_H
#pragma once
#include <string>
#include <vector>
using namespace std;
class Pelicula {
public:
    string imdb_id;
    string title;
    string plot_synopsis;
    vector<std::string> tags;

    Pelicula(const string &id, const string &title, const string &synopsis, const vector<std::string> &tags) {}
    Pelicula(){}

};




#endif //TAREA_PELICULAS_H
