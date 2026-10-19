#include <iostream>

// Funcion para swapear los valores de dos variables
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 5;
    int y = 10;

    std::cout << "Antes del swap: x = " << x << ", y = " << y << std::endl;

    // Llamada a la funcion swap pasando los argumentos por referencia
    swap(x, y);

    std::cout << "Despues del swap: x = " << x << ", y = " << y << std::endl;

    return 0;
}
