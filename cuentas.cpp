//
// Created by Javier Nunez on 1/17/2019.
//

#include "cuentas.h"
#include <fstream>
#include <iostream>
using namespace std;



void cuentas::agregarCliente() {
    ofstream binaryfile("Maestro_Cuentas.dat", ios::app | ios::out | ios::binary);

    if(!binaryfile) {
        cout<<"Error al abrir archivo"<<endl;
    }

    cliente nuevo;
    cout<<endl<<"--- Ingresando Cuenta ---\n";
    cout<<"Ingrese codigo:";
    cin>>nuevo.n_cuenta;
    cout<<"Ingrese nombre:";
    cin>>nuevo.nombre;
    cout<<"Se ingreso cuenta correctamente\n";
    cout<<"-----------------------------------\n\n";
    nuevo.saldo = 0;

    binaryfile.seekp(0, ios::end );
    binaryfile.write(reinterpret_cast<const char*>(&nuevo), sizeof(cliente));
    binaryfile.close();
}

void cuentas::consultarCliente() {
    ifstream empleadoIn("Maestro_Cuentas.dat", ios::in | ios::binary);
    if(!empleadoIn){
        cout<<"Error al intentar abrir el archivo Empleados.dat"<<endl;
        return;
    }

    cliente temporal;
    cout<<"--------------------Clientes Activos-----------------------------\n";
    empleadoIn.seekg(0,ios::beg);
    empleadoIn.read(reinterpret_cast<char *>(&temporal), sizeof(cliente));
    while(!empleadoIn.eof()){
        cout<<"Codigo:" << temporal.n_cuenta << "  Nombre:" << temporal.nombre << "    Saldo: " << temporal.saldo<< "\n";
        empleadoIn.read(reinterpret_cast<char *>(&temporal), sizeof(cliente));
    }
    empleadoIn.close();
}
