// Informações do estudante
// Nome: Gabriel Rodrigues Malaquias
// Curso: Bacharelado em Ciência da Computação
// RA:  758906

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM 256

int main() {
	char file_name[TAM];
	int tamSeq, tamRui;
	FILE *entrada;
	
	scanf("%s", file_name);
    entrada = fopen(file_name, "r");
    if (entrada == NULL)
    {
        printf("\nNão encontrei o arquivo!\n");
        exit(EXIT_FAILURE);
    }
	fscanf(entrada, "%d %d\n", &tamSeq, &tamRui);
	
	//printf("Tamseq: %d\nTamrui:%d\n", tamSeq, tamRui);
	
	char Sequencia[tamSeq], Ruido[tamRui];
	
	for(int i=0; i < tamSeq; i++){
		Sequencia[i] = getc(entrada);
	}
	getc(entrada);
	getc(entrada);
	for(int i=0; i < tamRui; i++){
		Ruido[i] = getc(entrada);
	}
	
	//printf("Sequencia: %s\nRuido: %s\n", Sequencia, Ruido);
	
    //char txt[] = "AABABACABABBAAAABAAABABACABABCDABABCCBACABABACAAAABABACABABBACABA"; 
    //char pat[] = "ABABACABAB";
    
    int i, j;
    //int m = strlen(pat), n = strlen(txt);
    
    for (i = 0; i < tamSeq; i++) {
        for (j = 0; j < tamRui && Sequencia[i+j]==Ruido[j]; j++);
        if (j == tamRui) printf("%d\n", i);
    }
            

}