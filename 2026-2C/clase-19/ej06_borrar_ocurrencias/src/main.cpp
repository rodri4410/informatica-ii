/* ej06_borrar_ocurrencias · main.cpp — borrarOcurrencias: recorre hasta el final */
#include <iostream>
#include "lista.h"

int main ()
{
    Lista lista;
    lista.insertarUltimo (12);
    lista.insertarUltimo (-13);
    lista.insertarUltimo (12);
    lista.insertarUltimo (12);
    lista.insertarUltimo (23);
    lista.insertarUltimo (12);
    lista.recorrerLista ();
    lista.borrarOcurrencias (12);     // primero, consecutivos y ultimo
    lista.recorrerLista ();
    lista.borrarOcurrencias (12);     // ya no hay: aviso
    lista.borrarOcurrencias (-13);    // el primero y unico de su valor
    lista.borrarOcurrencias (23);     // el unico nodo que queda: la lista queda vacia
    lista.recorrerLista ();
    lista.borrarOcurrencias (1);      // lista vacia: el while no entra, aviso
    return 0;
}
