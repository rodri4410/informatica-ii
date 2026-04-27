#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

FILE *fp = fopen("cmp1.txt","w+");
FILE *f2 = fopen("cmp2.txt","w+");
int flag=0;
char texto1[50];
char texto2[50];

if (fp == NULL || f2 == NULL){
    printf("\nError al crear uno de los archivos");
    return 1;
}

fprintf(fp, "Estoy creando el primer archivo");
fprintf(f2, "\nEstoy creando el segundo archivo");

rewind(fp);
rewind(f2);

fgets(texto1,50,fp);
fgets(texto2,50,f2);


if (strcmpi(texto1, texto2)!=0)
    printf("Los textos NO son iguales");
else
    printf("Los textos son iguales");

fclose(fp);
fclose(f2);

}
