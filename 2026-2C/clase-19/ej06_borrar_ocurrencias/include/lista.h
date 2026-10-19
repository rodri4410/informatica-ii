/* ej06_borrar_ocurrencias · lista.h — borrarOcurrencias: recorre hasta el final */
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
    void insertarAntes (int, int);
    Nodo* buscarNodo (int);
    void insertarDespues (int, int);
    void borrarNodo (int);
    void borrarOcurrencias (int);
};

#endif // LISTA_H
