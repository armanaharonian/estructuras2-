#pragma once
#include <iostream>
#include <assert.h>



int hashFunc( string clave, int tam ) {
    int suma = 0;
    for (int i = 0; i < clave.length(); i++) {
        suma += clave[i] * (i + 1);
    }
    return suma % tam;
}

    

