#include <iostream>

void incrementByPointer(int* ptr) {
    if (ptr) {  // Verificamos que el puntero no sea nulo
        (*ptr)++;
    }
}

int main() {
    int vX = 5;
    std::cout << "Valor antes del incremento (por direccion): " << vX << std::endl;

    incrementByPointer(&vX);  // Pasamos la direccion de 'value'

    std::cout << "Valor despues del incremento (por direccion): " << vX << std::endl;

    return 0;
}
