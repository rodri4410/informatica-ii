// Una referencia no se puede recolocar: asignarle otra variable asigna al objeto referenciado.
#include <iostream>

int main ()
{
    int vX{10};
    int vY{20};
    int& refX {vX};

    refX = vY ;         // NO cambiamos refX. Lo que hicimos fue: vX = vY ;

    std::cout << vX << "\n";
    return 0;
}
