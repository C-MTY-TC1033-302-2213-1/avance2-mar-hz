/*
- Nombre: Marian Hernandez Charles
- Matricula: A01285878
- Carrera: ITC
- Fecha: 22 de mayo de 2024
- ¿Qué aprendí en el desarrollo de esta clase?: Aprendi la conveniencia de tener codigo ordenado y
    metodos claros cuando tuve que cambiar un tipo de dato y fue facil encontrar todas las instancias
*/

#ifndef Episodio_hpp
#define Episodio_hpp

#include <stdio.h>
#include <string>

using namespace std;

class Episodio {
private:
    string titulo;
    int temporada;
    int calificacion;
public:
    // Constructores
    Episodio();
    Episodio(string _titulo, int _temporada, int _calificacion);

    // Modificadores
    void setTitulo(string _titulo);
    void setTemporada(int _temporada);
    void setCalificacion(int _calificacion);

    // Acceso
    string getTitulo();
    int getTemporada();
    int getCalificacion();

    // Otros metodos
    string str();
};

#endif