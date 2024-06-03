/*
- Nombre: Marian Hernandez Charles
- Matricula: A01285878
- Carrera: ITC
- Fecha: 26 de mayo de 2024
*/

#include "Polimorfismo.h"

// Constructor
Polimorfismo::Polimorfismo() {
    for (int index = 0; index < MAX_VIDEOS; index++) {
        arrPtrVideos[index] = nullptr;
    }

    // Cantidad de videos
    cantidad = 0;
}

// Modificadores
void Polimorfismo::setPtrVideo(int index, Video *video) {
    // validar que el index exista
    if (index >= 0 && index < cantidad) {
        arrPtrVideos[index] = video;
    }
}

void Polimorfismo::setCantidad(int _cantidad) {
    // Verificar que cantidad este entre 0 y MAX_VIDEOS-1, si no NO se modifica

    // Validacion de _cantidad
    if (_cantidad > 0 && _cantidad <= MAX_VIDEOS) {
        cantidad = _cantidad;
    }
}

// Acceso
Video* Polimorfismo::getPtrVideo(int index) {
    // Validar que el index existe
    if (index > 0 && index < cantidad) {
        return arrPtrVideos[index];
    }

    // Si no existe
    return nullptr;
}

int Polimorfismo::getCantidad() {
    return cantidad;
}

// Otros metodos
// Leer archivo
void Polimorfismo::leerArchivo(string _nombre) {
    // Declaraciones
    Serie *arrPtrSeries[50];
    Pelicula *arrPtrPeliculas[50];
    Episodio ep;
    fstream entrada;
    string row[7];
    string line, word;
    int cantidadPelis = 0;
    int cantidadSeries = 0;
    int iR = 0, index, stop;
    double promedio;

    entrada.open(_nombre, ios::in);

    while(getline(entrada, line)) {
        stringstream st(line);
        iR = 0;

        while (getline(st, word, ',')) {
            row[iR++] = word;
        }

        if(row[0] == "P") {
            // Agregar pointer con new al lugar de cantidad de peliculas en el arreglo pointers pelicula
            // Despues incrementa cantidad
            arrPtrPeliculas[cantidadPelis++] = new Pelicula(row[1], row[2], stoi(row[3]), row[4], stod(row[5]), stoi(row[6]));
        } else if (row[0] == "S") {
            // Agregar pointer con new al lugar de cantidad de series en el arreglo pointers serie
            // Despues incrementa cantidad
            arrPtrSeries[cantidadSeries++] = new Serie(row[1], row[2], stoi(row[3]), row[4], stod(row[5]));
        } else if (row[0] == "E") {
            // Calcular index de serie a la que pertenece
            index = stoi(row[1]) - 500;
            // Agregar episodio a la serie en el index calculado
            // Creado como pointer a episodio y obtenemos su valor con el operador indireccion
            arrPtrSeries[index] -> agregaEpisodio(*(new Episodio(row[2], stoi(row[3]), stoi(row[4]))));
        }
    }

    // Pasar todos los pointers serie y pointers pelicula al arrPtrVideos
    for (int index = 0; index < cantidadSeries; index++) {
        // Calcular calificacion de la serie
        promedio = arrPtrSeries[index] -> calculaPromedio();
        // Asignar promedio a calificacion
        arrPtrSeries[index] -> setCalificacion(promedio);
        // Calcular duracion de serie
        arrPtrSeries[index] -> calculaDuracion();

        // Agregar serie a arrPtrVideos e incrementar cantidad de videos
        arrPtrVideos[cantidad++] = arrPtrSeries[index];
    }

    for (int index = 0; index < cantidadPelis; index++) {
        // Agregar pelicula a arrPtrVideos e incrementar cantidad de videos
        arrPtrVideos[cantidad++] = arrPtrPeliculas[index];
    }

    /*
    // Desplegar contenido del archivo con str() virtual -> polimorfismo!!
    for (int index = 0; index < cantidad; index++) {
        cout << index << " " << arrPtrVideos[index] -> str() << endl;
    }
    */

    entrada.close();
}

/* reporteInventario
Despliega todas las series y peliculas
Al final numero de cantidad en existencia
Peliculas = #
Series = #
*/
void Polimorfismo::reporteInventario() {
    // Declarar variables
    int countPeliculas, countSeries;

    // Inicializacion
    countPeliculas = 0;
    countSeries = 0;

    // Recorrer todo el arreglo
    for (int index = 0; index < cantidad; index++) {
        cout << arrPtrVideos[index] -> str() << endl;

        // Indireccion con pointer genera el objeto
        if (typeid(*arrPtrVideos[index]) == typeid(Pelicula)) {
            countPeliculas++;
        } else if (typeid(*arrPtrVideos[index]) == typeid(Serie)) {
            countSeries++;
        }
    }

    // Al terminar el for, desplegar la cuenta
    cout << "Peliculas = " << countPeliculas << endl;
    cout << "Series = " << countSeries << endl;
}

/* reporteCalificacion
Despliega todos series y peliculas con la calificacion indicada en parametro de entrada
Al final despliega cantidad total que cumplio
Total = #
*/
void Polimorfismo::reporteCalificacion(double _calificacion) {
    // Contador total
    int total;

    // Inicializar
    total = 0;

    for(int index = 0; index < cantidad; index++) {
        // Verificar si su calificacion == _calificacion
        if (arrPtrVideos[index] -> getCalificacion() == _calificacion) {
            cout << arrPtrVideos[index] -> str() << endl;
            total++;
        }
    }

    // Desplegar cantidad total fuera del for
    cout << "Total = " << total << endl;
}

/*
Despliega la información de todas las Series y Peliculas que
tienen el genero indicado en el parámetro de entrada,
al final despliega la cantidad que cumplio (ver casos de prueba).
Total = ##
*/
void Polimorfismo::reporteGenero(string _genero) {
    int total;
    // Inicializar
    total = 0;

    for(int index = 0; index < cantidad; index++) {
        // Verificar si su genero == _genero
        if (arrPtrVideos[index] -> getGenero() == _genero) {
            cout << arrPtrVideos[index] -> str() << endl;
            total++;
        }
    }

    // Desplegar cantidad total fuera del for
    cout << "Total = " << total << endl;
}

/*
Despliega la información de todas las Peliculas que existan en el arreglo,
al final despliega la cantidad en existencia.
Total Peliculas = ##
en caso de que no existan peliculas debe
desplegar No peliculas con salto de línea al final(ver casos de prueba)
*/
void Polimorfismo::reportePeliculas() {
    int total;
    // Inicializar
    total = 0;

    for(int index = 0; index < cantidad; index++) {
        // Verificar si el tipo de puntero es de pelicula
        if (typeid(*arrPtrVideos[index]) == typeid(Pelicula)) {
            cout << arrPtrVideos[index] -> str() << endl;
            total++;
        }
    }

    // Desplegar cantidad total fuera del for
    if (total > 0) {
        cout << "Total Peliculas = " << total << endl;
    } else {
        cout << "No peliculas" << endl;
    }
}

/*
Despliega todos las Series que existan en el arreglo,
al final despliega la cantidad en existencia.
Total Series = ##
en caso de que no existan Series debe
desplegar No series con salto de línea al final
*/
void Polimorfismo::reporteSeries() {
    int total;
    // Inicializar
    total = 0;

    for(int index = 0; index < cantidad; index++) {
        // Verificar si el tipo de puntero es de tipo serie
        if (typeid(*arrPtrVideos[index]) == typeid(Serie)) {
            cout << arrPtrVideos[index] -> str() << endl;
            total++;
        }
    }

    // Desplegar cantidad total fuera del for
    if (total > 0) {
        cout << "Total Series = " << total << endl;
    } else {
        cout << "No series" << endl;
    }
}