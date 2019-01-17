//
// Created by Javier Nunez on 1/15/2019.
//

#include "cuentas.h"
#include <fstream>
#include <iostream>

using namespace std;


void cuentas::crear_cuenta() {
    //valor nulo
    float v=0;

    clientes nuevo;

    cout<<"Ingrese codigo:";
    cin>>nuevo.n_cuenta;
    cout<<"Ingrese nombre:";
    cin>>nuevo.nombre;

    nuevo.saldo=v;

    ofstream archivo("Transacciones", ios::out | ios::binary);
    if(!archivo){
        cout<<"Error ocurrido al abrir el archivo"<<endl;
        return;
    }
    archivo.seekp(0, ios::beg);
    archivo.write((char*) &nuevo , sizeof(clientes));
    cout<<"Se creo Correctamente\n";

    return;
}

void cuentas::imprimir_resumen_cuentas() {

    ifstream archivoA ("Maestro_Cuentas.dat", ios::in|ios::binary);
    clientes temporal;

    if(!archivoA){
        cout<<"Error al intentar abrir el archivo"<<endl;
        return;
    }
    cout<<endl<<"*Clientes Registrados *\n";
    archivoA.seekg(0,ios::beg);
    archivoA.read(reinterpret_cast<char *>(&temporal), sizeof(clientes));
    while(!archivoA.eof()){
        cout<<"codigo:" << temporal.n_cuenta << ", Nombre:" << temporal.nombre << ", Saldo: " << temporal.saldo<< "\n";
        archivoA.read(reinterpret_cast<char *>(&temporal), sizeof(clientes));
    }
    archivoA.close();
    return;

}
void cuentas::imprimir_resumen_trans() {

    ifstream archivoB ("Transacciones.dat", ios::in|ios::binary);
    transaccion temporalT;

    if(!archivoB){
        cout<<"Error al intentar abrir el archivo"<<endl;
        return;
    }

    cout << endl << "* Historial de Transacciones *\n";
    archivoB.seekg(0, ios::beg);
    archivoB.read(reinterpret_cast<char *>(&temporalT), sizeof(transaccion));
    while (!archivoB.eof()) {
        cout << "codigo:" << temporalT.n_cuenta << ", Tipo:" << temporalT.t_trans << ", Monto: "
             << temporalT.monto_trans <<"\n";
        archivoB.read(reinterpret_cast<char *>(&temporalT), sizeof(transaccion));
    }
    archivoB.close();
    return;
}