// Punto: tres formas de devolver un atributo desde un metodo.
//
//   int        copiaX()     -> devuelve una COPIA   (rvalue: no se puede asignar)
//   int&       refX()       -> devuelve un ALIAS modificable (rompe el private)
//   const int& refConstX()  -> devuelve un ALIAS de solo lectura
//
// Compilar:  g++ -Wall -Wextra -std=c++17 -o punto main.cpp
#include <iostream>

class Punto
{
private:
    int m_x {0};
    int m_y {0};

public:
    Punto (int x = 0, int y = 0);
    int        copiaX (void);
    int&       refX (void);
    const int& refConstX (void);
    void       setX (int);
    void       imprimir (void);
};

Punto::Punto (int x, int y)
{
    m_x = x;
    m_y = y;
}

// 1) Por valor: el return COPIA m_x. Lo que sale es un rvalue.
int Punto::copiaX (void)
{
    return m_x;
}

// 2) Por referencia: alias modificable. Compila, pero el private ya no protege nada.
int& Punto::refX (void)
{
    return m_x;
}

// 3) Por referencia const: el return NO copia, devuelve un alias de m_x.
//    Desde afuera se puede leer, pero no modificar.
//    Con un int no se nota; con un atributo grande (un miString, una matriz)
//    es la diferencia entre copiar todo o no copiar nada.
const int& Punto::refConstX (void)
{
    return m_x;
}

// La forma correcta de modificar: un metodo que decide que se acepta.
void Punto::setX (int x)
{
    m_x = x;
}

void Punto::imprimir (void)
{
    std::cout << "Punto (" << m_x << " , " << m_y << ")\n";
}

int main (void)
{
    Punto p (10, 20);

    p.imprimir();

    // ---- 1) copia --------------------------------------------------------
    int copia = p.copiaX();     // copia vale 10, es OTRA variable
    copia = 100;                // cambia la copia, no el punto
    std::cout << "copia = " << copia << "   ";
    p.imprimir();               // sigue en 10

    // Lo que devuelve copiaX() es un rvalue (slide 9):
    // p.copiaX() = 100;        // ERROR: lvalue required as left operand of assignment

    // ---- 2) referencia modificable ---------------------------------------
    p.refX() = 100;             // compila: es un alias de m_x
    std::cout << "p.refX() = 100   ";
    p.imprimir();               // 100: el private no sirvio de nada

    // ---- 3) referencia const ---------------------------------------------
    const int& rc = p.refConstX();   // rc es un alias de m_x, sin copiar
    // La referencia es const:
    // rc = 100;                // ERROR: assignment of read-only reference 'rc'

    p.setX(30);                      // modificamos por la via correcta...
    std::cout << "rc = " << rc << "   ";
    p.imprimir();                    // ...y rc lo ve: 30

    return 0;
}
