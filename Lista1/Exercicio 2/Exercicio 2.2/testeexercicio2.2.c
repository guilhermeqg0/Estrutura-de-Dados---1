//
// Exercício 2.2
//

#include <stdlib.h>
#include <stdio.h>
#include "exercicio2.2.h"

int main(){
	Lista l1, l2;
	int qnt, i, num;
	
	inicLista(&l1);
	inicLista(&l2);


	printf("Insira a quantidade de números da primeira lista:\n");
	fflush(stdin);
	scanf("%d", &qnt);
	insereFim(&l1, qnt);
	printf("\n");
	for (i = 0; i < qnt; ++i){
		printf("Insira o número:\n");
		fflush(stdin);
		scanf("%d", &num);
		insereFim(&l1, num);
	}
	printf("\n");

	printf("Insira a quantidade de números da segunda lista:\n");
	fflush(stdin);
	scanf("%d", &qnt);
	insereFim(&l2, qnt);
	printf("\n");
	for (i = 0; i < qnt; ++i){
		printf("Insira o número:\n");
		fflush(stdin);
		scanf("%d", &num);
		insereFim(&l2, num);
	}
	printf("\n");

	concatena(&l1, &l2);

	return 0;
}