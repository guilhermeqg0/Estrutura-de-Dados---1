#ifndef LISTAD_H
#define LISTAD_H

typedef int elem_t;

typedef struct no{
  elem_t exp;
  elem_t mult;
  struct no *prox;
} No_lista;

typedef No_lista Lista;

/* Inicializa uma lista */
void inicLista(Lista *p_l);

/* Verifica se a lista está vazia ou nao */
int listaVazia(Lista *p_l);

/* Insere um elemento na lista de maneira ordenada.
   Caso a lista nao esteja ordenada, ordena antes da insercao */
void insereOrdenado(Lista *p_l, elem_t e, elem_t e2);

void insereFim(Lista *p_l, elem_t e, elem_t e2);

/* Remove todos os numeros da lista */
void libera(Lista *p_l);

/* Exibe o conteudo da lista */
void exibe(Lista *p_l);

Lista soma(Lista *p_l1, Lista *p_l2, Lista *p_l3);

#endif