#include <iostream>
#include <vector>
#include <sstream>
#include <tools.h>

using namespace std;

int main()
{
    for (string celda : stringSplit("Abollonada $12000&100&Preferencial $15000&20&",'&')) {
        cout << celda << " ; ";
    }
    cout << endl << "Fin del programa" << endl;
    return 0;
}


