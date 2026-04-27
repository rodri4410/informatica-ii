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
fprintf(f2, "Estoy creando el segundo archivo");

rewind(fp);
rewind(f2);

while (fgetc(fp) != EOF && fgetc(f2)!= EOF)
{
    if (fgetc(fp)==fgetc(f2))
        flag=0;
    else flag=1;
}

if (flag == 1)
    printf("Los archivos son distintos");
else
    printf("Los archivos son iguales");

fclose(fp);
fclose(f2);

}
