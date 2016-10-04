#include <stdlib.h>
#include <stdio.h>
#include "header.h"

int main(){
	Pessoa p, aux;
	Carro c;
	Pet pt;
	int op, i;
	char nome[50], modelo[50], nome_pet[50];
	int idade;

	inicPessoa(&p);

	do{
		printf("Escolha a opcao desejada\n");

		printf("1. Cadastrar Pessoa\n2. Cadastrar animal\n3. Cadastrar Carro\n4. Imprimir pessoa\n5. Liberar lista(s) e Sair\n");
		scanf("%d", &op);
		__fpurge(stdin);

		switch(op){
			//Cadastrar Pessoa
			case 1: 
				//gets(nome);
				scanf("%[^\n]", nome);
				__fpurge(stdin);
				scanf("%d", &idade);
				cadastrarPessoa(&p, nome, idade);
			break;

			//Cadastrar animal
			case 2:
				scanf("%[^\n]", nome);
				__fpurge(stdin);
				aux = acharPessoa(&p, nome);
				if(aux == NULL){
					printf("Pessoa nao encontrada!");
				}else{
					scanf("%[^\n]", nome_pet);
					__fpurge(stdin);
					inserirPet(&aux, nome_pet);
				}
			break;

			//Cadastrar carro
			case 3:
				scanf("%[^\n]", nome);
				__fpurge(stdin);
				aux = acharPessoa(&p, nome);
				if(aux == NULL){
					printf("Pessoa nao encontrada!");
				}else{
					scanf("%[^\n]", modelo);
					__fpurge(stdin);
					inserirCarro(&aux, modelo);
				}
				
			break;

			//Imprimir pessoa
			case 4:
				scanf("%[^\n]", nome);
				__fpurge(stdin);
				imprimirPessoa(&p, nome);
			break;

			//Liberar e imprimir listas
			case 5:
				libera(&p);
				return 0;
			break;
		}
	}while(1);

}