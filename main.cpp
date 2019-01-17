#include <iostream>
#include <fstream>
#include "cuentas.h"
#include "transacciones.h"
#include "cuentas.h"

using namespace std;
int opc;

int main() {
    do {
        cout << " Menu Princioal " << endl;
        cout << "1. Ingresar Cuenta" << endl;
        cout << "2. Transaccion" << endl;
        cout << "3. Consultar Historial" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese una opcion:" << endl;

        cin >> opc;
        switch (opc) {
            case 1:
                cuentas::agregarCliente();
                break;
            case 2:
                char t;
                cout<<"---------Tipo de Transaccion-------\n";
                cout<<"( D / R )   ";
                cin>>t;
                switch(t) {
                    case 'd':
                    case 'D':
                        transacciones::agregarDeposito();
                        break;
                    case'R':
                    case 'r':
                        transacciones::agregarRetiro();
                        break;
                    default:
                        cout<<"Opcion Invalida\n\n";
                        break;
                }
                break;
            case 3:
                cuentas::consultarCliente();
                cout<<"----------------------------------\n";
                transacciones::consultarHisto();
                cout<<"----------------------------------\n";
                break;
            default:
                break;
        }
    }while(opc!=0);
    return 0;
}