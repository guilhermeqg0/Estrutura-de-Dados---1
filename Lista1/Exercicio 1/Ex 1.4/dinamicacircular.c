#include <stdlib.h>
#include <stdio.h>
#include "dinamicacircular.h"

/* Inicializa uma lista */
void inicLista(Lista *p_l){
	p_l->prox=NULL;
}

/* Verifica se a lista está vazia ou nao */
int listaVazia(Lista *p_l){
	if(p_l->prox==NULL) return 1;
	return 0;
}

/* Insere um elemento no inicio da lista */
void insereInicio(Lista *p_l, elem_t e){
	No_lista *novo_no, *aux;
	aux = p_l->prox;
	novo_no = (No_lista *) malloc(sizeof(No_lista));
	
	novo_no->info = e;
	
	if (p_l->prox == NULL)
	{
		p_l = novo_no;
		novo_no->prox = novo_no;
	}
	else if ((p_l)->prox == (p_l))
	{
		p_l->prox = novo_no;
		novo_no = (p_l);
	}
	else
	{
		while (aux->prox != p_l)
		{
			aux = aux->prox;
		}

		aux->prox = novo_no;
		novo_no->prox = p_l;
		p_l = novo_no;
	}
}

/* Insere um elemento no final da lista */
void insereFim(Lista *p_l, elem_t e){
	No_lista *novo_no, *aux;
	aux = p_l->prox;
	
	novo_no = malloc(sizeof(No_lista));
	novo_no->info = e;
	printf("Novo->info: %d\n", novo_no->info);

	if (p_l->prox == NULL)
	{
		printf("pl->prox->info: %d\n", p_l->prox->info);
		p_l->prox = novo_no;
		novo_no->prox = novo_no;
	}
	else if (p_l->prox->prox == p_l->prox)
	{
		aux->prox = novo_no;
		novo_no->prox = aux;
	}
	else
	{
		while(aux->prox != p_l->prox)
		{
			aux = aux->prox;	
		}
			
		aux->prox = novo_no;
		novo_no->prox = p_l->prox;
	}
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
		ordena(p_l);
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
	
	while (p_l->prox->prox != NULL)
		p_l = p_l->prox;	
	aux = p_l->prox;
	
	p_l->prox = aux->prox;
	*p_e = aux->info;
	free(aux);

	return 1;
}

/* Remove o numero de valor e.
   Retorna 0 caso este numero não tenha sido encontrado */
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
	No_lista *inicio, *aux, *aux2;

	if(listaVazia(p_l)){
		return;
	}else if(p_l->prox->prox == NULL){
		return;
	}

	inicio = p_l->prox;
	
	while(inicio->prox != NULL){
		aux = inicio->prox;
		aux2 = inicio;
		while(aux->prox != NULL){
			aux = aux->prox;
			aux2 = aux2->prox;
		}
		p_l->prox = aux;
		p_l = p_l->prox;
		p_l->prox = aux2;
		aux2->prox = NULL;
	}
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
	No_lista *aux;
	aux = p_l->prox;

	while(aux != p_l->prox){
		printf("%d ", aux->info);
		aux = aux->prox;
	}
}

void media(Lista *p_l){
	int i = 0;
	float soma = 0, media;

	while(p_l->prox != NULL){
		soma = soma + p_l->prox->info;
		p_l = p_l->prox;
		i++;
	}

	media = soma / i;

	printf("%.2f", media);
}