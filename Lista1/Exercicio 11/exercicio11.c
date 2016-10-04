#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "header.h"

//Com NÓ Cabeça

/* Inicializa uma lista */
void inicLista(Pessoa *p_l){
	p_l->prox = NULL;
}

/* Verifica se a lista está vazia ou nao */
int listaVazia(Pessoa *p_l){
	if(p_l->prox == NULL)
        return 1;

	return 0;
}

/* Insere um elemento no final da lista */
/*void insereFim(Pessoa *p_l, char nome, int idade, char carro, char pet){
	No_lista *novo;

	novo = malloc(sizeof(No_lista));
	strcpy(novo->nome, nome);
	novo->idade = idade;
	strcpy(novo->carro, carro);
	strcpy(novo->pet, pet);
	novo->prox = NULL;

	while(p_l->prox != NULL)
		p_l = p_l->prox;
	p_l->prox = novo;

}*/

void cadastra_usuario(Pessoa *p_l, char nome, int idade){
	No_lista *novo;

	novo = malloc(sizeof(No_lista));
	strcpy(novo->nome, &nome);
	novo->idade = idade;
	novo->prox = NULL;

	while(p_l->prox != NULL)
		p_l = p_l->prox;
	p_l->prox = novo;

}


/* Remove todos os numeros da lista */
void libera(Pessoa *p_l){
	No_lista *aux;

	while (p_l->prox != NULL){
		aux = p_l->prox;
		p_l->prox = aux->prox;
		free (aux);
	}
}

/* Exibe o conteudo da lista */
void exibe(Pessoa *p_l){
	int i;

	while(p_l->prox != NULL){
		printf("Nome: %s, Idade: %d anos", p_l->prox->nome, p_l->prox->idade);
		printf("\nPets: ");
		for(i=0; i < p_l->prox->n_pet; i++){
			if(i == 0)
				printf("%s", p_l->prox->pet[i]);
			else
				printf(", %s", p_l->prox->pet[i]);
		}

		printf("\nCarros: ");
		for(i=0; i < p_l->prox->n_car; i++){
			if(i == 0)
				printf("%s", p_l->prox->carro[i]);
			else
				printf(", %s", p_l->prox->carro[i]);
		}


		p_l = p_l->prox;
	}
	printf("\n");
}
/*
void transfere_lista(Lista *p_l, Lista *p_l1, Lista *p_l2){
    if(listaVazia(p_l1) || listaVazia(p_l2))
        return;

    while(p_l1->prox != NULL){
        insereFim(p_l, p_l1->prox->info);
        p_l1 = p_l1->prox;
    }

    while(p_l2->prox != NULL){
        insereFim(p_l, p_l2->prox->info);
        p_l2 = p_l2->prox;
    }

    ordena(p_l);
}

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

void strcpy_lista(Lista *p_l1, Lista *p_l2){

	while(p_l2->prox != NULL){

		insereFim(p_l1, p_l2->info);

		p_l2 = p_l2->prox;
	}

	exibe(p_l1);

}

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

}*/