/* ej02_crear_recorrer · main.cpp — crear y recorrer; los nodos quedan en el heap al terminar (sin destructor) */
#include <iostream>
#include "lista.h"

int main ()
{
    Lista lista;
    lista.crearLista ();
    lista.recorrerLista ();        // en que orden salen?
    return 0;
}
