#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*5. Realizar un programa que muestre el
contenido de un archivo de texto, cuyo
nombre es ingresado por argumentos del main*/

int main(int argc, char *argv[]){

char texto[100];

FILE *fp = fopen(argv[1],"r");

if (fp == NULL){
    printf("\nError al abrir el archivo");
    return 1;
}
if (argc<2)
    printf("No se ingreso ningun argumento");
 /*
while(fscanf(fp,"%s",texto)!= EOF){
    printf("%s",texto);
}
*/

while(fgets(texto,100,fp)!= NULL){
    printf("%s",texto);
}

fclose(fp);
}
