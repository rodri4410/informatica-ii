/* ej02_crear_recorrer · lista.cpp — crearLista (cada valor va al comienzo) y recorrerLista (el for con puntero) */
#include <iostream>
#include "lista.h"
#include "nodo.h"

Lista::Lista ()
{
    m_inicio = nullptr;
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
