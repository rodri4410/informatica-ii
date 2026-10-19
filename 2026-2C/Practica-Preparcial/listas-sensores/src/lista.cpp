#include <iostream>
#include <cstdio>
#include <cstring>
#include "lista.h"

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

void Lista::insertarOrdenado (Sensor sensor)
{
    //paso 1: crear el nodo en el heap
    Nodo* nuevo = new Nodo (sensor);

    if (m_inicio == nullptr)   //paso 2: caso lista vacia
        m_inicio = nuevo;

    else if (sensor.bateria < m_inicio->getSensor()->bateria) //paso3: caso primero de la lista
    {
        nuevo->setSig (m_inicio);
        m_inicio = nuevo;
    }

    else
    {
        Nodo* anterior = m_inicio;
        Nodo* p = m_inicio;
        while (p->getSig() != nullptr && sensor.bateria >= p->getSensor ()->bateria)
        {
            anterior = p;
            p = p->getSig();
        }
        if (sensor.bateria >= p->getSensor()->bateria) // legamos al final
            anterior = p;

        nuevo->setSig (anterior->getSig());
        anterior->setSig (nuevo);
    }
}

int Lista::cargarDesdeArchivo (const char* nombreArchivo)
{
    FILE* arch = std::fopen (nombreArchivo, "rb");
    Sensor s;
    int cantidad = 0;

    if (arch == nullptr)
    {
        std::cout << "No se puedo abrir el archivo: " << nombreArchivo << std::endl;
        return -1;
    }

    while (std::fread (&s, sizeof(Sensor), 1, arch) == 1)
    {
        insertarOrdenado(s);
        cantidad++;
    }

    std::fclose (arch);
    return cantidad;
}

bool Lista::estaActivo (Sensor* s)
{
    return (s->habilitado && s->bateria > 0);
}

void Lista::imprimirSensor (Sensor* s)
{
    std::cout << s->nombre
              << " bat=" << s->bateria << "%"
              << " sen=" << s->senial << "%"
              << " tem=" << s->temperatura;
    if (estaActivo(s))
        std::cout << "   ACTIVO";
    else
        std::cout << "   inactivo";
    std::cout << std::endl;
}

void Lista::recorrerLista()
{
    for (Nodo* p = m_inicio ; p != nullptr ; p = p->getSig())
        imprimirSensor (p->getSensor());
}

int Lista::verificarSenial (int umbral)
{
    int cantidad = 0;
    for (Nodo* p = m_inicio ; p != nullptr ; p = p->getSig())
    {
        if (p->getSensor ()->senial < umbral)
        {
            p->getSensor()->habilitado = false;
            cantidad++;
        }
    }
    return cantidad;
}

// ---- Lo que sigue no esta en el video ----

Nodo* Lista::buscarNodo (const char* nombre)
{
    // el nombre es un char[]: se compara con strcmp, no con ==
    for (Nodo* p = m_inicio ; p != nullptr ; p = p->getSig())
        if (std::strcmp (p->getSensor()->nombre, nombre) == 0)
            return p;
    return nullptr;
}

void Lista::habilitar (const char* nombre)
{
    Nodo* p = buscarNodo (nombre);
    if (p == nullptr)                        // no existe: avisar y volver
    {
        std::cout << "No existe el sensor: " << nombre << std::endl;
        return;
    }
    p->getSensor()->habilitado = true;
}

float Lista::promedioActivos ()
{
    float suma = 0;
    int cantidad = 0;
    for (Nodo* p = m_inicio ; p != nullptr ; p = p->getSig())
    {
        if (estaActivo (p->getSensor()))
        {
            suma = suma + p->getSensor()->temperatura;
            cantidad++;
        }
    }
    if (cantidad == 0)                       // antes de dividir
    {
        std::cout << "No hay sensores activos" << std::endl;
        return 0;
    }
    return suma / cantidad;
}

int Lista::contarSobrecalentados (float limite)
{
    int cantidad = 0;
    for (Nodo* p = m_inicio ; p != nullptr ; p = p->getSig())
    {
        if (estaActivo (p->getSensor()) && p->getSensor()->temperatura > limite)
            cantidad++;
    }
    return cantidad;
}

void Lista::consumirBateria (int consumo)
{
    // consumen todos los encendidos, habilitados o no: la resta es uniforme
    // y la lista sigue ordenada por bateria
    for (Nodo* p = m_inicio ; p != nullptr ; p = p->getSig())
    {
        Sensor* s = p->getSensor();
        if (s->bateria > 0)
        {
            s->bateria = s->bateria - consumo;
            if (s->bateria < 0)              // nunca por debajo de 0
                s->bateria = 0;
        }
    }
}

int Lista::purgarAgotados ()
{
    Nodo* actual = m_inicio;
    Nodo* anterior = nullptr;
    int cantidad = 0;

    while (actual != nullptr)                // hasta el final: pueden ser varios
    {
        if (actual->getSensor()->bateria == 0)
        {
            // el chequeo de "era el primero" va adentro del while:
            // los agotados pueden ser varios seguidos al principio
            if (anterior == nullptr)
                m_inicio = actual->getSig();
            else
                anterior->setSig (actual->getSig());

            Nodo* aEliminar = actual;
            actual = actual->getSig();       // avanzar ANTES de liberar
            delete aEliminar;
            cantidad++;
        }
        else
        {
            anterior = actual;
            actual = actual->getSig();
        }
    }
    return cantidad;
}
