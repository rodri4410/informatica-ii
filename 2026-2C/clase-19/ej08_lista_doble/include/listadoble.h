/* ej08_lista_doble · listadoble.h — lista doblemente enlazada: cada operacion mantiene los dos enlaces */
#ifndef LISTADOBLE_H
#define LISTADOBLE_H
#include "nododoble.h"

class ListaDoble
{
private:
    NodoDoble* m_inicio;
public:
    ListaDoble ();
    ~ListaDoble ();
    void insertarPrimero (int);
    NodoDoble* buscarPorPosicion (int);   // 0 es el primero
    void insertarDespues (NodoDoble*, int);
    void recorrerLista ();
    void eliminarNodo (NodoDoble*);
};

#endif // LISTADOBLE_H
