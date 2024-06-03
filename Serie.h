/*
- Nombre: Marian Hernandez Charles
- Matricula: A01285878
- Carrera: ITC
- Fecha: 22 de mayo de 2024
- ¿Qué aprendí en el desarrollo de esta clase?: Aprendi a aplicar los arreglos de objetos como atributos y tambien
    la sintaxis de la herencia mejor
*/

#ifndef Serie_h
#define Serie_h

#include "Video.h"
#include "Episodio.h"

using namespace std;

class Serie : public Video {
private:
    Episodio episodios[5];
    int cantidad;
public:
    // Constructores
    Serie();
    Serie(string _iD, string _titulo, int _duracion, string _genero, double _calificacion);

    // Duracion
    void calculaDuracion();

    // Modificadores
    void setEpisodio(int posicion, Episodio episodio);
    void setCantidad(int _cantidad);

    // Acceso
    Episodio getEpisodio(int posicion);
    int getCantidad();

    // Otros
    double calculaPromedio();
    string str();
    void agregaEpisodio(Episodio episodio);

};

#endif