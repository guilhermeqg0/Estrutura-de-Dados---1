#ifndef LISTAD_H
#define LISTAD_H


typedef struct Lista
{
	FILE *arq;
	char *nome;
	struct Lista *prox;
	
}Lista;

void inicialista(Lista *p_l);

void lerArq(Lista *p_l, char c[], int num);

void libera(Lista *p_l);