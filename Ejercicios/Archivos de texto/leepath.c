#include <stdio.h>
#include <stdlib.h>

int main() {
    char *path = getenv("PATH");

    if (path == NULL) {
        printf("No se pudo obtener PATH\n");
        return 1;
    }

    printf("PATH = %s\n", path);

    return 0;
}
