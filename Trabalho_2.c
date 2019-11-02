// Informações do estudante
// Nome: Gabriel Rodrigues Malaquias
// Curso: Bacharelado em Ciência da Computação
// RA:  758906

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void swap_vec(double *v, int pos1, int pos2) {

    double aux = v[pos1];
    v[pos1] = v[pos2];
    v[pos2] = aux;
    
}

int particao(double *v, int ini, int fim) {

    // pegar o do meio
    // se estiver ordenado, otimo
    // se estiver aleatorizado, tanto faz, certo?
    int pivo = (ini+fim)/2;
    
    swap_vec(v, ini, pivo);    
    pivo = ini;
    
    int i, j;
    i = ini + 1;
    j = fim - 1;
    
    while(i <= j) {
    
        while(i < fim && v[i] <= v[pivo]) i++;
        while(v[j] > v[pivo]) j--;
        
        if (i < j)
            swap_vec(v, i, j);
    
    }
    
    //if (v[j] < v[pivo]) j = pivo;
    swap_vec(v, pivo, j);
    
    return j;

}

void kselect(double *v, int ini, int fim, int k) {

    
    //caso base
    if (ini >= fim) return; 
    
    int j = particao(v, ini, fim);
    if (j == k) return;
    if (k < j)
        kselect(v, ini, j, k);
    else
        kselect(v, j+1, fim, k );
    
    return;

}

int main(int argc, char *argv[])
{
    char file_name[MAX];
    double **v, limiar;
    int n, k, i, j;
    FILE *entrada;

    scanf("%s", file_name);
    entrada = fopen(file_name, "r");
    if (entrada == NULL)
    {
        printf("\nNão encontrei o arquivo!\n");
        exit(EXIT_FAILURE);
    }
    fscanf(entrada, "%d %d %lf", &n, &k, &limiar);
    v = (double **)malloc(n * sizeof(double *));
    for (i = 0; i < n; i++)
    {
        v[i] = (double *)malloc(n * sizeof(double));
        for (j = 0; j < n; j++)
            fscanf(entrada, "%lf", &v[i][j]);
    }
    fclose(entrada);
	
	int qtd_out = 0;
	for(i = 0; i < n; i++){
		kselect(v[i], 0, n, k+1);
		/*for(int z = 0; z<n; z++){
			printf("%lf ", v[i][z]);
		}
		printf("\n");*/
		if(v[i][k+1] > limiar)
			qtd_out++;
	}
	printf("%d\n", qtd_out);
	
    for (i = 0; i < n; i++)
        free(v[i]);
    free(v);

    return 0;
}
