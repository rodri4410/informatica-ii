/* ej08_lista_doble · listadoble.cpp — cada operacion mantiene los dos enlaces (m_sig y m_ant) */
#include <iostream>
#include "listadoble.h"

ListaDoble::ListaDoble ()
{
    m_inicio = nullptr;
}

ListaDoble::~ListaDoble ()
{
    NodoDoble* p = m_inicio;
    while (p != nullptr)
    {
        NodoDoble* sig = p->getSig ();
        delete p;
        p = sig;
    }
}

void ListaDoble::insertarPrimero (int dato)
{
    //paso 1
    NodoDoble* nuevo = new NodoDoble (dato);
    //paso 2: el nuevo apunta al primero; el primero (si existe) apunta atras al nuevo
    nuevo->setSig (m_inicio);
    if (m_inicio != nullptr)
        m_inicio->setAnt (nuevo);
    //paso 3
    m_inicio = nuevo;
}

NodoDoble* ListaDoble::buscarPorPosicion (int pos)
{
    int i {};
    for (NodoDoble* p = m_inicio ; p != nullptr ; p = p->getSig ())
    {
        if (pos == i)
            return p;
        i++;
    }
    return nullptr;
}

void ListaDoble::insertarDespues (NodoDoble* N, int dato)
{
    if (N == nullptr)
    {
        std::cerr << "insertarDespues: el nodo objetivo no existe" << '\n';
        return;
    }
    //paso 1
    NodoDoble* nuevo = new NodoDoble (dato);
    //paso 2: el nuevo apunta al siguiente de N; el siguiente de N (si existe) apunta atras al nuevo
    nuevo->setSig (N->getSig ());
    if (N->getSig () != nullptr)
        N->getSig ()->setAnt (nuevo);
    //paso 3: N apunta al nuevo, y el nuevo apunta atras a N
    N->setSig (nuevo);
    nuevo->setAnt (N);
}

void ListaDoble::recorrerLista ()                 // identico al de Lista: el enlace m_ant no se usa
{
    std::cout << "Recorriendo lista: " << '\n';
    for (NodoDoble* p = m_inicio ; p != nullptr ; p = p->getSig ())
        std::cout << p->getDato () << '\n';
}

void ListaDoble::eliminarNodo (NodoDoble* killme)
{
    if (killme == nullptr)
    {
        std::cerr << "eliminarNodo: el nodo no existe" << '\n';
        return;
    }
    if (m_inicio == killme)                           // era el primero
    {
        m_inicio = killme->getSig ();
        if (killme->getSig () != nullptr)
            killme->getSig ()->setAnt (nullptr);
    }
    else
    {
        killme->getAnt ()->setSig (killme->getSig ());            // primer paso
        if (killme->getSig () != nullptr)                           // segundo paso (si no es el ultimo)
            killme->getSig ()->setAnt (killme->getAnt ());
    }
    delete killme;                                                  // cuarto paso
}
