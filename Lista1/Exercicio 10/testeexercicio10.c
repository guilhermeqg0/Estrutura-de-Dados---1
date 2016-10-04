//
// Exercício 10
//

#include <stdlib.h>
#include <stdio.h>
#include "exercicio10.h"

int main(){
	Lista l1, l2, l3;
	int qnt, i, num;
	
	inicLista(&l1);
	inicLista(&l2);
	inicLista(&l3);


	printf("Insira a quantidade de números da primeira lista:\n");
	fflush(stdin);
	scanf("%d", &qnt);
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
	printf("\n");
	for (i = 0; i < qnt; ++i){
		printf("Insira o número:\n");
		fflush(stdin);
		scanf("%d", &num);
		insereFim(&l2, num);
	}
	printf("\n");

	l3 = intersecciona(&l1, &l2, &l3);

	exibe(&l3);
	printf("\n");

	return 0;
}