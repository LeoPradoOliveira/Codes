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


///////////////Funções do exercício///////////////


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



int main(int argc, char ** argv){
    Arv* limoeiro;
    limoeiro = arv_criavazia();


    limoeiro = arv_insere(limoeiro, 'a');
    limoeiro = arv_insere(limoeiro, 'b');
    limoeiro = arv_insere(limoeiro, 'c');
    limoeiro = arv_insere(limoeiro, 'd');
    limoeiro = arv_insere(limoeiro, 'e');
    limoeiro = arv_insere(limoeiro, 'f');
    limoeiro = arv_insere(limoeiro, 'g');
    limoeiro = arv_insere(limoeiro, 'h');
    limoeiro = arv_insere(limoeiro, 'i');
    limoeiro = arv_insere(limoeiro, 'a');  

    printf("\nArvore printada simetricamente:\n");
    arv_imprime_simetrica(limoeiro);
    printf("|\n");
    printf("Folhas da arvore: %d\n",arv_num_folhas(limoeiro));
    printf("Galhos de um no: %d\n",galho_de_um_no(limoeiro));
    printf("Galhos de dois nos: %d\n",galho_de_dois_no(limoeiro));

    printf("\n");

    arv_libera(limoeiro);
    return SUCESSO;
}