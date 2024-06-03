/*
- Nombre: Marian Hernandez Charles
- Matricula: A01285878
- Carrera: ITC
- Fecha: 22 de mayo de 2024
*/

#include "Serie.h"

// Constructores
Serie::Serie() : Video() {
    cantidad = 0;
}

Serie::Serie(string _iD, string _titulo, int _duracion, string _genero, double _calificacion) : Video(_iD, _titulo, _duracion, _genero, _calificacion) {
    cantidad = 0;
}

// Duracion
void Serie::calculaDuracion() {
    int _duracion = 0;

    for (int index = 0; index < cantidad; index++) {
        _duracion += episodios[index].getTemporada();
    }

    duracion = _duracion;
}

// Modificadores
void Serie::setEpisodio(int posicion, Episodio episodio) {
    // Validar el numero de episodios
    if (posicion >= 0 && posicion < cantidad) {
        episodios[posicion] = episodio;
    }
}

void Serie::setCantidad(int _cantidad) {
    cantidad = _cantidad;
}

// Acceso
Episodio Serie::getEpisodio(int posicion) {
    Episodio epi;
    // Validacion que exista el episodio
    if (posicion >= 0 && posicion < cantidad) {
        return episodios[posicion];
    }

    // No existe, return default
    return epi;
}

int Serie::getCantidad() {
    return cantidad;
}

// Otros
double Serie::calculaPromedio() {
    double acum = 0;
    for (int index = 0; index < cantidad; index++) {
        acum += episodios[index].getCalificacion();
    }

    if (cantidad > 0) {
        return acum / cantidad;
    }

    return 0;

}

// override
string Serie::str() {
    string str = iD + ' ' + titulo + ' ' + to_string(duracion) + ' '
    + genero + ' ' + to_string(calificacion) + ' ' + to_string(cantidad);

    // str() para cada episodio en episodios
    for (int index = 0; index < cantidad; index++) {
        str = str + '\n' + episodios[index].str();
    }

    return str + '\n';
}

void Serie::agregaEpisodio(Episodio episodio) {
    // Validar que quepa otro episodio
    if (cantidad < 5) {
        episodios[cantidad++] = episodio;
    }
}