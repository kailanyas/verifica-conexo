#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

//funcao que retorna um ponteiro que aponta para uma vetor de ponteiros
int **CriaMatriz(int num_Vertices){
    int **matriz = malloc(num_Vertices * sizeof(int*));
    return matriz;
}

//funcao que aloca espaço para as colunas da matriz
void AlocaMatriz(int **matriz, int num_Vertices) {
    int i;
    for (i = 0; i < num_Vertices; i++) {
        matriz[i] = malloc(num_Vertices * sizeof(int));
    }
}

//funcao que atribui zero para todos os elementos da matriz
void ZeraMatriz(int **matriz, int num_Vertices) {
    int i, j;
    for (i = 0; i < num_Vertices; i++) {
        for (j = 0; j < num_Vertices; j++) {
            matriz[i][j] = 0;
        }
    }
}

//funcao que imprime a matriz (feita para testes)
void ImprimeMatriz(int **matriz, int num_Vertices) {
    int i, j;
    for (i = 0; i < num_Vertices; i++) {
        for (j = 0; j < num_Vertices; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

//funcao que preenche a matriz de adjacencia de acordo com o arquivo de entrada
void InsereMatriz(int **matriz, FILE* arq) {
    int i=0, temp=0, aux=0;
    while (fscanf(arq, "%d %d", &temp, &aux) == 2){
        matriz[temp-1][aux-1] = 1;
        matriz[aux-1][temp-1] = 1;
        i++;
   }
}

//conta o numero de componentes
int BProfundidade(int **matriz, int num_Vertices) {
    int cont = 0, Visit[num_Vertices], i;
    for (i = 0; i < num_Vertices; i++){
        Visit[i] = -1;
    }
    for (i = 0; i < num_Vertices; i++) {
        if (Visit[i] == -1) {
            cont++;
            BP(matriz, num_Vertices, i, Visit, cont);
        }
    }

    return cont;
}

//função auxiliar que realiza a busca em profundidade
void BP(int **matriz, int num_Vertices, int v, int Visit[], int cont) {
    Visit[v] = cont;
    int j;
    for(j = 0; j < num_Vertices; j++) {
        if (matriz[v][j] == 1 && Visit[j] == -1) {
            BP(matriz, num_Vertices, j, Visit, cont);
        }
    }
}


