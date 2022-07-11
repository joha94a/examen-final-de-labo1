#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "funciones.h"
#include "rlutil.h"



int main(){
    srand(time(NULL));
    int opcion;

    cout << "GRAN CERDO" << endl << "______________" << endl;

    cout << "1 - JUGAR" << endl;
    cout << "2 - ESTADISTICAS" << endl;
    cout << "3 - CERDITOS" << endl << "______________" << endl;
    cout <<"0 - SALIR" << endl;

    cin >> opcion;

    switch(opcion)
    {
        case 1:
            system("cls");
            ComenzarJuego();
        break;

        case 2:
            system("cls");
            numeroAlAzar();
        break;

        case 3: ;
        break;

        case 0: ;
        break;

        default: cout << "Ingrese una opcion disponible";
        break;

    }




return 0;

}
