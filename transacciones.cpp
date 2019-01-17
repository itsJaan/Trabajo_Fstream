//
// Created by Javier Nunez on 1/17/2019.
//

#include "transacciones.h"
#include "cuentas.h"
#include <iostream>
#include <fstream>

using namespace std;

void transacciones::agregarDeposito() {
    ofstream transfile("Transacciones.dat", ios::app | ios::out | ios::binary);

    if(!transfile) {
        cout<<"Error al abrir archivo"<<endl;
    }

    trans nuevo;
    cout<<endl<<"\n------Depositando------\n";
    cout<<"Ingrese numero de cuenta:";
    cin>>nuevo.n_cuenta;
    nuevo.t_transac==1;
    cout<<"Ingrese monto de transacciones:";
    cin>>nuevo.monto_transac;
    cout<<"Deposito efectuado Correctamente\n";
    cout<<"-----------------------------------\n";

    transfile.seekp(0, ios::beg );
    transfile.write(reinterpret_cast<const char*>(&nuevo), sizeof(transacciones));
    transfile.close();

    cliente temporal;
    ifstream lecturaA("Maestro_Cuentas.dat", ios::in | ios::binary);
    lecturaA.seekg(0,ios::beg);
    ofstream escrituraA("Maestro_Cuentas.dat" , ios::out | ios::binary);

    lecturaA.read(reinterpret_cast<char *>(&temporal), sizeof(cliente));
    while(!lecturaA.eof()){
        if(temporal.n_cuenta==nuevo.n_cuenta){
            temporal.saldo=temporal.saldo+nuevo.monto_transac;
            escrituraA.write((char*) &temporal , sizeof(cliente));
        }
        lecturaA.read(reinterpret_cast<char *>(&temporal), sizeof(cliente));
    }
    return;
}

void transacciones::agregarRetiro() {
    ofstream transfile("Transacciones.dat", ios::app | ios::out | ios::binary);

    if(!transfile) {
        cout<<"Error al abrir archivo"<<endl;
    }

    trans nuevo;
    cout<<endl<<"\n----- Retirando ----\n";

    cout<<"Ingrese numero de cuenta:";
    cin>>nuevo.n_cuenta;
    nuevo.t_transac==2;
    cout<<"Ingrese monto de transacciones:";
    cin>>nuevo.monto_transac;
    cout<<"Retiro efectuado Correctamente\n";
    cout<<"-----------------------------------\n";


    transfile.seekp(0, ios::beg );
    transfile.write(reinterpret_cast<const char*>(&nuevo), sizeof(transacciones));
    transfile.close();

    cliente temporal;
    ifstream lecturaA("Maestro_Cuentas.dat", ios::in | ios::binary);
    lecturaA.seekg(0,ios::beg);
    ofstream escrituraA("Maestro_Cuentas.dat" , ios::out | ios::binary);

    lecturaA.read(reinterpret_cast<char *>(&temporal), sizeof(cliente));

    while(!lecturaA.eof()){
        if(temporal.n_cuenta==nuevo.n_cuenta){
            temporal.saldo=temporal.saldo-nuevo.monto_transac;
            escrituraA.write((char*) &temporal , sizeof(cliente));
        }
        lecturaA.read(reinterpret_cast<char *>(&temporal), sizeof(cliente));
    }

    return;
}

void transacciones::consultarHisto() {
    ifstream empleadoIn("Transacciones.dat", ios::in | ios::binary);

    if(!empleadoIn){
        cout<<"Error al intentar abrir el archivo"<<endl;
        return;
    }

    trans temporal;
    cout<<"-------------- Historia de transacciones --------------------\n";
    empleadoIn.seekg(0,ios::beg);
    empleadoIn.read(reinterpret_cast<char *>(&temporal), sizeof(transacciones));
    while(!empleadoIn.eof()){
        cout<<"Codigo:" << temporal.n_cuenta << "  Tipo de Transaccion:" << temporal.t_transac << "    Monto: " << temporal.monto_transac<< "\n";
        empleadoIn.read(reinterpret_cast<char *>(&temporal), sizeof(transacciones));
    }
    cout<<endl;

    empleadoIn.close();
}



