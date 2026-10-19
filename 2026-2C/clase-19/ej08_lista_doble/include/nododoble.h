/* ej08_lista_doble · nododoble.h — nodo con dos enlaces */
#ifndef NODODOBLE_H
#define NODODOBLE_H

class NodoDoble
{
private:
    int m_dato;
    NodoDoble* m_sig;
    NodoDoble* m_ant;
public:
    NodoDoble (int);
    int getDato ();
    NodoDoble* getSig ();
    NodoDoble* getAnt ();
    void setSig (NodoDoble*);
    void setAnt (NodoDoble*);
};

#endif // NODODOBLE_H
