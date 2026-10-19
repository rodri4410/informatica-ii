// Una funcion que devuelve por valor produce un rvalue.
// Una funcion que devuelve por referencia produce un lvalue: se le puede asignar.
#include <iostream>

int global = 100;

int& setGlobal ()
{
    return global;
}

int setValue ()
{
    return 6;
}

int main ()
{
    std::cout << setValue() << '\n';

    setGlobal() = 400;      // OK: setGlobal() es un lvalue (alias de global)
    std::cout << global << '\n';

    // setValue() = 3;      // ERROR: lvalue required as left operand of assignment

    return 0;
}
