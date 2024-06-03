/*
- Nombre: Marian Hernandez Charles
- Matricula: A01285878
- Carrera: ITC
- Fecha: 22 de mayo de 2024
- ¿Qué aprendí en el desarrollo de esta clase?: Aprendi a aplicar la sintaxis de los constructores con herencia 
    por mi cuenta y a interpretar mejor los diagramas uml de clases
*/

#ifndef Pelicula_h
#define Pelicula_h

#include "Video.h"

using namespace std;

class Pelicula : public Video {
private:
    int oscares;
public:
    // Constructores
    Pelicula();
    Pelicula(string _iD, string _titulo, int _duracion, string _genero, double _calificacion, int _oscares);

    // Modificadores
    void setOscares(int _oscares);

    // Acceso
    int getOscares();

    // Otros
    string str();
};

#endif
