#include <iostream>
#include <fstream>
#include "cuentas.h"
#include "transaccion.h"

using namespace std;


int main() {

    char numCuenta[4];
    int menu;
    int y;

    cuentas cuenta;
    do {
        cout << "---Menu---" << endl;
        cout << "1.Ingresar nueva Cuenta\n";
        cout << "2.Depositar ó Retirar\n";
        cout << "3.Resumen de Cuentas\n";
        cout << "0.Salir\n";
        cin >> menu;

        switch (menu) {
            case 1:
                cuenta.crear_cuenta();
                break;
            case 2:
                cout << "1.D \n2.R\n";
                cin >> y;
                if(y==1)
                    trans::Depositar();
                else
                    trans::Retirar();
                break;
            case 3:
                cuenta.imprimir_resumen_cuentas();
                //cuenta.imprimir_resumen_trans();
                break;
            case 0:
                exit(0);

            default:
                cout << "Opcion Invalida.";
                break;

        }
    }while(menu!=0);
}

