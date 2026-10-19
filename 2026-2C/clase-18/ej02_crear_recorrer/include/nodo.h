/* ej02_crear_recorrer · nodo.h — Nodo con dos constructores y los getters */
#ifndef NODO_H
#define NODO_H

class Nodo
{
private:
    int m_dato;
    Nodo* m_sig;
public:
    Nodo (int);
    Nodo (int, Nodo*);
    Nodo* getSig ();
    int getDato ();
};

#endif // NODO_H
