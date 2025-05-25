#ifndef MATRIZ_H
#define MATRIZ_H

int **CriaMatriz(int num_Vertices);

void AlocaMatriz(int **matriz, int num_Vertices);

void ZeraMatriz(int **matriz, int num_Vertices);

void ImprimeMatriz(int **matriz, int num_Vertices);

void InsereMatriz(int **matriz, FILE* arq);

int BProfundidade(int **matriz, int num_Vertices);

void BP(int **matriz, int num_Vertices, int vertice, int Visit[], int cont);



#endif
