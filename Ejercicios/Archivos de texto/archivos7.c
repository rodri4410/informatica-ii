#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*7. Escriba un programa que lea el contenido de la
variable de entorno PATH y lo almacene en
un archivo de texto llamado path.txt.*/

int main(){

char *path = getenv("PATH");

FILE *fp = fopen("path.txt","w");

if (fp == NULL){
    printf("\nError al crear el archivo");
    return 1;
}

fputs(path,fp);


fclose(fp);
}
