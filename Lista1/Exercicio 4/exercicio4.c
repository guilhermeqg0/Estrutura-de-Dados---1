#include <stdlib.h>
#include <stdio.h>
#include "exercicio4.h"

/* Inicializa uma lista */
void inicLista(Lista *p_l){
	p_l->prox=NULL;
}

/* Verifica se a lista está vazia ou nao */
int listaVazia(Lista *p_l){
	if(p_l->prox==NULL) return 1;
	return 0;
}

/* Insere um elemento no final da lista */
void insereFim(Lista *p_l, elem_t e){
	No_lista *novo_no;
	
	novo_no = malloc(sizeof(No_lista));
	novo_no->info = e;
	novo_no->prox = NULL;
	
	while(p_l->prox != NULL)
		p_l = p_l->prox;
	p_l->prox = novo_no;

}


/* Remove todos os numeros da lista */
void libera(Lista *p_l){
	No_lista *aux;
	
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
void exibe(Lista *p_l, int pos){
	int indice = 1;

	while(p_l->prox != NULL){
		if(indice == pos){
			printf("%c", p_l->prox->info);
			p_l = p_l->prox;
			if (p_l->prox != NULL){
				if (p_l->prox->info == ' ')
					indice++;
			}
		}else{
			if (p_l->prox->info == ' '){
				indice++;
			}
			p_l = p_l->prox;
		}
	}
}