#ifndef PELICULA_H
#define PELICULA_H
#include <string>
using namespace std;

class Pelicula
{
public:
    Pelicula();
    Pelicula(string registroBD);
private:
    int idPelicula;
    string nombre;
    string genero;
    int duracion;
    string clasif;
public:
    int getIdPelicula();
    void setIdPelicula(int id);
    string getNombre();
    void setNombre(string nom);
    string getGenero();
    void setGenero(string gen);
    int getDuracion();
    void setDuracion(int dur);
    string getClasif();
    void setClasif(string cla);
    string getBDRecord();
};

#endif // PELICULA_H
