/* ej05_lista · main.cpp — los casos de las slides: vacia, primero, medio, ultimo, no encontrado */
#include <iostream>
#include "lista.h"

int main ()
{
    Lista lista;
    lista.insertarAntes (1, 5);        // lista vacia: aviso por cerr
    lista.insertarUltimo (-13);
    lista.insertarUltimo (2);
    lista.insertarUltimo (12);
    lista.insertarUltimo (23);
    lista.insertarAntes (46, 12);      // en el medio: el ejemplo del mazo
    lista.insertarAntes (0, -13);      // el objetivo es el primero: delega en insertarPrimero
    lista.insertarAntes (7, 100);      // no esta: aviso
    lista.recorrerLista ();

    Nodo* p = lista.buscarNodo (12);   // devuelve la direccion del nodo, o nullptr
    if (p != nullptr)
        std::cout << "Encontrado: " << p->getDato () << '\n';
    p = lista.buscarNodo (100);
    if (p == nullptr)
        std::cout << "El 100 no esta" << '\n';

    lista.insertarDespues (99, 23);    // despues del ultimo: no es un caso especial
    lista.insertarDespues (7, 100);    // no esta: aviso
    lista.recorrerLista ();

    lista.borrarNodo (46);             // en el medio
    lista.borrarNodo (0);              // el primero
    lista.borrarNodo (99);             // el ultimo
    lista.borrarNodo (100);            // no esta: aviso
    lista.recorrerLista ();

    Lista vacia;
    vacia.borrarNodo (5);              // lista vacia: aviso
    return 0;
}
