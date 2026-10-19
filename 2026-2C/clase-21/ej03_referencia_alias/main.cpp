// Referencia lvalue: un segundo nombre para el mismo objeto.
#include <iostream>

int main ()
{
    int vX{10};         //vX es una variable integer
    int& refX {vX};     //refX es una referencia lvalue
                        //podemos usar refX como un alias de vX
    std::cout << vX << "\n";
    std::cout << refX << "\n";
    refX = 1;
    std::cout << vX << refX << "\n";    // imprime 1 y 1, sin separador

    // Las referencias se inicializan siempre:
    // int& refY;                        // ERROR: 'refY' declared as reference but not initialized

    // Solo a lvalues modificables del mismo tipo:
    // const int vY{5};
    // int& refY {vY};                   // ERROR: binding reference of type 'int&' to 'const int' discards qualifiers
    // int& refC {11};                   // ERROR: cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'
    // double vD{10.0};
    // int& refD {vD};                   // ERROR: cannot bind non-const lvalue reference of type 'int&' to a value of type 'double'

    return 0;
}
