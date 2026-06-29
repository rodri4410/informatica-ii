#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *fin;
    float valor;

    if (argc < 2) {
        fprintf(stderr, "Error: falta un número.\n");
        return 1;
    }

    valor = strtof(argv[1], &fin);

    if (*fin != '\0') {
        fprintf(stderr,"Error: '%s' no es un numero valido.\n", argv[1]);
        return 1;
    }

    printf("[strtof] Valor convertido: %.2f\n", valor);
    return 0;
}

