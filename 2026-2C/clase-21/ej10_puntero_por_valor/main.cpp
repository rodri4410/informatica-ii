// El puntero se recibe POR VALOR: la funcion modifica su copia, no el puntero del main.
// g++ -Wall -Wextra avisa "parameter 'ptr' set but not used": es exactamente el punto.
#include <iostream>

void cambiarPtr (int* ptr)
{
    ptr = nullptr;
}

int main ()
{
    int x{12};
    int* ptr{&x};
    cambiarPtr (ptr);
    std::cout << *ptr << "\n";      // 12: ptr sigue apuntando a x
    return 0;
}
