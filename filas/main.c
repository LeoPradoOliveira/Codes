#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leo.h"

int main(int argc,char ** argv){
    Fila *a;
    int b;
    a = fila_cria_vet();
    scanf(" %d", &b);
    fila_insere_vet(a,b);
    fila_imprime_vet(a);


    return 0;
}
