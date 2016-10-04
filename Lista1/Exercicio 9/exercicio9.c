#include <stdlib.h>
#include <stdio.h>
#include "exercicio9.h"

/* Inicializa uma lista */
void inicLista(Lista *p_l){
	p_l->prox=NULL;
}

/* Verifica se a lista está vazia ou nao */
int listaVazia(Lista *p_l){
	if(p_l->prox==NULL) return 1;
	return 0;
}


/* Insere um elemento na lista de maneira ordenada.
   Caso a lista nao esteja ordenada, ordena antes da insercao */
void insereOrdenado(Lista *p_l, elem_t e, elem_t e2){
	No_lista *novo_no;
	novo_no = (No_lista *) malloc(sizeof(No_lista));
	
	novo_no->exp = e;
	novo_no->mult = e2;

	if(listaVazia(p_l)){
		p_l->prox = novo_no;
		novo_no->prox = NULL;
	}else{
		printf("1\n");
		while(p_l->prox != NULL && p_l->prox->exp < e){
			printf("2\n");
			p_l = p_l->prox;
		}

		if(p_l->prox != NULL && p_l->prox->exp == e){
			p_l->prox->mult = p_l->prox->mult + e2;
			printf("3\n");
		}else{
			novo_no->prox = p_l->prox;
			p_l->prox = novo_no;
			printf("4\n");
		}	
	}

}

void insereFim(Lista *p_l, elem_t e, elem_t e2){
	No_lista *novo_no;
	
	while(p_l->prox != NULL){
		if(p_l->prox->exp == e){
			printf("1\n");
			p_l->prox->mult = p_l->prox->mult + e2;
			return;
		}
		p_l = p_l->prox;
	}


	novo_no = malloc(sizeof(No_lista));
	novo_no->exp = e;
	novo_no->mult = e2;
	novo_no->prox = NULL;
	
	
	p_l->prox = novo_no;

}

/* Remove todos os numeros da lista */
void libera(Lista *p_l){
	No_lista *aux;

	if (listaVazia(p_l))
		return;
	
	aux = p_l->prox;
	p_l = p_l->prox;
	while(1){	
		if (p_l->prox != NULL){
			p_l = p_l->prox;
			free(aux);
			aux = p_l;
		}else{
			free(aux);
			return;
		}
	}
}

/* Exibe o conteudo da lista */
void exibe(Lista *p_l){
	if (listaVazia(p_l))
		return;

	while(p_l->prox != NULL){
		printf("+(%dx^%d)", p_l->prox->mult, p_l->prox->exp);
		p_l = p_l->prox;
	}
}

Lista soma(Lista *p_l1, Lista *p_l2, Lista *p_l3){
	int exp1, exp2, mult1, mult2;
	No_lista *aux1, *aux2;

	exibe(p_l1);printf("\n");
	exibe(p_l2);printf("\n");

	aux1 = p_l1;
	aux2 = p_l2;
	while(aux1->prox != NULL || aux2->prox != NULL){
		
		if (aux1->prox != NULL){
			exp1 = aux1->prox->exp;
			mult1 = aux1->prox->mult;
			aux1->prox = aux1->prox->prox;
			insereFim(p_l3, exp1, mult1);
		}

		if (aux2->prox != NULL){
			exp2 = aux2->prox->exp;
			mult2 = aux2->prox->mult;
			aux2->prox = aux2->prox->prox;
			insereFim(p_l3, exp2, mult2);	
		}
	}
	return *p_l3;
}














