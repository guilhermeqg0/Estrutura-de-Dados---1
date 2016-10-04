#include <stdlib.h>
#include <stdio.h>
#include "exercicio10.h"

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

/* Insere um elemento na lista de maneira ordenada.
   Caso a lista nao esteja ordenada, ordena antes da insercao */
void insereOrdenado(Lista *p_l, elem_t e){
	No_lista *novo_no;
	novo_no = (No_lista *) malloc(sizeof(No_lista));
	
	novo_no->info = e;

	if(listaVazia(p_l)){
		p_l->prox = novo_no;
		novo_no->prox = NULL;
	}else{
		while(p_l->prox != NULL && p_l->prox->info < e)
			p_l = p_l->prox;

		novo_no->prox = p_l->prox;
		p_l->prox = novo_no;
	}

}

/* Verifica se a lista esta ordenada */
int ordenada(Lista *p_l){
	if(listaVazia(p_l))
		return 1;
	while(p_l->prox->prox != NULL){
		p_l = p_l->prox;

		if (p_l->info > p_l->prox->info)
			return 0;
	}
	return 1;
}

/* Ordena a lista */
void ordena(Lista *p_l){
	No_lista *aux, *aux2;

	if(listaVazia(p_l))
		return;
	if(p_l->prox->prox == NULL)
		return;
	if (ordenada(p_l))
		return;

	while(p_l->prox != NULL){
		aux = p_l->prox;
		while(aux->prox != NULL){
			if(aux->prox->info < p_l->prox->info){
				if(aux->prox->prox != NULL){
					aux2 = aux->prox;
					aux->prox = aux->prox->prox;
					aux2->prox = p_l->prox;
					p_l->prox = aux2;
				}else{
					aux2 = aux->prox;
					aux->prox = NULL;
					aux2->prox = p_l->prox;
					p_l->prox = aux2;
				}
			}else{
				aux = aux->prox;
			}
		}
		p_l = p_l->prox;
	}

}

/* Remove o elemento que esta no inicio da lista.
   Retorna 0 caso a lista esteja vazia */
int removeInicio(Lista *p_l){
	No_lista *aux;

	if (listaVazia(p_l))
		return;

	aux = p_l->prox;
	p_l->prox = p_l->prox->prox;
	free(aux);
	return 1;
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
		printf("%d ", p_l->prox->info);
		p_l = p_l->prox;
	}
}

Lista intersecciona(Lista *p_l1, Lista *p_l2, Lista *p_l3){
	int num, pos, i, ja_contem;
	No_lista *inserir = NULL, *aux;

	while(!listaVazia(p_l1)){
		aux = p_l2;
		while(inserir == NULL && aux->prox != NULL){
			if(p_l1->prox->info == aux->prox->info){
				inserir = p_l1->prox;
				p_l1->prox = p_l1->prox->prox;
			}
			aux = aux->prox;
		}
		if(inserir != NULL){
			aux = p_l3;
			ja_contem = 0;
			while(aux->prox != NULL){
				if(aux->prox->info == inserir->info){
					ja_contem = 1;
				}

				aux = aux->prox;
			}
			if(ja_contem == 0 && inserir != NULL){
				inserir->prox = aux->prox;
				aux->prox = inserir;
			}
			inserir = NULL;		
		}else{
			p_l1->prox = p_l1->prox->prox;
		}		
	}
	return *p_l3;
}
