#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    float valor;

    if (argc < 2) {
        printf("Error: falta un numero.\n");
        return 1;
    }

    valor = atof(argv[1]);  // Convierte sin verificar
    printf("[atof] Valor convertido: %.2f\n", valor);

    return 0;
}
