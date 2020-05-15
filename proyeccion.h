#ifndef PROYECCION_H
#define PROYECCION_H
#include <string>

using namespace std;

class Proyeccion
{
public:
    Proyeccion();
    Proyeccion(string registroBD);
private:
    int idProyeccion;
    int idPelicula;
    int idSala;
    int horaInicio;
    int horaFinal;
public:
    int     getIdProyeccion();
    int     getIdPelicula();
    void    setIdPelicula(int idPel);
    int     getHoraInicio();
    void    setHoraInicio(int horaIni);
    int     getHoraFinal();
private:
    void    setIdProyeccion(int idPro);

};

#endif // PROYECCION_H
