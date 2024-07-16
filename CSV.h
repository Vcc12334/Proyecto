//
// Created by raymo on 8/07/2024.
//

#ifndef TAREA_CSV_H
#define TAREA_CSV_H

#pragma once
#include <unordered_map>
#include "Peliculas.h"

unordered_map<string, Pelicula> cargarCSV(const string& nombreArchivo);


#endif //TAREA_CSV_H
