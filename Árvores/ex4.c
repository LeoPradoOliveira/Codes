#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
struct arv{
	char info;
    int count;
    int max;
	struct arv *esq;
	struct arv *dir;
};
typedef struct arv Arv;

#define SUCESSO 0

Arv* arv_criavazia(){return NULL;}

int arv_vazia(Arv* a){
	return (a == NULL);	
}

Arv* arv_libera(Arv* a){
	if(!arv_vazia(a)){
		arv_libera(a->esq);
		arv_libera(a->dir);
		free(a);
	}
	return NULL;
}

Arv* arv_insere(Arv* a,char b){
    if(a==NULL){
        a = (Arv*) malloc (sizeof(Arv));
        a->info = b;
        a->esq = a->dir = NULL;
    }
    else if(b < a->info)
        a->esq = arv_insere(a->esq,b);
        else
        a->dir = arv_insere(a->dir,b);
    return a;
}

void arv_imprime_preordem(Arv* a){
	if(!arv_vazia(a)){
		printf("%c ",a->info);
		arv_imprime_preordem(a->esq);
		arv_imprime_preordem(a->dir);
	}
}

void arv_imprime_simetrica(Arv* a){
	if(!arv_vazia(a)){
		arv_imprime_simetrica(a->esq);
		printf("%c ",a->info);
		arv_imprime_simetrica(a->dir);
	}
}

void arv_imprime_posordem(Arv *a){
	if(!arv_vazia(a)){
		arv_imprime_posordem(a->esq);
		arv_imprime_posordem(a->dir);
		printf("%c ",a->info);
	}
        
}

int arv_num_folhas(Arv* a){
    int total=0;

    if(arv_vazia(a)){
        return 0;
    }
    if(!arv_vazia(a->esq)){
        total += arv_num_folhas(a->esq);
    }
    if(!arv_vazia(a->dir)){
        total += arv_num_folhas(a->dir);
    }
    if(a->esq == NULL && a->dir == NULL){
        return total+1;
    }else
    return total;
}

int galho_de_um_no(Arv *a){
    int total=0;

    if(arv_vazia(a)){
        return 0;
    }
    if(!arv_vazia(a->esq)){
        total += galho_de_um_no(a->esq);
    }
    if(!arv_vazia(a->dir)){
        total += galho_de_um_no(a->dir);
    }
    if((a->esq == NULL && a->dir != NULL) || (a->esq != NULL && a->dir == NULL)){
        return total+1;
    }else
        return total;
}

int galho_de_dois_no(Arv* a){
    int total=0;

    if(!arv_vazia(a->esq)){
        total += galho_de_dois_no(a->esq);
    }
    if(!arv_vazia(a->dir)){
        total += galho_de_dois_no(a->dir);
    }
    if(a->dir != NULL && a->esq != NULL){
        return total+1;
    }
        return total;
}

///////////////Funções do exercício///////////////

/*Detalhe importante: devido à forma como é feita a inserção na árvore para ser realizada a contagem, 
caso sejam colocados caracteres iguais, eles serão acumulados em um nó só, fazendo com que a 
contagem de nós e folhas se altere em relação ao outro exercício.*/

Arv* arv_insere_acumulado(Arv* a,char b){
    int maior = 0;
    if(a==NULL){
        a = (Arv*) malloc (sizeof(Arv));
        a->info = b;
        a->count = 1;
        a->esq = a->dir = NULL;
    }
    else if(b < a->info)
        a->esq = arv_insere_acumulado(a->esq,b);
    else if(b > a->info)
        a->dir = arv_insere_acumulado(a->dir,b);
    else{
        a->count++;
    }
    if(a->count>maior){
        maior = a->count;
    }
    a->max = maior;
    return a;
}

void mysuperhistogramH(Arv* a, int max){
    int i;
	if(!arv_vazia(a)){
		mysuperhistogramH(a->esq, max);
        printf(" |%c ",a->info);
        for(i=0;i<a->count;i++){
		printf("%c", 254);
        }
        for(i=0;i<max-a->count;i++){
            printf(" ");
        }
        printf(" |%d\n", a->count);
		mysuperhistogramH(a->dir, max);
	}
}

void mysuperhistogramV(Arv* a, int max){
    int i = max;
    
    if(!arv_vazia(a)){      
		mysuperhistogramV(a->esq, i);

        if(a->count==i){
            printf("%d ", a->count);
        }
        if(a->count>i){
            printf("%c ", 219);
        }
        if(a->count<i)
            printf("  ");

		mysuperhistogramV(a->dir, i);
	}
}

int main(int argc, char ** argv){
    Arv* limoeiro;
    int i;
    limoeiro = arv_criavazia();

    limoeiro = arv_insere_acumulado(limoeiro, 't');
    limoeiro = arv_insere_acumulado(limoeiro, 't');
    limoeiro = arv_insere_acumulado(limoeiro, 'u');
    limoeiro = arv_insere_acumulado(limoeiro, '?');
    limoeiro = arv_insere_acumulado(limoeiro, ')');
    limoeiro = arv_insere_acumulado(limoeiro, 'a');
    limoeiro = arv_insere_acumulado(limoeiro, '?');
    limoeiro = arv_insere_acumulado(limoeiro, 'y');
    limoeiro = arv_insere_acumulado(limoeiro, 'r');
    limoeiro = arv_insere_acumulado(limoeiro, 'u');
    limoeiro = arv_insere_acumulado(limoeiro, '8');
    limoeiro = arv_insere_acumulado(limoeiro, '?');
    limoeiro = arv_insere_acumulado(limoeiro, 'z');
    limoeiro = arv_insere_acumulado(limoeiro, 'a');
    limoeiro = arv_insere_acumulado(limoeiro, 't');
    limoeiro = arv_insere_acumulado(limoeiro, 'z');

    printf("\nHistograma Horizontal:\n\n");
    mysuperhistogramH(limoeiro, limoeiro->max);
    printf("\nHistograma Vertical:\n\n");

    //Gambiarra pra melhorar a formatação
    for(i=0;i<=limoeiro->max;i++){
        mysuperhistogramV(limoeiro, limoeiro->max-i);
        printf("\n");
    }
    arv_imprime_simetrica(limoeiro);
    //Gambiarra pra melhorar a formatação

    printf("\n");

    arv_libera(limoeiro);
    return SUCESSO;
}