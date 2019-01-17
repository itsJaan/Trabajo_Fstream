//
// Created by Javier Nunez on 1/15/2019.
//

#ifndef EJERCICIOCLASE_S1_FSTREAM_TRANSACCION_H
#define EJERCICIOCLASE_S1_FSTREAM_TRANSACCION_H

struct transaccion{
    int n_cuenta;
    int t_trans;
    double monto_trans;
};
class trans {
public:
    static void Depositar();
    static void Retirar();
};
#endif //EJERCICIOCLASE_S1_FSTREAM_TRANSACCION_H
