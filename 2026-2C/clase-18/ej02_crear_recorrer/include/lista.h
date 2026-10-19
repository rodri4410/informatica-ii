/* ej02_crear_recorrer · lista.h — Lista con crearLista y recorrerLista; todavia sin destructor */
#ifndef LISTA_H
#define LISTA_H
#include "nodo.h"

class Lista
{
private:
    Nodo* m_inicio;
public:
    Lista ();
    void crearLista ();
    void recorrerLista ();
};

#endif // LISTA_H
