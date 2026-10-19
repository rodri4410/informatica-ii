// Categorias de valor: lvalue (tiene identidad, persiste) y rvalue (temporal, muere en la expresion).
#include <iostream>

int return5 ()
{
    return 5;
}

int main ()
{
    // 5 es una expresión rvalue
    int x{ 5 };
    // 1.2 es una expresión rvalue
    const double d{ 1.2 };
    // x es una expresión lvalue modificable
    std::cout << x << '\n';
    // d es una expresión lvalue no-modificable
    std::cout << d << '\n';
    // return5() es una expresión rvalue (devuelto por valor)
    std::cout << return5() << '\n';
    // x + 1 es un rvalue
    std::cout << x + 1 << '\n';

    // A la izquierda del = tiene que haber un lvalue modificable:
    // 4 = x;              // ERROR: lvalue required as left operand of assignment
    // 666 = x;            // ERROR: lvalue required as left operand of assignment

    // El operador & necesita un lvalue:
    // int* y = &666;      // ERROR: lvalue required as unary '&' operand

    return 0;
}
