/* ej08_lista_doble · main.cpp — NodoDoble y ListaDoble */
#include <iostream>
#include "listadoble.h"

int main ()
{
    ListaDoble lista;
    lista.recorrerLista ();                    // vacia: solo el encabezado
    lista.insertarPrimero (23);
    lista.insertarPrimero (12);
    lista.insertarPrimero (2);
    lista.insertarPrimero (-13);
    lista.recorrerLista ();

    NodoDoble* n = lista.buscarPorPosicion (1);       // el nodo en la posicion 1 (el 2)
    lista.insertarDespues (n, 666);
    lista.recorrerLista ();

    lista.eliminarNodo (lista.buscarPorPosicion (2)); // el 666
    lista.eliminarNodo (lista.buscarPorPosicion (0)); // el primero
    lista.recorrerLista ();
    lista.eliminarNodo (lista.buscarPorPosicion (9)); // no existe: aviso
    return 0;
}
