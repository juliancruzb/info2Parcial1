#include <iostream>
#include <vector>
#include <sstream>
#include <tools.h>
#include <cinema.h>
#include <persona.h>

using namespace std;



int main()
{
    // Inicializa elementos
    Cinema cine;
    cine.cargarConfiguracion();
    int option = -1; // Opción seleccionada
    while (option < 0) {
        system("CLS");
        // Mostrar en pantalla menu de opciones
        option = cine.msgLogin();
    }
    // Es usuario
    if (option == 0) {
        int optPeli = cine.optUsuario();
        cine.mostrarPelicula(optPeli);
    }

    return 0;
}


