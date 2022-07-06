#include <stdio.h>
#include <math.h>
#include <stdlib.h>
struct arv{
	char info;
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
		printf("| %c ",a->info);
		arv_imprime_preordem(a->esq);
		arv_imprime_preordem(a->dir);
	}
}

void arv_imprime_simetrica(Arv* a){
	if(!arv_vazia(a)){
		arv_imprime_simetrica(a->esq);
		printf("| %c ",a->info);
		arv_imprime_simetrica(a->dir);
	}
}

void arv_imprime_posordem(Arv *a){
	if(!arv_vazia(a)){
		arv_imprime_posordem(a->esq);
		arv_imprime_posordem(a->dir);
		printf("| %c ",a->info);
	}
}

int main(int argc, char ** argv){
    Arv* limoeiro;
    limoeiro = arv_criavazia();
    int i, j;
    char t;

    printf("Quantos caracteres estarao na arvore?\n");
    scanf(" %d", &i);

    for(j=0;j<i;j++){
        printf("Char %d:\n", j+1);
        scanf(" %c", &t);
        limoeiro = arv_insere(limoeiro, t);
    }
    printf("Pre-ordem: ");
    arv_imprime_preordem(limoeiro);
    printf("|\n");
    printf("Simetrica: ");
    arv_imprime_simetrica(limoeiro);
    printf("|\n");
    printf("Pos-ordem: ");
    arv_imprime_posordem(limoeiro);
    printf("|");

    arv_libera(limoeiro);
    return SUCESSO;
}