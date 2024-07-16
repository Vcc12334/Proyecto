//
// Created by raymo on 8/07/2024.
//

#ifndef TAREA_BUSCADOR_H
#define TAREA_BUSCADOR_H
#pragma once
#include <vector>
#include <unordered_map>
#include "Peliculas.h"

std::vector<Pelicula> buscarPeliculas(const std::unordered_map<std::string, Pelicula>& peliculas, const std::string& query);
std::vector<Pelicula> buscarPorTag(const std::unordered_map<std::string, Pelicula>& peliculas, const std::string& tag);
std::vector<Pelicula> buscarSimilares(const Pelicula& pelicula, const std::unordered_map<std::string, Pelicula>& peliculas);

#endif //TAREA_BUSCADOR_H
