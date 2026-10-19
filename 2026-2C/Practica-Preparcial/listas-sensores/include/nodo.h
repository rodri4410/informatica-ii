#ifndef NODO_H
#define NODO_H

struct Sensor
{
    char  nombre[16];     // identificador, terminado en '\0'
    int   bateria;        // 0 a 100 (%)
    int   senial;         // 0 a 100 (%)
    float temperatura;    // ultima lectura, en grados
    bool  habilitado;
};

class Nodo
{
private:
    Sensor m_sensor;
    Nodo* m_sig;

public:
    Nodo (Sensor);
    Nodo* getSig ();
    Sensor* getSensor ();
    void setSig (Nodo*);
};

#endif
