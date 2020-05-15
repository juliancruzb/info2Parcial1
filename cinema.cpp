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

Pelicula Cinema::obtenerPelicula(int id) {
    map<int,Pelicula>::iterator it;
    // Se valida que exista
    it = Peliculas.find(id);
    if (it != Peliculas.end()) {
        //Si ya existe
        return it->second;
    } else {
        Pelicula noResul;
        return noResul;
    }
}

string Cinema::validarUsuario(string usuario, string contrasena) {
    map<string,Persona>::iterator it;
    string tempo;

    // Se valida que exista
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
    vector <string> tempo2;

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
    Ventas.clear();
    tempo = cargarRegistros(archivoVentas);
    for (string a : tempo) {
        tempo2 = stringSplit(a,'|');
        Ventas.insert(pair<int,string>(stoi(tempo2[0]),tempo2[2]));
    }
}

void Cinema::guardarConfiguracion() {
    vector <string> tempo;
    vector <string> tempo2;
    for(auto elemento : Usuarios){
        //tempo.push_back(elemento.second.getBDRecord());
    }
    escribirArchivo(tempo,archivoUsuarios);
    tempo.erase(tempo.begin(),tempo.end());

    for(auto elemento : Salas){
        //tempo.push_back(elemento.second.getBDRecord());
    }
    escribirArchivo(tempo,archivoSalas);
    tempo.erase(tempo.begin(),tempo.end());

    for(auto elemento : Peliculas){
        //tempo.push_back(elemento.second.getBDRecord());
    }
    escribirArchivo(tempo,archivoPeliculas);
    tempo.erase(tempo.begin(),tempo.end());

    for(auto elemento : Cartelera){
        //tempo.push_back(elemento.second.getBDRecord());
    }
    escribirArchivo(tempo,archivoCartelera);
    tempo.erase(tempo.begin(),tempo.end());

    for(auto elemento : Ventas){
        //tempo.push_back(elemento.second.getBDRecord());
    }
    escribirArchivo(tempo,archivoVentas);
    tempo.erase(tempo.begin(),tempo.end());

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
        sesion.usuario = usuario;

        tempo = tempo.erase(0,3);
        sesion.rol = tempo;
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

int Cinema::optUsuario() {
    int opt=0;
    Pelicula infoPeli;
    cout << "\t" << "*********   CARTELERA   *********" << endl << endl;
    for(auto element : Cartelera) {
        if (element.second.getDisp()>0) {
            cout << "\t";
            cout << element.first;
            cout << "\t\t";
            infoPeli = obtenerPelicula(element.second.getIdPelicula());
            if (infoPeli.getIdPelicula()==0) continue;
            cout << infoPeli.getNombre();
            cout << "\t\t";
            cout << infoPeli.getGenero();
            cout << "\t\t";
            cout << infoPeli.getDuracion();
            cout << "\t\t";
            cout << element.second.getIdSala();
            cout << "\t\t";
            cout << element.second.getHoraInicio();
            cout << "\t\t";
            cout << infoPeli.getClasif();
            cout << "\t\t";
            cout << element.second.getDisp();
            cout << endl;
        }
    }
    cout << "\tSeleccione una opcion: ";
    cin >> opt;
    return opt;
}

int Cinema::mostrarPelicula(int idProy) {
    map<int,Proyeccion>::iterator it;
    Sala infoSala;
    string silla;
    string sillaElegida;
    bool venta=false;
    vector <string> sillaVendidas;
    vector <string> sillaDisponibles;
    // Se valida que exista
    it = Cartelera.find(idProy);
    if (it != Cartelera.end()) {
        for (auto venta : Ventas) {
            if (venta.first == idProy)
                sillaVendidas.push_back(venta.second);
        }
        //Si ya existe
        string letras[12] = {"A","B","C","D","E","F","G","H","I","J","K","L"};
        string numeros[12] = {"01","02","03","04","05","06","07","08","09","10","11","12"};
        for (int i=0;i<12;i++) {
            for (int j=0;j<12;j++) {
                silla = string(letras[i]) + string(numeros[j]);
                for (string vendida : sillaVendidas) {
                    if (silla.compare(vendida)==0) {
                        venta = true;
                        break;
                    }
                }
                if (venta) {
                    cout << "   " << "  ";
                    venta = false;
                } else {
                    cout << silla << "  ";
                    sillaDisponibles.push_back(silla);
                }
            }
        }
        cout << endl << endl;
        cout <<"\tDigita el codigo de la silla para comprar: ";
        cin >> sillaElegida;
        // TODO: Validar Silla Elegida;
        Ventas.insert(pair<int,string>(idProy,sillaElegida));
    } else {
        cout << "La pelicula escogida no existe, verifica bien el id de la izquierda." << endl;
        system("PAUSE");
    }
    return 1;
}
