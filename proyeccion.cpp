#include "proyeccion.h"
#include <vector>
#include "tools.h"

Proyeccion::Proyeccion()
{

}
Proyeccion::Proyeccion(string registroBD){
    vector<string> infoProyeccion = stringSplit(registroBD,'|');
    string temp;
    if (infoProyeccion.size() != 5) {
        throw "PRO01 - El registro de base de datos esta corrupto";
    } else {
        idProyeccion = stoi(infoProyeccion[0]);
        idPelicula = stoi(infoProyeccion[1]);
        idSala = stoi(infoProyeccion[2]);
        horaInicio = stoi(infoProyeccion[3]);
        horaFinal = stoi(infoProyeccion[4]);
    }
}

int Proyeccion::getIdProyeccion() {
    return idProyeccion;
}
int Proyeccion::getIdPelicula(){
    return idPelicula;
}
void Proyeccion::setIdPelicula(int idPel){
    idPelicula = idPel;
}
int Proyeccion::getHoraInicio(){
    return horaInicio;
}
void Proyeccion::setHoraInicio(int horaIni){
    horaInicio = horaIni;
}
int Proyeccion::getHoraFinal(){
    return horaFinal;
}
void Proyeccion::setIdProyeccion(int idPro){
    idProyeccion = idPro;
}
