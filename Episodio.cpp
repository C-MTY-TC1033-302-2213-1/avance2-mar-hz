/*
- Nombre: Marian Hernandez Charles
- Matricula: A01285878
- Carrera: ITC
- Fecha: 22 de mayo de 2024
*/

#include "Episodio.h"

// Constructores
Episodio::Episodio() {
    titulo = "Episodio Default";
    temporada = 1;
    calificacion = 5;
}

Episodio::Episodio(string _titulo, int _temporada, int _calificacion) {
    titulo = _titulo;
    temporada = _temporada;
    calificacion = _calificacion;
}

// Modificadores
void Episodio::setTitulo(string _titulo) {
    titulo = _titulo;
}

void Episodio::setTemporada(int _temporada) {
    temporada = _temporada;
}

void Episodio::setCalificacion(int _calificacion) {
    calificacion = _calificacion;
}

// Acceso
string Episodio::getTitulo() {
    return titulo;
}

int Episodio::getTemporada() {
    return temporada;
}

int Episodio::getCalificacion() {
    return calificacion;
}

// Otros metodos
string Episodio::str() {
    return titulo + ' ' + to_string(temporada) + ' ' + to_string(calificacion);
}