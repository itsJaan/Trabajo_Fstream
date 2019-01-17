//
// Created by Javier Nunez on 1/15/2019.
//
#include <iostream>
#include <fstream>
#include "transaccion.h"
#include "clientes.h"

using namespace std;

void trans:: Depositar(){

    transaccion nuevoT;
    clientes temporal;

    cout<<"Ingrese codigo:";
    cin>>nuevoT.n_cuenta;
    nuevoT.t_trans==1;
    cout<<"Ingrese monto:";
    cin>>nuevoT.monto_trans;


    ofstream archivo("Transacciones.dat" , ios::out | ios::binary);
    if(!archivo){
        cout<<"Error ocurrido al abrir el archivo"<<endl;
        return;
    }
    archivo.seekp(0, ios::beg);
    archivo.write((char*) &nuevoT , sizeof(transaccion));
    archivo.close();

    ifstream lecturaA("Maestro_Cuentas.dat", ios::in | ios::binary);
    lecturaA.seekg(0,ios::beg);
    lecturaA.read(reinterpret_cast<char *>(&temporal), sizeof(clientes));
    while(!lecturaA.eof()){
        if(temporal.n_cuenta==nuevoT.n_cuenta){
            ofstream escrituraB("Maestro_Cuentas.dat" , ios::out | ios::binary);
            //escrituraB.seekp();
            temporal.saldo=temporal.saldo+nuevoT.monto_trans;
            escrituraB.write((char*) &temporal , sizeof(clientes));
        }
        lecturaA.read(reinterpret_cast<char *>(&temporal), sizeof(clientes));
    }
}
void trans:: Retirar(){

    transaccion nuevoT;
    clientes temporal;
    cout<<"Ingrese codigo:";
    cin>>nuevoT.n_cuenta;
    nuevoT.t_trans==2;
    cout<<"Ingrese monto:";
    cin>>nuevoT.monto_trans;


    ofstream archivo("Transacciones.dat" , ios::out | ios::binary);
    if(!archivo){
        cout<<"Error ocurrido al abrir el archivo"<<endl;
        return;
    }
    archivo.seekp(0, ios::beg);
    archivo.write((char*) &nuevoT , sizeof(transaccion));
    archivo.close();

    ifstream lecturaA("Maestro_Cuentas.dat", ios::in | ios::binary);
    lecturaA.seekg(0,ios::beg);
    lecturaA.read(reinterpret_cast<char *>(&temporal), sizeof(clientes));
    while(!lecturaA.eof()){
        if(temporal.n_cuenta==nuevoT.n_cuenta){
            ofstream escrituraB("Maestro_Cuentas.dat" , ios::out | ios::binary);
            //escrituraB.seekp();
            temporal.saldo=temporal.saldo-nuevoT.monto_trans;
            escrituraB.write((char*) &temporal , sizeof(clientes));
        }
        lecturaA.read(reinterpret_cast<char *>(&temporal), sizeof(clientes));
    }
}