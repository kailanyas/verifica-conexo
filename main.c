#include<stdio.h>
#include<stdlib.h>
#include "matriz.h"

//verifica se a promessa foi cumprida ou não, de acordo com o numero de componentes
void VerificaEstrada(int componentes) {
    if (componentes == 1) {
        printf("PROMESSA CUMPRIDA\n");
    }
    else {
        printf("FALTAM %d ESTRADAS\n", componentes-1);
    }
}

int main(int argc, char *argv[])
{
    int num_Vertices = 0, num_Arestas = 0, aux, temp;
    
    if(argc < 2) {
    	printf("Digite o nome do arquivo\n");
    }
    else {
    	char *arquivo = argv[1];
		FILE *arq = fopen(arquivo, "r");
		if (arq == NULL) {
		    perror("Erro ao abrir o arquivo");
		    return EXIT_FAILURE;
		}
		
		if((fscanf(arq, "%d", &num_Vertices)) == -1) {
			printf("Arquivo vazio\n");
			exit(0);
		}
		
		fscanf(arq, "%d", &num_Arestas);
		
		int **matriz = CriaMatriz(num_Vertices);
		AlocaMatriz(matriz, num_Vertices);
		ZeraMatriz(matriz, num_Vertices);
		InsereMatriz(matriz, arq);
		fclose(arq);
		
		int componentes = BProfundidade(matriz, num_Vertices);
		VerificaEstrada(componentes);
	}
}
