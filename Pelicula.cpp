/*
- Nombre: Marian Hernandez Charles
- Matricula: A01285878
- Carrera: ITC
- Fecha: 22 de mayo de 2024
*/

#include "Pelicula.h"

// Constructores
Pelicula::Pelicula() : Video() {
    oscares = 100;
}

Pelicula::Pelicula(string _iD, string _titulo, int _duracion, string _genero, double _calificacion, int _oscares) : Video(_iD, _titulo, _duracion, _genero, _calificacion) {
    oscares = _oscares;
}

// Modificadores
void Pelicula::setOscares(int _oscares) {
    oscares = _oscares;
}

// Acceso
int Pelicula::getOscares() {
    return oscares;
}

// Otros
string Pelicula::str() {
    return iD + ' ' + titulo + ' ' + to_string(duracion) + ' '
    + genero + ' ' + to_string(calificacion) + ' ' + to_string(oscares);
}