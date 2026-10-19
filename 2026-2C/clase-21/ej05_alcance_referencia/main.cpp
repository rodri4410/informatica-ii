// El alcance de la referencia y el del objeto referenciado son independientes.
#include <iostream>

int main ()
{
    int vX{10};
    int vY{20};
    {
        int& refX {vX};
        refX = vY ;
    } //refX deja de existir fuera del bloque,
      //sin embargo vX sigue como si nada
      //solo deja de tener dos nombres
    std::cout << vX << "\n";
    return 0;
}
