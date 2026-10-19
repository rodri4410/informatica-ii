// Referencia lvalue const: referencia a un lvalue no modificable, a un lvalue modificable, o a un rvalue.
#include <iostream>

int main ()
{
    const int vX{10};
    //int& refX {vX};   //esto no funciona
    const int& refX {vX};

    int vY{10};
    const int& refY {vY};       // sobre un no-const: se puede leer, no modificar

    const int& refC {14};       // la referencia const crea un objeto temporal
                                // que vive lo que vive refC

    std::cout << refX << "\n";
    std::cout << refY << "\n";
    std::cout << refC << "\n";

    // refX = 12 ;              // ERROR: assignment of read-only reference 'refX'
    // refY = 12 ;              // ERROR: assignment of read-only reference 'refY'

    return 0;
}
