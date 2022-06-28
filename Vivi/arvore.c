#include "arvore.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

Arv* arv_criavazia(){return NULL;}

Arv* arv_cria(char valor,Arv* esq,Arv* dir){
	Arv *raiz = (Arv*) malloc(sizeof(Arv));
	raiz->info =valor;
	raiz->esq = esq;
	raiz->dir = dir;	
	return raiz;
}

int arv_vazia(Arv* a){
	return (a == NULL);	
}

void arv_imprime_preordem(Arv* a){
	if(!arv_vazia(a)){
		printf("%c\t",a->info);
		arv_imprime_preordem(a->esq);
		arv_imprime_preordem(a->dir);
	}
}

void arv_imprime_simetrica(Arv* a){
	if(!arv_vazia(a)){
		arv_imprime_simetrica(a->esq);
		printf("%c\t",a->info);
		arv_imprime_simetrica(a->dir);
	}
}

void arv_imprime_posordem(Arv *a){
	if(!arv_vazia(a)){
		arv_imprime_posordem(a->esq);
		arv_imprime_posordem(a->dir);
		printf("%c\t",a->info);
	}
}

Arv* arv_libera(Arv* a){
	if(!arv_libera(a)){
		arv_libera(a->esq);
		arv_libera(a->dir);
		free(a);
	}
	return NULL;
}

int arv_pertence(Arv* a,char v){
	if(arv_vazia(a))	return 0;
	else return a->info == v || arv_pertence(a->esq,v) || arv_pertence(a->dir,v);
}

static int max2(int a,int b){
	return (a>b) ? a : b ;
}

int arv_altura(Arv *a){
	if(arv_vazia(a))
		return -1; 
	else 
		return 1 + max2 (arv_altura(a->esq),arv_altura(a->dir));
}

//ARVORE COM FILHOS VARIAVEIS

ArvVar *arvv_cria(int v){
	ArvVar *a = (ArvVar*) malloc (sizeof(ArvVar));
	a->info = v;
	a->filho = NULL;
	a->irmao = NULL;
	return a;
}

void arvv_insere(ArvVar *r,ArvVar *inserido){
	inserido->irmao = r->filho;
	r->filho = inserido;
}

void arvv_imprime(ArvVar *a){
	ArvVar *p;
	printf("%i\t",a->info);
	for(p=a->filho;p!=NULL;p=p->irmao)
		arvv_imprime(p);
}

int arvv_pertence(ArvVar *a,int v){
	ArvVar *p;
	if(a->info ==v)
		return 1;
	else{
		for(p=a->filho;p!=NULL;p=p->irmao){
			if(arvv_pertence(p,v))
			return 1;
		}
		return 0;
	}
}

void arvv_libera(ArvVar *a){
	ArvVar *p = a->filho;
	while(p!=NULL){
		ArvVar *t = p->irmao;
		arvv_libera(p);
		p=t;
	}
	free(a);
}

int arvv_altura(ArvVar *a){
	int hmax = -1;
	ArvVar *p;

	for(p=a->filho;p!=NULL;p=p->irmao){
		int h = arvv_altura(p);
		if(h>hmax) hmax = h;
	}
	return hmax +1;
}