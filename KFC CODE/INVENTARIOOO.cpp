#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include "extraertxt.h"

using namespace std;

int main(){
	int opcion;

    cout << "\n==================================================="
         << "\n| \t BIENVENIDO AL SISTEMA DE KFC             |"
         << "\n==================================================="
         << endl;
    cout << "\n==================================================="<< endl,
    cout << "| 1. Venta de Producto                            |" <<
    endl << "| 2. Agregar Nuevo Producto                       |"<<
    endl << "| 3. Mostrar inventario                           |"<<
    endl << "| 4. Facturacion                                  |";
    cout << "\n==================================================="<< endl,
    cout << "OPCION: ";
    cin >> opcion;
    cout << endl;



    	switch (opcion)
        {
            case 1:
                mostrarmenu();
                venta();

                break;

            case 2:

                //agregarProducto ();
                break;

            case 3:
                mostrarinventario();

                break;
            case 4:
                //facturacion;
                break;
            default:
                cout << "\n\nOPCION NO VALIDA" << endl;
                break;
        }

    return 0;
}



