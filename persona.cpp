#include "persona.h"
#include "tools.h"
#include <sstream>
#include <iostream>
using namespace std;

Persona::Persona()
{
    cout << "";
}

Persona::Persona(string registroBD){
    vector<string> infoPersona = stringSplit(registroBD,'|');
    string temp;
    if (infoPersona.size() != 4) {
        throw "PER01 - El registro de base de datos esta corrupto";
    } else {
        usuario = infoPersona[0];
        nombre = infoPersona[1];
        clave = infoPersona[2];
        rol = infoPersona[3];
    }
}

string Persona::getID(){
    return usuario;
}
void Persona::setUsuario(string u){
    usuario = u;
}
string Persona::getNombre(){
    return nombre;
}
void Persona::setNombre(string n){
    nombre = n;
}
string Persona::getClave(){
    return clave;
}
void Persona::setClave(string c){
    clave = c;
}
string Persona::getRol(){
    return rol;
}
void Persona::setRol(string r){
    rol = r;
}
