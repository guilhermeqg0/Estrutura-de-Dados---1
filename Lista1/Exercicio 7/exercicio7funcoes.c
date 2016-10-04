#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Função STRLEN

int strlen_lista(Lista *p_l){
	int cont=0;

	if(listaVazia(p_l))
		return 0;

	while(p_l->prox != NULL){
		cont++;
		p_l = p_l->prox;
	}

	return cont;
}


//Função STRCMP

void strcmp_lista(Lista *p_l1, Lista *p_l2){

	int cont1, cont2, cmp;

	cont1 = strlen_lista(p_l1);
	cont2 = strlen_lista(p_l2);
	cmp = cont1 / cont2;
	if(cmp < 0)
		printf("Palavra 2 MAIOR que Palavra 1");
	else if(cmp > 0)
		printf("Palavra 1 MAIOR que Palavra 2");
	else
		printf("Palavras Iguais");

}

//Função STRCPY

void strcpy_lista(Lista *p_l1, Lista *p_l2){

	while(p_l2->prox != NULL){

		insereFim(p_l1, p_l2->info);

		p_l2 = p_l2->prox;
	}

	exibe(p_l1);

}

//Função STRCAT

void strcat_lista(Lista *p_l1, Lista *p_l2){
	Lista *p_l3;
	p_l3 = malloc(sizeof(No_lista));

	while(p_l1->prox != NULL){

		insereFim(p_l3, p_l1->info);

		p_l1 = p_l1->prox;
	}


	while(p_l2->prox != NULL){

		insereFim(p_l3, p_l2->info);

		p_l2 = p_l2->prox;
	}

	exibe(p_l3);

}
