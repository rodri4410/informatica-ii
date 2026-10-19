/* ej08_lista_doble · nododoble.cpp — getters y setters de los dos enlaces */
#include "nododoble.h"

NodoDoble::NodoDoble (int dato)
{
    m_dato = dato;
    m_sig = m_ant = nullptr;
}

int NodoDoble::getDato ()
{
    return m_dato;
}

NodoDoble* NodoDoble::getSig ()
{
    return m_sig;
}

NodoDoble* NodoDoble::getAnt ()
{
    return m_ant;
}

void NodoDoble::setSig (NodoDoble* sig)
{
    m_sig = sig;
}

void NodoDoble::setAnt (NodoDoble* ant)
{
    m_ant = ant;
}
