#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 0

struct lista{
	int info;
	struct lista *prox;
};

typedef struct lista lst; 

typedef struct pilh{
	lst *prim;
} pilha;

// FUNCOES DE LISTA
lst* linit(){
	return NULL;
}

lst* linsert(lst *l, int i){
    lst * novo= (lst* )malloc(sizeof(lst));
    lst * tmp = l;

	novo->info=i;
    novo->prox = NULL;
    if(tmp == NULL){
        novo->prox = tmp;
        return novo;
    }

    if(i > (tmp->info)){
        novo->prox = tmp;
        return novo;
    }

	while(1){
        if(tmp->prox == NULL){
            tmp->prox = novo;
            novo->prox = NULL;
            return l;
        }
        if((tmp->prox->info) <= i){
            novo->prox = tmp->prox;
            tmp->prox = novo;
            return l;
        }
        tmp = tmp->prox;
    }
}

lst * lpop(lst * l){
    lst * tmp = l;
    l = l->prox;
    free(tmp);
    return l;
}

// FUNCOES DE PILHA
pilha * pinit(){
	pilha *p=(pilha *)malloc(sizeof(pilha));
	p->prim = NULL;
	return p;
}

void push(pilha *p, int v){
	lst *l=(lst *)malloc(sizeof(lst));
	l->info=v;
	l->prox=p->prim;
	p->prim=l;
}

int pop(pilha *p){
	lst *l;
	int c;
	if(p->prim==NULL){
		printf("Pilha vazia\n");
		return -1;
	}
	l=p->prim;
	c = l->info;
	p->prim = l->prox;
	free(l);
	return c;
}

void pfree(pilha *p){
	lst *l=p->prim;
	while(l != NULL){
		lst *t = l->prox;
		free(l);
		l=t;
	}
	free(p);
}

// FUNCOES DE FILA

typedef struct filal{
	lst * ini;
	lst * fim;
}Fila;

Fila * finit(){
	Fila *f = (Fila *) malloc(sizeof(Fila));
	f->ini = f->fim = NULL;
	return f;
}


void fpush(Fila *f,int v){
	lst *n = (lst *) malloc(sizeof(lst));
    n->info = v;
    n->prox = NULL;

    lst *tmp = f->ini;
    if(tmp==NULL){
        f->ini = n;
        return;
    }

	while(1){
        if(tmp->prox == NULL){
            tmp->prox = n;
            return;
        }
        tmp = tmp->prox;
    }
}

int fpop(Fila *f){
	lst *t;
	int v;
	if(f->ini == NULL){
		return -1;
	}
	t = f->ini;
	v = t->info;
	f->ini = t->prox;
	if(f->ini==NULL) 
        f->fim = NULL;
	return v;
}

int fvazia(Fila *f){
	return (f->ini == NULL);
}

void ffree(Fila *f){
	lst *q = f->ini;
	while(q!=NULL){
		lst *t = q->prox;
		free(q);
		q = t;
	}
	free(f);
}

// main
int main(){
    int tam, n1, n2;
    FILE * fl;
    Fila * fil;
    pilha * pil;
    lst * lis;
    unsigned char bol[3]= {1, 1, 1};

    fil = finit();
    pil = pinit();
    lis = linit();

    fl = fopen("test.txt", "r");
    if(fl == NULL)
        return 1;

    do{
        fscanf(fl, "%d", &tam);
    for(int i=0;i<tam;i++){
        fscanf(fl, "%d %d", &n1, &n2);
        if(n1 == 1){
            fpush(fil, n2);
            push(pil, n2);
            lis = linsert(lis, n2);
        }
        if(n1 == 2){
            if(bol[0] == 1 && pop(pil) != n2)
                bol[0] = 0;
            if((bol[1] == 1) && (fpop(fil) != n2))
                bol[1] = 0;
            if(bol[2] == 1 && lis->info != n2){
                bol[2] = 0;
            }
            lis = lpop(lis);
        }
    }
    
    

    if((bol[0] == bol[1]) && (bol[1] == bol[2]) && (bol[0] == bol[2])){
        if(bol[0] == 0)
            printf("impossible");
        else
            printf("not sure");
    }
    else
        if((bol[0]  == 1) && (bol[1] == 0) && (bol[2] == 0))
            printf("stack");
        else if((bol[1]) && (bol[0] == 0) && (bol[2] == 0))
            printf("queue");
        else if((bol[2] == 1) && (bol[0] == 0) && (bol[1] == 0)) 
            printf("priority queue");
        else
            printf("not sure");
    printf("\n");

    

    bol[0]=1;
    bol[1]=1;
    bol[2]=1;
    
    while(lis!=NULL){
        lis=lpop(lis);
    }
    pfree(pil);
    ffree(fil);
    fil = finit();
    pil = pinit();
    lis = linit();

    }while(feof(fl)==0);

    return SUCESSO;
}