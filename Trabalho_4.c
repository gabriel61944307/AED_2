// Informações do estudante
// Nome: Gabriel Rodrigues Malaquias
// Curso: Bacharelado em Ciência da Computação
// RA:  758906

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

void relaxa(int** grafo, int vertice, int qtd_vertices, int* peso, int* aberto){
	for(int i = 0; i < qtd_vertices; i++){
		if(grafo[vertice][i] != -1 && aberto[i] == 1){
			if(peso[i] == -1 && peso[vertice] != -1){
				peso[i] = grafo[vertice][i] + peso[vertice];
			}
			else if(peso[i] == -1 && peso[vertice] == -1){
				peso[i] = grafo[vertice][i];
			}
			else if(((peso[vertice] + grafo[vertice][i]) < peso[i])){
				peso[i] = peso[vertice] + grafo[vertice][i];
			}
		}
	}
	aberto[vertice] = 0;
}

int menorPeso(int* peso, int tam, int* aberto){
	int menor = INT_MAX;
	int posmenor = 0;
	for(int i = 0; i < tam; i++){
		if(peso[i] != -1 && peso[i] < menor && aberto[i] == 1){
			menor = peso[i];
			posmenor = i;
		}
	}
	return posmenor;
}

int main(){
	int qtd_vertices = 0, qtd_arestas = 0, A = 0, B = 0, W = 0;
	scanf("%d %d", &qtd_vertices, &qtd_arestas);
	int aberto[qtd_vertices], peso[qtd_vertices];

	int **grafo=(int**)malloc(qtd_vertices*sizeof(int*));
    for(int i=0; i<qtd_vertices; i++){
        grafo[i]=(int*)malloc(qtd_vertices*sizeof(int));
	}

	for(int i = 0; i < qtd_vertices; i++){
		for(int j = 0; j < qtd_vertices; j++){
			grafo[i][j] = -1;
		}
	}
	for(int i = 0; i < qtd_vertices; i++){
		aberto[i] = 1;
	}
	memset(peso, -1, sizeof(peso));


	for(int i = 0; i < qtd_arestas; i++){
		scanf("%d", &A);
		scanf("%d", &B);
		scanf("%d", &W);
		if((grafo[A][B] != -1) && (W < grafo[A][B]) && (A != B)){
			grafo[A][B] = W;
		}
		else if((grafo[A][B] == -1) && (A != B))
			grafo[A][B] = W;
	}



	relaxa(grafo, 0, qtd_vertices, peso, aberto);
	aberto[0] = 0;

	while(aberto[qtd_vertices-1]){
		int i = menorPeso(peso, qtd_vertices, aberto);
		relaxa(grafo, i, qtd_vertices, peso, aberto);
	}

	printf("%d\n", peso[qtd_vertices-1]);

	return 0;
}
