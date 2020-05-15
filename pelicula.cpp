#include "pelicula.h"
#include <sstream>
#include <vector>
#include "tools.h"

using namespace std;
//Constructor por defecto
Pelicula::Pelicula()
{

}
//Constructor a partir de registro de base de datos
Pelicula::Pelicula(string registroBD){
    vector<string> infoPelicula = stringSplit(registroBD,'|');
    string temp;
    if (infoPelicula.size() != 5) {
        throw "PEL01 - El registro de base de datos esta corrupto";
    } else {
        idPelicula = stoi(infoPelicula[0]);
        nombre = infoPelicula[1];
        genero = infoPelicula[2];
        duracion = stoi(infoPelicula[3]);
        clasif = infoPelicula[4];
    }
}
// Función para obtener el id de la pelicula
int Pelicula::getIdPelicula() {
    return idPelicula;
}
// Función para configurar el id de la pelicula
void Pelicula::setIdPelicula(int id) {
    idPelicula = id;
    return;
}
// Función para obtener el nombre de la pelicula
string Pelicula::getNombre() {
    return nombre;
}
// Función para configurar el nombre de la pelicula
void Pelicula::setNombre(string nom) {
    nombre = nom;
}
// Función para obtener el genero de la pelicula
string Pelicula::getGenero() {
    return genero;
}
// Función para configurar el genero de la pelicula
void Pelicula::setGenero(string gen) {
    genero = gen;
    return;
}
// Función para obtener la duracion de la pelicula
int Pelicula::getDuracion() {
    return duracion;
}
// Función para configurar la duracion de la pelicula
void Pelicula::setDuracion(int dur) {
    duracion = dur;
    return;
}
// Función para obtener la clasificacion de la pelicula
string Pelicula::getClasif() {
    return clasif;
}
// Función para configurar la clasificación de la pelicula
void Pelicula::setClasif(string cla) {
    clasif = cla;
}
// Funcion para obtener el registro en base de datos de la pelicula
string Pelicula::getDBRecord() {
    //Variables locales
    string recordPelicula = "";
    recordPelicula.append(to_string(idPelicula));
    recordPelicula.append("|");
    recordPelicula.append(nombre);
    recordPelicula.append("|");
    recordPelicula.append(genero);
    recordPelicula.append("|");
    recordPelicula.append(to_string(duracion));
    recordPelicula.append("|");
    recordPelicula.append(clasif);
    return recordPelicula;
}
