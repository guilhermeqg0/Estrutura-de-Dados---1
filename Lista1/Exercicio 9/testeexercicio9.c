//
// Exercício 10
//

#include <stdlib.h>
#include <stdio.h>
#include "exercicio9.h"

int main(){
	Lista l1, l2, l3;
	int i, n, m, termos;
	
	inicLista(&l1);
	inicLista(&l2);
	inicLista(&l3);

	printf("Quantos termos tem o PRIMEIRO polinomio ?:\n");
	scanf("%d", &termos);
	printf("Insira o PRIMEIRO polinomio termo a termo no modelo:\n");
	printf("'N M' - Sendo n o multiplo e m o expoente de x.\n");
	printf("Aperte enter para terminar a inserção.\n");
	i = 0;
	while(i < termos){
		scanf("%d", &n);
		fflush(stdin);
		scanf("%d", &m);
		fflush(stdin);
		insereOrdenado(&l1, m, n);
		i++;
	}

	printf("\n");

	printf("Quantos termos tem o SEGUNDO polinomio ?:\n");
	scanf("%d", &termos);
	printf("Insira o SEGUNDO polinomio termo a termo no modelo:\n");
	printf("'N M' - Sendo n o multiplo e m o expoente de x.\n");
	printf("Aperte enter para terminar a inserção.\n");
	i = 0;
	while(i < termos){
		scanf("%d", &n);
		fflush(stdin);
		scanf("%d", &m);
		fflush(stdin);
		insereOrdenado(&l2, m, n);
		i++;
	}

	l3 = soma(&l1, &l2, &l3);

	exibe(&l3);printf("\n");

	

	return 0;
}
