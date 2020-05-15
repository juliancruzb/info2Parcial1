#include "proyeccion.h"
#include <vector>
#include "tools.h"

Proyeccion::Proyeccion()
{

}
Proyeccion::Proyeccion(string registroBD){
    vector<string> infoProyeccion = stringSplit(registroBD,'|');
    string temp;
    if (infoProyeccion.size() != 6) {
        throw "PRO01 - El registro de base de datos esta corrupto";
    } else {
        idProyeccion = stoi(infoProyeccion[0]);
        idPelicula = stoi(infoProyeccion[1]);
        idSala = stoi(infoProyeccion[2]);
        horaInicio = stoi(infoProyeccion[3]);
        horaFinal = stoi(infoProyeccion[4]);
        aforo = stoi(infoProyeccion[5]);
    }
}

int Proyeccion::getIdProyeccion() {
    return idProyeccion;
}
int Proyeccion::getIdPelicula(){
    return idPelicula;
}
int Proyeccion::getIdSala(){
    return idSala;
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
int  Proyeccion::getDisp(){
    return aforo;
}
string Proyeccion::getBDRecord() {
    string record = "";
    record.append(to_string(idProyeccion));
    record.append("|");
    record.append(to_string(idPelicula));
    record.append("|");
    record.append(to_string(idSala));
    record.append("|");
    record.append(to_string(horaInicio));
    record.append("|");
    record.append(to_string(horaFinal));
    return record;
}
