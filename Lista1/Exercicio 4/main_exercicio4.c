// Exercício 4

#include <stdio.h>
#include "exercicio4.h"

int main()
{
	Lista l;
	int i, palavra = 1, qnt_pesquisas, pos;
	char letra;


	inicLista(&l);

	printf("\n");
	printf("Insira as palavras.\n");

	__fpurge(stdin); 
	for (i = 0; i < 200; ++i)
	{
		scanf("%c", &letra);
		if (letra == ' ')
			palavra++;

		if (letra == '\n')
			i = 200;

		insereFim(&l, letra);
	}

	printf("\n");
	printf("Insira o número de consultas que você quer fazer:\n");
	__fpurge(stdin);
	scanf("%d", &qnt_pesquisas);


	for (i = 0; i < qnt_pesquisas; ++i){
		printf("Insira a posição da palavra que deseja realizar a busca:\n");
		__fpurge(stdin);
		scanf("%d", &pos);
		if(pos > palavra){
			printf("Numero Invalido!\n");
			i--;
		}else{
			exibe(&l, pos);
			printf("\n");
		}	
	}

	libera(&l);

	return 0;
}