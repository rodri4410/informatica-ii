/* ej06_borrar_ocurrencias · lista.cpp — borrarOcurrencias: recorre hasta el final */
#include <iostream>
#include "lista.h"
#include "nodo.h"

Lista::Lista ()
{
    m_inicio = nullptr;
}

Lista::~Lista ()
{
    Nodo* p = m_inicio;
    while (p != nullptr)
    {
        Nodo* sig = p->getSig ();
        delete p;
        p = sig;
    }
}

void Lista::crearLista ()
{
    int x {};
    m_inicio = nullptr;                // potencial memory leak: si ya habia nodos, se pierden
    std::cout << "El ingreso termina con -1" << '\n';
    do {
        std::cin >> x;
        if (x != -1)
            m_inicio = new Nodo (x, m_inicio);
    } while (x != -1);
}

void Lista::recorrerLista ()
{
    std::cout << "Recorriendo lista: " << '\n';
    for (Nodo* p = m_inicio ; p != nullptr ; p = p->getSig ())
        std::cout << p->getDato () << '\n';
}

void Lista::insertarPrimero (int dato)
{
    //paso 1: crear el nodo
    Nodo* nuevo = new Nodo (dato);
    //paso 2: el nuevo apunta al que era el primero
    nuevo->setSig (m_inicio);
    //paso 3: el nuevo pasa a ser el primero
    m_inicio = nuevo;
}

Nodo* Lista::getUltimo ()
{
    Nodo* p = m_inicio;
    if (p == nullptr)                  // lista vacia: no hay ultimo
        return nullptr;
    while (p->getSig () != nullptr)
        p = p->getSig ();
    return p;
}

void Lista::insertarUltimo (int dato)
{
    if (m_inicio == nullptr)           // lista vacia: el ultimo es tambien el primero
    {
        insertarPrimero (dato);
        return;
    }
    //paso 1: crear el nodo (apunta a nullptr: va a ser el ultimo)
    Nodo* nuevo = new Nodo (dato);
    //paso 2: buscar el ultimo y engancharle el nuevo
    Nodo* ultimo = getUltimo ();
    ultimo->setSig (nuevo);
}

void Lista::insertarAntes (int dato, int objetivo)
{
    if (m_inicio == nullptr)
    {
        std::cerr << "insertarAntes: la lista esta vacia" << '\n';   // cerr: cout para errores, va por otro canal
        return;
    }
    if (m_inicio->getDato () == objetivo)      // el objetivo es el primero
    {
        insertarPrimero (dato);
        return;
    }
    //paso 1: dos punteros auxiliares
    Nodo* actual = m_inicio;
    Nodo* anterior = nullptr;
    //paso 2: buscar el objetivo recordando cual es el anterior
    while (actual != nullptr && actual->getDato () != objetivo)
    {
        anterior = actual;
        actual = actual->getSig ();
    }
    if (actual == nullptr)
    {
        std::cerr << "insertarAntes: el valor " << objetivo << " no esta en la lista" << '\n';
        return;
    }
    //paso 3: el nuevo apunta al objetivo
    Nodo* nuevo = new Nodo (dato, actual);
    //paso 4: el anterior apunta al nuevo
    anterior->setSig (nuevo);
}

Nodo* Lista::buscarNodo (int objetivo)
{
    for (Nodo* p = m_inicio ; p != nullptr ; p = p->getSig ())
        if (p->getDato () == objetivo)
            return p;                  // la direccion del nodo que lo tiene
    return nullptr;                    // no esta
}

void Lista::insertarDespues (int dato, int objetivo)
{
    Nodo* ptrObj = buscarNodo (objetivo);
    if (ptrObj == nullptr)
    {
        std::cerr << "insertarDespues: el valor " << objetivo << " no esta en la lista" << '\n';
        return;
    }
    //el nuevo apunta a donde apuntaba el objetivo, y el objetivo apunta al nuevo
    Nodo* nuevo = new Nodo (dato, ptrObj->getSig ());
    ptrObj->setSig (nuevo);
}

void Lista::borrarNodo (int objetivo)
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

void Lista::borrarOcurrencias (int objetivo)
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
