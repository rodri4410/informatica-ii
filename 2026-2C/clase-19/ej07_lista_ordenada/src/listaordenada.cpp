/* ej07_lista_ordenada · listaordenada.cpp — los metodos copiados de Lista cambian solo el nombre de la clase */
#include <iostream>
#include "listaordenada.h"
#include "nodo.h"

ListaOrd::ListaOrd ()
{
    m_inicio = nullptr;
}

ListaOrd::~ListaOrd ()
{
    Nodo* p = m_inicio;
    while (p != nullptr)
    {
        Nodo* sig = p->getSig ();
        delete p;
        p = sig;
    }
}

void ListaOrd::recorrerLista ()
{
    std::cout << "Recorriendo lista: " << '\n';
    for (Nodo* p = m_inicio ; p != nullptr ; p = p->getSig ())
        std::cout << p->getDato () << '\n';
}

Nodo* ListaOrd::getUltimo ()
{
    Nodo* p = m_inicio;
    if (p == nullptr)                  // lista vacia: no hay ultimo
        return nullptr;
    while (p->getSig () != nullptr)
        p = p->getSig ();
    return p;
}

Nodo* ListaOrd::buscarNodo (int objetivo)
{
    for (Nodo* p = m_inicio ; p != nullptr ; p = p->getSig ())
        if (p->getDato () == objetivo)
            return p;                  // la direccion del nodo que lo tiene
    return nullptr;                    // no esta
}

void ListaOrd::borrarNodo (int objetivo)
{
    if (m_inicio == nullptr)
    {
        std::cerr << "borrarNodo: la lista esta vacia" << '\n';
        return;
    }
    //paso 1: dos punteros auxiliares
    Nodo* actual = m_inicio;
    Nodo* anterior = nullptr;
    //paso 2: buscar el objetivo recordando el anterior
    while (actual != nullptr && actual->getDato () != objetivo)
    {
        anterior = actual;
        actual = actual->getSig ();
    }
    if (actual == nullptr)
    {
        std::cerr << "borrarNodo: el valor " << objetivo << " no esta en la lista" << '\n';
        return;
    }
    //paso 3: desenganchar
    if (actual == m_inicio)                    // era el primero
        m_inicio = actual->getSig ();
    else
        anterior->setSig (actual->getSig ());
    //paso 4: liberar
    delete actual;
}

void ListaOrd::borrarOcurrencias (int objetivo)
{
    Nodo* actual = m_inicio;
    Nodo* anterior = nullptr;
    bool encontrado {false};

    while (actual != nullptr)                  // ahora no paramos al encontrarlo: vamos hasta el final
    {
        if (actual->getDato () == objetivo)
        {
            encontrado = true;
            if (actual == m_inicio)
                m_inicio = actual->getSig ();
            else
                anterior->setSig (actual->getSig ());
            Nodo* aEliminar = actual;
            actual = actual->getSig ();        // avanzamos ANTES de liberar
            delete aEliminar;
        }
        else
        {
            anterior = actual;
            actual = actual->getSig ();
        }
    }
    if (!encontrado)
        std::cerr << "borrarOcurrencias: el valor " << objetivo << " no esta en la lista" << '\n';
}

void ListaOrd::insertarOrdenado (int dato)
{
    //paso 1: crear el nodo
    Nodo* nuevo = new Nodo (dato);

    if (m_inicio == nullptr)                          //paso 2: lista vacia
        m_inicio = nuevo;
    else if (dato < m_inicio->getDato ())             //paso 3: va primero
    {
        nuevo->setSig (m_inicio);
        m_inicio = nuevo;
    }
    else                                              //paso 4: buscar el lugar
    {
        Nodo* anterior = m_inicio;
        Nodo* p = m_inicio;
        while (p->getSig () != nullptr && dato > p->getDato ())
        {
            anterior = p;
            p = p->getSig ();
        }
        if (dato > p->getDato ())                     //paso 5: llegamos al final
            anterior = p;
        //paso 6: enganchar entre anterior y el que le sigue
        nuevo->setSig (anterior->getSig ());
        anterior->setSig (nuevo);
    }
}
