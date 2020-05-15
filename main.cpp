#include <iostream>
#include <vector>
#include <sstream>
#include <tools.h>
#include <cinema.h>
#include <persona.h>

using namespace std;



int main()
{
    /*
     * TESTING
     */

    for (string celda : cargarRegistros("red1.txt")) {
      cout << celda << " ; ";
    }
    cout << endl << "Fin del programa" << endl;
    return 0;
}


