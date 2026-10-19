/* ej07_lista_ordenada · main.cpp — ListaOrd con insertarOrdenado: el tema del parcial */
#include <iostream>
#include "listaordenada.h"

int main ()
{
    ListaOrd lista;
    int x {};
    std::cout << "Ingresar valores en cualquier orden, -1 termina" << '\n';
    std::cin >> x;
    while (x != -1)
    {
        lista.insertarOrdenado (x);
        std::cin >> x;
    }
    lista.recorrerLista ();          // salen ordenados
    return 0;
}
