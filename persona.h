#ifndef PERSONA_H
#define PERSONA_H
#include <string>

using namespace std;

class Persona
{
public:
    Persona();
    Persona(string registroBD);
private:
    string usuario;
    string nombre;
    string clave;
    string rol;
public:
    string getUsuario();
    void setUsuario(string u);
    string getNombre();
    void setNombre(string n);
    string getClave();
    void setClave(string c);
    string getRol();
    void setRol(string r);
};

#endif // PERSONA_H
