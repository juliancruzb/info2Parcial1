#ifndef TOOLS_H
#define TOOLS_H
#include <vector>
using namespace std;
vector<string> stringSplit(const string& texto, char delimitador);
string cifrarDescifrar(string txt);
vector<string> cargarRegistros(string a);
void escribirArchivo(vector <string>, string file);
#endif // TOOLS_H
