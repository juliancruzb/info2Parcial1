#include "cinema.h"
#include <string>
#include <tools.h>

Cinema::Cinema()
{
    cargarConfiguracion();
}
void Cinema::agregarUsuario(string usuario, Persona u) {
    Usuarios[usuario] = u;
}
void Cinema::agregarPelicula(int id, Pelicula pel){
    Peliculas[id]=pel;
}
void Cinema::agregarSala(int id, Sala sala){
    Salas[id]=sala;
}
void Cinema::agregarCartelera(int id, Proyeccion pro) {
    Cartelera[id]=pro;
}
string Cinema::validarUsuario(string usuario, string contrasena) {
    map<string,Persona>::iterator it;
    string tempo;
    // Se valida que exista esa relación
    it = Usuarios.find(usuario);
    if (it != Usuarios.end()) {
        //Si ya existe
        tempo = it->second.getClave();
        tempo = cifrarDescifrar(tempo);
        if (contrasena.compare(tempo) == 0) {
            return "OK_"+it->second.getRol();
        } else {
            return "Autenticacion fallida";
        }
    }
    return "No tenemos registro de este usuario, valide la informacion";
}

void Cinema::cargarConfiguracion() {
    vector <string> tempo;

    Usuarios.clear();
    tempo = cargarRegistros(archivoUsuarios);
    for (string a : tempo) {
        Persona p(a);
        Usuarios[p.getID()]=p;
    }
    Salas.clear();
    tempo = cargarRegistros(archivoSalas);
    for (string a : tempo) {
        Sala s(a);
        Salas[s.getIdSala()]=s;;
    }
    Peliculas.clear();
    tempo = cargarRegistros(archivoPeliculas);
    for (string a : tempo) {
        Pelicula pel(a);
        Peliculas[pel.getIdPelicula()] = pel;
    }
    Cartelera.clear();
    tempo = cargarRegistros(archivoCartelera);
    for (string a : tempo) {
        Proyeccion pro(a);
        Cartelera[pro.getIdProyeccion()]=pro;
    }
    Usuarios.clear();
    tempo = cargarRegistros(archivoUsuarios);
    for (string a : tempo) {
        Persona p(a);
        Usuarios[p.getID()]=p;
    }
}

int Cinema::msgLogin() {
    string usuario, clave, tempo="";
    cout << "\t" << "*********   BIENVENIDO AL SISTEMA   *********" << endl;
    cout << "\t" << "*********  DE ADMON SALAS DE CINE   *********" << endl << endl;
    cout << "\tUsuario: ";
    cin >> usuario;
    cout << "\t2Clave: ";
    cin >> clave;
    tempo = validarUsuario(usuario,clave);
    if(tempo.substr(0,3).compare("OK_") == 0) {
        tempo = tempo.erase(0,3);
        if (tempo.compare("USER")==0) {
            return 0;
        } else {
            return 1;
        }
    } else {
        cout << endl << tempo;
        system("PAUSE");
        return -1;
    }
}
        cout << "\t5. Mostrar camino eficiente de paquete" << endl;
        cout << "\t6. Cargar configuracion de red" << endl;
        cout << "\t7. Generar red aleatoria" << endl;
        cout << "\t0. Salir" << endl << endl;
        cout << "\tSeleccione una opcion: ";
        cin >> opt;
        return opt;
    }
}
