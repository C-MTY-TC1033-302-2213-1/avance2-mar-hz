/*
- Nombre: Marian Hernandez Charles
- Matricula: A01285878
- Carrera: ITC
- Fecha: 22 de mayo de 2024
- ¿Qué aprendí en el desarrollo de esta clase?: Aprendi mejor el funcionamiento de los constructores y pude
    practicar los atributos protected en las clases derivadas de esta
*/

#ifndef Video_h
#define Video_h

#include <stdio.h>
#include <string>

using namespace std;

class Video {
protected:
    string iD;
    string titulo;
    int duracion;
    string genero;
    double calificacion;
public:
    // Constructores
    Video();
    Video(string _iD, string _titulo, int _duracion, string _genero, double _calificacion);

    // Modificadores
    void setID(string _iD);
    void setTitulo(string _titulo);
    void setDuracion(int _duracion);
    void setGenero(string _genero);
    void setCalificacion(double _calificacion);

    // Acceso
    string getID();
    string getTitulo();
    int getDuracion();
    string getGenero();
    double getCalificacion();

    // Otros
    virtual string str();
};

#endif