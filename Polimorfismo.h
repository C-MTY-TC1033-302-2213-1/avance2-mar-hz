/*
- Nombre: Marian Hernandez Charles
- Matricula: A01285878
- Carrera: ITC
- Fecha: 26 de mayo de 2024
- ¿Qué aprendí en el desarrollo de esta clase?: Aprendi como se ve la utilidad del polimorfismo con el str() de
arreglo de Videos, y aprendi a leer de un archivo csv
*/

#ifndef Polimorfismo_h
#define Polimorfismo_h

#include <typeinfo>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Pelicula.h"
#include "Serie.h"
#include "Episodio.h"
#include <stdio.h>

using namespace std;

const int MAX_VIDEOS = 100;

class Polimorfismo {
private:
    Video *arrPtrVideos[MAX_VIDEOS];
    int cantidad;
public:
    // Constructor
    Polimorfismo();

    // Modificadores
    void setPtrVideo(int index, Video *video);
    void setCantidad(int _cantidad);

    // Acceso
    Video* getPtrVideo(int index);
    int getCantidad();

    // Otros metodos
    void leerArchivo(string _nombre);
    void reporteInventario();
    void reporteCalificacion(double _calificacion);
    void reporteGenero(string _genero);
    void reportePeliculas();
    void reporteSeries();
};

#endif