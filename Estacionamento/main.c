#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

int main(){
    FilaL *parking;
    int opt;
    char sign[8];
    
    parking = fila_cria_l(parking);

    do{
        printf("1-Adicionar carro\n2-Remover carro\n3-Imprimir placas\n4-Encerrar\n");
        scanf(" %d", &opt);
        
        switch(opt){

            case 1:
                printf("Placa a ser adicionada: _______\b\b\b\b\b\b\b");
                getchar();
                fgets(sign,8,stdin);
                fila_insere_l(parking,sign);
                break;

            case 2:

                if(parking->ini!=NULL){
                    printf("Placa a ser retirada: _______\b\b\b\b\b\b\b");
                    getchar();
                    fgets(sign,8,stdin);
                    if(strcmp(sign, parking->ini->info)==0){
                        fila_retira_l(parking);
                        printf("Retirada com sucesso!\n");
                    }
                    else{
                        printf("Esse carro nao e o primeiro da fila, nada retirado.\n");
                    }
                }
                else
                printf("Estacionamento vazio.\n");
                break;

            case 3:
                fila_imprime_l(parking);
                if(parking->ini==NULL)
                printf("Vazio.\n");
                break;

            case 4:
                break;
            default:
                printf("Invalido, digite novamente:\n");
                break;
        }
    }while(opt!=4);

    fila_libera_l(parking);
    return 0;
}