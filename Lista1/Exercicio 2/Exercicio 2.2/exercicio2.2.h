#ifndef LISTAD_H
#define LISTAD_H

typedef int elem_t;

typedef struct no{
  elem_t info;
  struct no *prox;
} No_lista;

typedef No_lista Lista;

/* Inicializa uma lista */
void inicLista(Lista *p_l);

/* Verifica se a lista está vazia ou nao */
int listaVazia(Lista *p_l);

/* Insere um elemento no final da lista */
void insereFim(Lista *p_l, elem_t e);

/* Verifica se a lista esta ordenada */
int ordenada(Lista *p_l);

/* Ordena a lista */
void ordena(Lista *p_l);

/* Remove o elemento que esta no inicio da lista.
   Retorna 0 caso a lista esteja vazia */
int removeInicio(Lista *p_l);

/* Remove todos os numeros da lista */
void libera(Lista *p_l);

/* Exibe o conteudo da lista */
void exibe(Lista *p_l);

void concatena(Lista *p_l1, Lista *p_l2);

#endif