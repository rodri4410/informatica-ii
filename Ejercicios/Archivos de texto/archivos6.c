#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Realizar un programa que copie un archivo a otro
cuyos nombres estaran indicados como argumentos del main.
 Asi: copy archivo_original.txt archivo_copia.txt*/

int main(int argc, char *argv[]){

char texto[100];


FILE *f1 = fopen(argv[1],"r");
FILE *f2 = fopen(argv[2],"w");

if (f1 == NULL || f2 == NULL){
    printf("\nError al abrir o crear los archivos");
    return 1;
}
if (argc<2)
    printf("No se ingreso ningun argumento");

while(fgets(texto,100,f1)!= NULL){
    fputs(texto,f2);
}

fclose(f1);
fclose(f2);
}
