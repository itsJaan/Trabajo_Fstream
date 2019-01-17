//
// Created by Javier Nunez on 1/17/2019.
//

#ifndef EJERCICIO_ARCHIVOSBINARIOS_TRABAJOCLASE_CUENTAS_H
#define EJERCICIO_ARCHIVOSBINARIOS_TRABAJOCLASE_CUENTAS_H

struct cliente{
    int n_cuenta;
    char nombre[20];
    double saldo;
};

class cuentas {
public:
    static void agregarCliente();
    static void consultarCliente();
};


#endif //EJERCICIO_ARCHIVOSBINARIOS_TRABAJOCLASE_CUENTAS_H
