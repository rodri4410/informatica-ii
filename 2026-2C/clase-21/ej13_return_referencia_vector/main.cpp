#include <iostream>

// Funcion que devuelve una referencia a un elemento de un vector
int& obtenerElemento(int vec[], int indice) {
    return vec[indice];
}

int main() {
    int miVec[5] = {10, 20, 30, 40, 50};

    // Llamamos a la funcion y modificamos el valor del elemento 2
    obtenerElemento(miVec, 2) = 100;

    // Imprimimos el vector para verificar el cambio
    std::cout << "Vector despues de la modificacion: ";
    for (int i = 0; i < 5; i++) {
        std::cout << miVec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
