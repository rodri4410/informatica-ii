#include <iostream>

void incrementByReference(int& ref) {
    ref++;
}

int main() {
    int vX = 5;
    std::cout << "Valor antes del incremento (por referencia): " << vX << std::endl;

    incrementByReference(vX);  // Pasamos 'value' por referencia

    std::cout << "Valor despues del incremento (por referencia): " << vX << std::endl;

    return 0;
}
