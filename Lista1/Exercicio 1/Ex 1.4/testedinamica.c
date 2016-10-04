/*
 * Exercício 1.2 - Lista dinamica com nó cabeça
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dinamicacircular.h"

int main(){
	Lista l;
	int n=0, count, num, i;

	while((n < 1) || (n > 9999)){
		scanf("%d", &n);
	}
	count = n;
	n = 3*n;

	inicLista(&l);

	srand(time(NULL));

	for (i = 0; i < count; i++){
		num = rand() % n;
		printf("Numero a ser inserido: %d\n", num);
		insereFim(&l, num);
	}

	exibe(&l);
	printf("\n");

	//inverte(&l);
	//exibe(&l);
	//printf("\n");

	//ordena(&l);
	//exibe(&l);
	//printf("\n");

	//media(&l);
	//printf("\n");

}