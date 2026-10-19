#include "nodo.h"

Nodo::Nodo (Sensor sensor)
{
    m_sensor = sensor;
    m_sig = nullptr;
}

Nodo* Nodo::getSig ()
{
    return m_sig;
}

Sensor* Nodo::getSensor ()
{
    return &m_sensor;
}

void Nodo::setSig (Nodo* sig)
{
    m_sig = sig;
}
