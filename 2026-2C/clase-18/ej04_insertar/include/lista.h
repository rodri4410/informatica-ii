/* ej04_insertar · lista.h — insertarPrimero, getUltimo (nullptr si vacia) e insertarUltimo */
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
    void insertarPrimero (int);
    Nodo* getUltimo ();
    void insertarUltimo (int);
};

#endif // LISTA_H
