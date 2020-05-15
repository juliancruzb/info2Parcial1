#include "sala.h"
#include "tools.h"
#include <iostream>
#include <sstream>

using namespace std;

// Constructor por defecto
Sala::Sala()
{

}
//Constructor a partir del registro de BD
Sala::Sala(string registroBD) {
    vector<string> infoSala = stringSplit(registroBD,'|');
    vector<string> infoDist;
    string temp;
    if (infoSala.size() != 5) {
        throw "SAL01 - El registro de base de datos esta corrupto";
    } else {
        //Se valida el vector de distribucion
        infoDist = stringSplit(infoSala[4],'&');
        if (!(infoDist.size()%2 == 0)) {
            throw "SAL02 - El registro de base de datos esta corrupto";
        } else {
            idSala = stoi(infoSala[0]);
            capacidad = stoi(infoSala[1]);
            sillasxLinea = stoi(infoSala[2]);
            maxSillasLinea = stoi(infoSala[3]);
            bool iterador = false;
            for (auto dist : infoDist) {
                if (iterador) {
                    distribucion[temp] = stoi(dist);
                }
                temp = dist;
                iterador = !iterador;
            }
        }
    }
}
// Funcion para obtener el id de la sala
int Sala::getIdSala() {
    return idSala;
}
// Funcion para configurar el id de la sala
void Sala::setIdSala(int id) {
    idSala = id;
    return;
}
// Funcion para obtener la capacidad de la sala
int Sala::getCapacidad() {
    return capacidad;
}
// Funcion para configurar la capacidad de la sala
void Sala::setCapacidad(int cap) {
    capacidad = cap;
    return;
}
// Funcion para actualizar la distribucion de categorias
void Sala::updateDistrib(string categoria, int capacidad) {
    /*
     * TODO: Por terminar
     * - Validar que la categoria exista
     * - Validar que la actualizacion no supere la capacidad
     */
    cout << "Parametros ingresados " << categoria << " , " << capacidad <<endl;
}
// Funcion para obtener la distribucion de la sala.
map<string,int> Sala::getDistrib() {
    return distribucion;
}
int Sala::getSillasLinea() {
    return sillasxLinea;
}
string Sala::getBDRecord() {
    //Variables locales
    string recordSala = "";
    string recordDistr = "";
    //Antes de construir el registro procesamos las distribuciones
    for (auto element : getDistrib()) {
        recordDistr.append(element.first);
        recordDistr.append("&");
        recordDistr.append(to_string(element.second));
        recordDistr.append("&");
    }
    //Se construye el registro de base de datos.
    recordSala.append(to_string(idSala));
    recordSala.append("|");
    recordSala.append(to_string(capacidad));
    recordSala.append("|");
    recordSala.append(to_string(sillasxLinea));
    recordSala.append("|");
    recordSala.append(to_string(maxSillasLinea));
    recordSala.append("|");
    recordSala.append(recordDistr);
    return recordSala;
}
void Sala::setSillasLinea(int sxl) {
    sillasxLinea = sxl;
    return;
}
