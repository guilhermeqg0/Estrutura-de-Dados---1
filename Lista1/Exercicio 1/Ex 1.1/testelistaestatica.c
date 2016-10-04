/*
 * Exercício 1.1 - Lista Estática
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "estatica.h"

int main(){
	vet v;
	int n=0, count, item, i;

	while((n < 1) || (n > 9999)){
		scanf("%d", &n);
	}
	count = n;
	n = 3*n;

	inicia(&v);

	srand(time(NULL));

	for (i = 0; i < count; i++){
		item = rand() % n;
		insere(&v, item);
	}

	printa(&v);
	printf("\n");

	printaInvertido(&v);
	printf("\n");

	ordena(&v);
	printa(&v);
	printf("\n");

	media(&v);
	printf("\n");

}