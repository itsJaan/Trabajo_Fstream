//
// Created by Javier Nunez on 1/15/2019.
//

#ifndef EJERCICIOCLASE_S1_FSTREAM_CUENTAS_H
#define EJERCICIOCLASE_S1_FSTREAM_CUENTAS_H
#include "clientes.h"
#include "transaccion.h"

class cuentas {
public:
    void crear_cuenta();
    //bool existe_cuenta(int cod);
    void imprimir_resumen_cuentas();
    void imprimir_resumen_trans();

};


#endif //EJERCICIOCLASE_S1_FSTREAM_CUENTAS_H
