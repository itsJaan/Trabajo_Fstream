//
// Created by Javier Nunez on 1/17/2019.
//

#ifndef EJERCICIO_ARCHIVOSBINARIOS_TRABAJOCLASE_TRANSACCIONES_H
#define EJERCICIO_ARCHIVOSBINARIOS_TRABAJOCLASE_TRANSACCIONES_H



struct trans{
    int n_cuenta;
    int t_transac;
    double monto_transac;
};

class transacciones {
public:
    static void agregarDeposito();
    static void agregarRetiro();
    static void consultarHisto();

};


#endif //EJERCICIO_ARCHIVOSBINARIOS_TRABAJOCLASE_TRANSACCIONES_H
