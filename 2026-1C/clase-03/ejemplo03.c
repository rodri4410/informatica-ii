#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int valor;

    if (argc < 2) {
        printf("Uso: %s <numero>\n", argv[0]);
        return 1;
    }

    valor = atoi(argv[1]);

    printf("[atoi] Valor convertido: %d\n", valor);
    return 0;
}