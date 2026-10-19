#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"

class Lista
{
private:
    Nodo* m_inicio;
    bool estaActivo (Sensor*);
    void imprimirSensor (Sensor*);
public:
    Lista();
    ~Lista();
    void insertarOrdenado (Sensor);
    int   cargarDesdeArchivo (const char*);
    void recorrerLista();
    int verificarSenial (int);
    Nodo* buscarNodo (const char*);          // devuelve el nodo con ese nombre, o nullptr
    void habilitar (const char*);
    float promedioActivos ();
    int contarSobrecalentados (float);
    void consumirBateria (int);
    int purgarAgotados ();                   // devuelve cuantos elimino
};

#endif
