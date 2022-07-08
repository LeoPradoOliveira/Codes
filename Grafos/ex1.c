#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define EL_MAIA 0

int **aloca_matriz(int **a, int tam){
    int col;

    a = malloc(tam * sizeof(int *));
    for (col = 0; col < tam; col++){
        a[col] = malloc(tam * sizeof(int));
    }

    return a;
}

void free_matriz(int **a, int tam){
    int lin;

    for (lin = 0; lin < tam; lin++){
        free(a[lin]);
    }

    free(a);
}

int **preenche_matriz(int **a, int tam){
    srand(time(NULL));
    int lin, col;

    for (lin = 0; lin < tam; lin++){
        for (col = 0; col < tam; col++){
            a[lin][col] = rand() % 2;
        }
    }
    return a;
}

void imprime_matriz(int **a, int tam){
    int lin, col;

    printf("╔════════════════════════════════╗\n");
    printf("║      Matriz de Adjacencias     ║\n");
    printf("╚════════════════════════════════╝\n");

    for (lin = 0; lin < tam; lin++){
        printf("|");
        for (col = 0; col < tam; col++){
            printf("%d", a[lin][col]);
        }
        printf("|\n");
    }
}

void conta_grau(int **a, int tam){
    int *vertices;
    int lin, col;

    vertices = malloc(tam * sizeof(int));

    for (col = 0; col < tam; col++){
        for (lin = 0; lin < tam; lin++){
            vertices[col] += a[lin][col];
        }
    }
    printf("╔════════════════════════════════╗\n");

    for (col = 0; col < tam; col++){
        printf("║ Grau do %2d° vertice: %2d        ║\n", col + 1, vertices[col]);
    }
    printf("╚════════════════════════════════╝\n");
}

int main(int argc, char **argv){
    int **garfo;
    int tam;

    //Dinamiza o tamanho do grafo-matriz
    printf("╔════════════════════════════════╗\n");
    printf("║ Quantidade de nos do grafo:    ");
    printf("║\n╚════════════════════════════════╝\n");
    scanf(" %d", &tam);

    // Aloca o grafo-matriz
    garfo = aloca_matriz(garfo, tam);

    // Preenche o grafo-matriz aleatoriamente
    garfo = preenche_matriz(garfo, tam);

    // Imprime o grafo-matriz
    imprime_matriz(garfo, tam);

    // Calcula o resultado do problema
    conta_grau(garfo, tam);

    // Libera o grafo
    free_matriz(garfo, tam);

    return EL_MAIA;
}