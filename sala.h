#ifndef SALA_H
#define SALA_H
#include <map>
#include <string>
#include <tools.h>
using namespace std;

class Sala
{
public:
    Sala();
    Sala(string recordBD);
private:
    int idSala;
    int capacidad;
    map<string, int> distribucion;
    int sillasxLinea = 12;
    int maxSillasLinea = 20;
public:
    int getIdSala();
    void setIdSala(int id);
    int getCapacidad();
    void setCapacidad(int cap);
    void updateDistrib(string categoria, int capacidad);
    map<string,int> getDistrib();
    int getSillasLinea();
    string getBDRegistro();
private:
    void setSillasLinea(int sxl);
};

#endif // SALA_H
