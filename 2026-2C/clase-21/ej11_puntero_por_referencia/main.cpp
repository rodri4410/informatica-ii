#include <iostream>

// Funcion que toma un puntero por referencia y lo cambia para que apunte a otra direccion
void cambiarPuntero(int*& ptr) {
    static int nuevoValor = 20;  // ¿Se acuerdan el uso de static?
    ptr = &nuevoValor;           // Cambiamos el puntero para que apunte a nuevoValor
}

int main() {
    int valorOriginal = 10;
    int* puntero = &valorOriginal;

    std::cout << "Antes de cambiar el puntero:" << std::endl;
    std::cout << "puntero apunta a valorOriginal, valor = " << *puntero << std::endl;

    // Llamamos a la funcion que cambia a dónde apunta el puntero
    cambiarPuntero(puntero);

    std::cout << "Despues de cambiar el puntero:" << std::endl;
    std::cout << "puntero ahora apunta a nuevoValor, valor = " << *puntero << std::endl;

    return 0;
}
