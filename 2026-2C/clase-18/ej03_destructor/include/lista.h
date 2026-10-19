/* ej03_destructor · lista.h — se agrega ~Lista */
#ifndef LISTA_H
#define LISTA_H
#include "nodo.h"

class Lista
{
private:
    Nodo* m_inicio;
public:
    Lista ();
    ~Lista ();
    void crearLista ();
    void recorrerLista ();
};

#endif // LISTA_H
