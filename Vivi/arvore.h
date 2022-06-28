//ARVORE BINARIA
struct arv{
	char info;
	struct arv *esq;
	struct arv *dir;
};

typedef struct arv Arv;

Arv* arv_criavazia(void);
Arv* arv_cria(char valor,Arv* esq,Arv* dir);
Arv* arv_libera(Arv* a);
int arv_vazia(Arv* a);
int arv_pertence(Arv* a,char v);
void arv_imprime_preordem(Arv* a);
void arv_imprime_simetrica(Arv* a);
void arv_imprime_posordem(Arv* a);

static int max2(int a,int b);
int arv_altura(Arv *a);

//ARVORE COM FILHOS VARIADOS

struct arvvar{
	int info;
	struct arvvar *filho;
	struct arvvar *irmao;
};

typedef struct arvvar ArvVar;

ArvVar *arvv_cria(int v);
void arvv_insere(ArvVar *r,ArvVar *inserido);
void arvv_imprime(ArvVar *a);
int arvv_pertence(ArvVar *a,int v);
void arvv_libera(ArvVar *a);
int arvv_altura(ArvVar *a);