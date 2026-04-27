#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*7. Escriba un programa que lea el contenido de la
variable de entorno PATH y lo almacene en
un archivo de texto llamado path.txt.
1. Como extra, se pide que el contenido se procese de forma tal que cada ruta contenida en PATH (separadas por
; en Windows o : en Linux) quede en una línea distinta del archivo.*/

int main(){


int cont=0;
char *path = getenv("PATH");
char *token;

FILE *fp = fopen("path.txt","w");

if (path == NULL){
    printf("No se pudo obtener PATH\n");
    return 1;
}

if (fp == NULL){
    printf("\nError al crear el archivo");
    return 1;
}


token = strtok(path,";");

while (token != NULL){
   fputs(token,fp);
   fputc('\n',fp);
   token = strtok(NULL, ";");
}



fclose(fp);
}
