#include <iostream>

// Funcion que devuelve una referencia
int& funcion(int vX, int& rY ) {
    static int aux {};
    rY++;
    aux = vX*rY;
    return aux;
}

int main() {
    int vX{2};
    std::cout << "vX: " << vX << "\n";

    //Guardo la referencia
    int& refAux {funcion (vX, vX)};
    std::cout << "vX: " << vX << "\trefAux: " << refAux << "\n";

    //Guardo la direccion de aux
    int* ptrAux = &funcion (vX, vX);
    std::cout << "vX: " << vX << "\t*ptrAux: " << *ptrAux << "\n";

    //Guardo la copia de aux
    int copiaAux {funcion (vX, vX)};
    std::cout << "vX: " << vX << "\tcopiaAux: " << copiaAux << "\n";

    return 0;
}
