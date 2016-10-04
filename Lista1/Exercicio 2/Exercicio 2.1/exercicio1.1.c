#include <stdlib.h>
#include <stdio.h>
#include "lista_no_cabeca.h"

//Com N� Cabe�a

/* Inicializa uma lista */
void inicLista(Lista *p_l){
	p_l->prox = NULL;
}

/* Verifica se a lista est� vazia ou nao */
int listaVazia(Lista *p_l){
	if(p_l->prox == NULL)
        return 1;

	return 0;
}

/* Insere um elemento no inicio da lista */
void insereInicio(Lista *p_l, elem_t e){
	No_lista *novo_no;
	novo_no = (No_lista *) malloc(sizeof(No_lista));

	novo_no->info = e;
	novo_no->prox = p_l->prox;
	p_l->prox = novo_no;
}

/* Insere um elemento no final da lista */
void insereFim(Lista *p_l, elem_t e){
	No_lista *novo;

	novo = malloc(sizeof(No_lista));
	novo->info = e;
	novo->prox = NULL;

	while(p_l->prox != NULL)
		p_l = p_l->prox;
	p_l->prox = novo;

}


/* Insere um elemento na lista de maneira ordenada.
   Caso a lista nao esteja ordenada, ordena antes da insercao */
void insereOrdenado(Lista *p_l, elem_t e){
	No_lista *novo;

	if (!ordenada(p_l))
		ordena (p_l);

	novo = (No_lista *)malloc (sizeof(No_lista));
	novo->info = e;

	while (p_l->prox != NULL && p_l->prox->info < novo->info){
		p_l = p_l->prox;
	}
	novo->prox = p_l->prox;
	p_l->prox = novo;
}

/* Verifica se a lista esta ordenada */
int ordenada(Lista *p_l){
	if (listaVazia(p_l))
		return 1;

	while (p_l->prox->prox != NULL){
		if (p_l->prox->info > p_l->prox->prox->info)
			return 0;
		p_l = p_l->prox;
	}
	return 1;
}

/* Ordena a lista */
void ordena(Lista *p_l){
	No_lista *desord, *aux, *novo;

	desord = p_l->prox;
	p_l->prox = NULL;
	while (desord != NULL){
		novo = desord;
		desord = desord->prox;
		aux = p_l;

		while (aux->prox != NULL && aux->prox->info < novo->info){
			aux = aux->prox;
		}
		novo->prox = aux->prox;
		aux->prox = novo;
	}
}

/* Remove o elemento que esta no inicio da lista.
   Retorna 0 caso a lista esteja vazia */
int removeInicio(Lista *p_l, elem_t *p_e){
	No_lista *aux;

	if (listaVazia(p_l))
		return 0;

	aux = p_l->prox;
	*p_e = aux->info;
	//p_l->prox = aux->prox;
	p_l->prox = p_l->prox->prox;
	free(aux);
	return 1;
}

/* Remove o elemento que esta no final da lista.
   Retorna 0 caso a lista esteja vazia */
int removeFim(Lista *p_l, elem_t *p_e){
	No_lista *aux;
	if (listaVazia(p_l))
		return 0;

//	while (p_l->prox->prox != NULL)
	while ((*(*p_l).prox).prox != NULL)
		p_l = p_l->prox;

	aux = p_l->prox;

	/*
	aux = p_l->prox;
	while(aux->prox != NULL){
		p_l = aux;
		aux = aux->prox;
	}
	*/

	p_l->prox = aux->prox;
	*p_e = aux->info;
	free(aux);

	return 1;
}

/* Remove o numero de valor e.
   Retorna 0 caso este numero n�o tenha sido encontrado */
int removeValor(Lista *p_l, elem_t e){
	No_lista *aux;
	int removeu = 0;

	if (listaVazia(p_l))
		return 0;

	aux = p_l->prox;
	while(aux != NULL){
		if (aux->info == e){
			p_l->prox = aux->prox;
			free(aux);
			removeu = 1;
			aux = p_l->prox;
		}
		else {
			p_l = p_l->prox;
			aux = p_l->prox;
		}
	}

	return removeu;
}

/* Inverte os elementos de uma lista */
void inverte(Lista *p_l){
	No_lista *desord, *novo;

	desord = p_l->prox;
	p_l->prox = NULL;
	while (desord != NULL){
		novo = desord;
		desord = desord->prox;

		novo->prox = p_l->prox;
		p_l->prox = novo;
	}

}

/* Remove todos os numeros da lista */
void libera(Lista *p_l){
	No_lista *aux;

	while (p_l->prox != NULL){
		aux = p_l->prox;
		p_l->prox = aux->prox;
		free (aux);
	}
}

/* Exibe o conteudo da lista */
void exibe(Lista *p_l){
	while(p_l->prox != NULL){
		printf("%d ", p_l->prox->info);
		p_l = p_l->prox;
	}
}

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
