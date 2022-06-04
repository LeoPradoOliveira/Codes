#include <stdio.h>
#include <stdlib.h>
#include "fila.h"



static int incr(int i){
	return (i+1)%N;
}

Fila *fila_cria_vet(){
	Fila *f = (Fila *) malloc(sizeof(Fila));
	f->n = 0;
	f->ini = 0;
	return f;
}

void fila_insere_vet(Fila *f, float v){
	int fim;
	if(f->n == N){
		printf("Capacidade da fila estourou\n");
		exit(1);
	}
	fim = (f->ini + f->n)%N;
	f->vet[fim] = v;
	f->n++;
}

float fila_retira_vet(Fila *f){
	float v;
	if(fila_vazia_vet(f)){
		printf("Fila vazia!\n");
		exit(1);
	}
	v=f->vet[f->ini];
	f->ini = (f->ini + 1) % N;
	f->n--;
	return v;
}

int fila_vazia_vet(Fila *f){
	return (f->n == 0);
}

void fila_libera_vet(Fila *f){
	free(f);
}


// Lista encadeada
FilaL *fila_cria_l(){
	FilaL *f = (FilaL *) malloc(sizeof(FilaL));
	f->ini = f->fim = NULL;
	return f;
}

void fila_insere_l(FilaL *f,char *v){
	Lista *n = (Lista *) malloc(sizeof(Lista));
	int i;
	for(i=0;i<20;i++) n->info[i]=v[i];
	n->prox = NULL;
	if(f->fim != NULL) f->fim->prox = n;
	else f->ini = n;
	f->fim = n;
}

char *fila_retira_l(FilaL *f){
	Lista *t;
	char *v;
	if(fila_vazia_l(f)){
		printf("Fila vazia!");
		exit(1);
	}
	t = f->ini;
	v = t->info;
	f->ini = t->prox;
	if(f->ini==NULL) f->fim = NULL;
	free(t);
	return v;
}

int fila_vazia_l(FilaL *f){
	return (f->ini == NULL);
}

void fila_libera_l(FilaL *f){
	Lista *q = f->ini;
	while(q!=NULL){
		Lista *t = q->prox;
		free(q);
		q = t;
	}
	free(f);
}

Lista* fila_busca_l(FilaL *fila, char informacao[]){
	Lista *q;
	for(q=fila->ini; q!=NULL; q=q->prox){
		if(strcmp(informacao, q->info)==0){
			return q;
		}
	}
	return NULL;
}

// Funções de impressão

void fila_imprime_vet(Fila *f){
	int i;
	for(i=0;i<f->n; i++) printf("%f \n", f->vet[(f->ini+i)%N]);
}

void fila_imprime_l(FilaL *f){
	Lista *q;
	for(q=f->ini; q!= NULL; q=q->prox) printf("\t%s\n",q->info);
}
