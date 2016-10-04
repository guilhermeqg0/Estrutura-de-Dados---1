#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "header.h"

void inicPessoa(Pessoa *head){
	*head = NULL;
}

void inicPet(Pet *head){
	*head = NULL;
}

void inicCarro(Carro *head){
	*head = NULL;
}

void cadastrarPessoa(Pessoa *head, char *nome, int idade) { // Realiza o cadastro de uma pessoa.
	Pessoa novo, aux;
	aux = *head;

	if(aux == NULL){
		novo = malloc(sizeof(Pessoa));
		strcpy(novo->nome, nome);
		novo->idade = idade;
		novo->prox = NULL;
		*head = novo;
	}else{
		while(aux->prox != NULL){
			aux = aux->prox;

		}
		
		novo = malloc(sizeof(Pessoa));
		strcpy(novo->nome, nome);
		novo->idade = idade;
		novo->prox = NULL;
		aux->prox = novo;

	}
}

Pessoa acharPessoa(Pessoa *head, char *nome){ // Retorna o endereco do no da pessoa.
	Pessoa aux;
	aux = *head;
	while(aux != NULL){
		if(strcmp(aux->nome, nome) == 0){
			/*printf("%s", aux->nome);
			printf("%d", aux->idade);*/
			return aux;
		}
		aux = aux->prox;
	}

	return NULL;
}


void inserirCarro(Pessoa *head, char *modelo){ //Usar junto com o acharPessoa.
	Pessoa aux = *head;
	Carro aux_car = aux->veiculos;
	Carro novo;

	if(aux_car == NULL){
		novo = (Carro)malloc(sizeof(carro));
		strcpy(novo->modelo, modelo);
		novo->prox = NULL;
		(*head)->veiculos = novo;
	}else{
		while(aux_car->prox != NULL)
			aux_car = aux_car->prox;
	
		novo = (Carro)malloc(sizeof(carro));
		strcpy(novo->modelo, modelo);
		novo->prox = NULL;
		aux_car->prox = novo;
	}


}

void inserirPet(Pessoa *head,char *nome){ //Usar junto com o acharPessoa.
	Pessoa aux = *head;
	Pet aux_pet = aux->animais;
	Pet novo;

	if(aux_pet == NULL){
		novo = malloc(sizeof(pet));
		strcpy(novo->nome, nome);
		novo->prox = NULL;
		(*head)->animais = novo;
	}else{
		while(aux_pet != NULL){
			if(aux_pet->prox == NULL)
				break;

			aux_pet = aux_pet->prox;
		}
		novo = malloc(sizeof(pet));
		strcpy(novo->nome, nome);
		novo->prox = NULL;
		aux_pet->prox = novo;
		

	}
}
void imprimirPessoa(Pessoa *head, char *nome){ // Conforme regras.	
	Pessoa aux;
	Carro aux_car;
	Pet aux_pet;
	aux = acharPessoa(head, nome);
	if(aux == NULL){
		printf("\nNenhum resultado encontrado\n");
		return;
	}


	int cont=0;

	printf("\nNome: %s, Idade: %d anos\n", aux->nome, aux->idade);
	printf("Pets: ");
	aux_pet = aux->animais;
	if(aux_pet != NULL){
		while(aux_pet != NULL){
			if(cont == 0)
				printf("%s", aux_pet->nome);
			else
				printf(", %s", aux_pet->nome);

			aux_pet = aux_pet->prox;
			cont++;	
		}
	}

	cont = 0;
	printf("\nCarros: ");
	aux_car = aux->veiculos;
	if(aux_car != NULL){
		while(aux_car != NULL){
			if(cont == 0)
				printf("%s", aux_car->modelo);
			else
				printf(", %s", aux_car->modelo);

			aux_car = aux_car->prox;
			cont++;	
		}
	}
	printf("\n\n");
}
void libera(Pessoa *head){ // Liberar sublistas tambem.
	Pessoa aux, lixo;
	aux = *head;
	Carro aux_car = aux->veiculos, lixo_car;
	Pet aux_pet = aux->animais, lixo_pet;
	while(aux != NULL){
		lixo = aux;
		aux = aux->prox;
		free(lixo);
	}
	while(aux_car != NULL){
		lixo_car = aux_car;
		aux_car = aux_car->prox;
		free(lixo);
	}
	while(aux_pet != NULL){
		lixo_pet = aux_pet;
		aux_pet = aux_pet->prox;
		free(lixo);
	}
	*head = NULL;

}
