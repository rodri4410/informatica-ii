/* ej07_lista_ordenada · listaordenada.h — ListaOrd: lo reutilizable de Lista + insertarOrdenado */
#ifndef LISTAORDENADA_H
#define LISTAORDENADA_H
#include "nodo.h"

class ListaOrd
{
private:
    Nodo* m_inicio;
public:
    ListaOrd ();
    ~ListaOrd ();
    void recorrerLista ();
    Nodo* getUltimo ();
    Nodo* buscarNodo (int);
    void borrarNodo (int);
    void borrarOcurrencias (int);
    void insertarOrdenado (int);
};

#endif // LISTAORDENADA_H
