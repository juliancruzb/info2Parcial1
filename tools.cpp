#include "tools.h"
#include <vector>
#include <sstream>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// Funcion para parsear un texto con un delimitador
vector<string> stringSplit(const string& texto, char delimitador) {
    vector<string> vecSplit;
    string elemento;
    istringstream sst(texto);
    while (getline(sst, elemento,delimitador)) {
        vecSplit.push_back(elemento);
    }
    return vecSplit;
}
// Funcion para cifrar o descifrar un texto
string cifrarDescifrar(string txt) {
    char key = 'J';
    string salida = txt;
    for (int i = 0; i < int(txt.size()); i++) {
        salida[i] = txt[i] ^ key;
    }
    return salida;
}

// Funcion para leer archivo
vector<string> cargarRegistros(string archivo) {
    vector<string> resultado;
    string linea;
    ifstream file;
    file.open(archivo,ios::in);
    while (!file.eof()) {
        getline(file,linea);
        resultado.push_back(linea);
    }
    file.close();
    return resultado;
}

//Funcion para escribir archivo
void escribirArchivo(vector <string> info, string fileToWrite) {
    ofstream file;
    file.open(fileToWrite,ios::in);
    if (file.is_open()) {
        for (string linea : info) {
            file << linea <<"\n";
        }
    } else {
        throw "Se presento un error escribiendo archivo";
    }
}
