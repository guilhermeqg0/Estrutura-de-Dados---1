#include "estatica.h"
#include <stdio.h>

// Inicializa o vetor
void inicia (vet *v){
	v->tam = 0;
}

// Insere um elemento no final do vetor. Retorna 1 se a inserçao ocorreu com sucesso ou 0 caso contrario.
int insere (vet *v, elem_t n){
	if (cheio(*v))
	{
		return 0;
	}
	v->item[v->tam++] = n;
	return 1;
}

// Retorna 1 caso o vetor esteja cheio ou 0 caso contrario
int cheio (vet v){
	if (v.tam == MAX)
		return 1;
	return 0;
}

// Printa todos os itens do vetor
void printa(vet *v){
	int i;

	for (i = 0; i < v->tam; ++i){
		printf("%d ", v->item[i]);
	}
}

// Printa todos os itens do vetor de forma invertida
void printaInvertido(vet *v){
	int i;

	for (i = v->tam; i > 0; --i){
		printf("%d ", v->item[i-1]);
	}
}

// Ordena de forma crescente todos os itens do vetor
void ordena(vet *v){
	int i, j, aux;

	for (i = 0; i < v->tam; ++i){
		for (j = 0; j < v->tam; ++j){
			if(v->item[i] < v->item[j]){
				aux = v->item[i];
				v->item[i] = v->item[j];
				v->item[j] = aux;
			}			
		}
	}

}

// Printa a media da soma de todos os itens do vetor
void media(vet *v){
	int i;
	float media, soma = 0;

	for (i = 0; i < v->tam; ++i){
		soma = soma + v->item[i];
	}
	
	media = soma/v->tam;
	printf("%.2f", media);

}

