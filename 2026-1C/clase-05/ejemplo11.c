#include <stdio.h>

int main() {
    FILE *fp = fopen("archivo.txt", "r");
    char c;

    if (!fp) {
        perror("No se pudo abrir");
        return 1;
    }

    while ((c = fgetc(fp)) != EOF) {
        putchar(c);
    }

    // Al salir del ciclo: ¿EOF o error?
    if (ferror(fp)) {
        printf("\n Ocurrio un error al leer el archivo.\n");
    } else if (feof(fp)) {
        printf("\n Lectura finalizada correctamente (EOF).\n");
    }

    fclose(fp);
    return 0;
}