#include "tools.h"
#include <vector>
#include <sstream>
#include <string>
using namespace std;

vector<string> stringSplit(const string& texto, char delimitador) {
    vector<string> vecSplit;
    string elemento;
    istringstream sst(texto);
    while (getline(sst, elemento,delimitador)) {
        vecSplit.push_back(elemento);
    }
    return vecSplit;
};
