/*
- Nombre: Marian Hernandez Charles
- Matricula: A01285878
- Carrera: ITC
- Fecha: 22 de mayo de 2024
*/

#include "Video.h"

// Constructores
Video::Video() {
    iD = "A01285878";
    titulo = "Marian Hernandez";
    duracion = 40;
    genero = "Educacion";
    calificacion = 100.0;
}

Video::Video(string _iD, string _titulo, int _duracion, string _genero, double _calificacion) {
    iD = _iD;
    titulo = _titulo;
    duracion = _duracion;
    genero = _genero;
    calificacion = _calificacion;
}

// Modificadores
void Video::setID(string _ID) {
    iD = _ID;
}

void Video::setTitulo(string _titulo) {
    titulo = _titulo;
}

void Video::setDuracion(int _duracion) {
    duracion = _duracion;
}

void Video::setGenero(string _genero) {
    genero = _genero;
}

void Video::setCalificacion(double _calificacion) {
    calificacion = _calificacion;
}

// Acceso
string Video::getID() {
    return iD;
}

string Video::getTitulo() {
    return titulo;
}

int Video::getDuracion() {
    return duracion;
}

string Video::getGenero() {
    return genero;
}

double Video::getCalificacion() {
    return calificacion;
}

// Otros
string Video::str() {
    return iD + ' ' + titulo + ' ' + to_string(duracion) + ' '
    + genero + ' ' + to_string(calificacion);
}