#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*4. Realizar un programa que busque una palabra
en un archivo de texto y si está varias veces indicar
cuántas. La palabra se debe ingresar como argumento del main.*/

int main(int argc, char *argv[]){

char texto[100];
int cont=0;

FILE *fp = fopen("concat.txt","r");


if (fp == NULL){
    printf("\nError al abrir el archivo");
    return 1;
}
if (argc<2)
    printf("No se ingreso ningun argumento");

while (fscanf(fp,"%s",texto) != EOF){
    if(strcmpi(texto,argv[1])==0)
        cont++;
}

printf("\nLa palabra se encontro %d veces",cont);

fclose(fp);
}
