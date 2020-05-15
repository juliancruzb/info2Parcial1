#ifndef CINEMA_H
#define CINEMA_H
#include <persona.h>
#include <pelicula.h>
#include <sala.h>
#include <proyeccion.h>
#include <tools.h>
#include <iostream>
#include <map>

using namespace std;

class Cinema
{

public:
    Cinema();
    map<string, Persona> Usuarios;
    map<int, Pelicula> Peliculas;
    map<int, Sala> Salas;
    map<int, Proyeccion> Cartelera;
    void agregarUsuario(string usuario, Persona u);
    void agregarPelicula(int id, Pelicula pel);
    void agregarSala(int id, Sala sala);
    void agregarCartelera(int id, Proyeccion pro);
    void cargarConfiguracion();
    string validarUsuario(string usuario, string contrasena);
    int msgLogin();
    const string archivoUsuarios = "usuarios.txt";
    const string archivoPeliculas = "peliculas.txt";
    const string archivoSalas = "salas.txt";
    const string archivoCartelera = "cartelera.txt";
};

#endif // CINEMA_H
