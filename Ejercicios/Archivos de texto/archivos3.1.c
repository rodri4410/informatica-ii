#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

char texto[100];
char texto2[100];

FILE *fp = fopen("concat.txt","w");
FILE *f1 = fopen("cmp1.txt","r");
FILE *f2 = fopen("cmp2.txt","r");

if (fp == NULL || f1==NULL || f2 == NULL){
    printf("\nError al abrir alguno de los archivos");
    return 1;
}

fgets(texto,100,f1);
fgets(texto2,100,f2);

fputs(texto,fp);
fputs("\n",fp);
fputs(texto2,fp);

fclose(fp);
fclose(f1);
fclose(f2);
}
