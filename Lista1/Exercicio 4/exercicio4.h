#ifndef LISTAD_H
#define LISTAD_H

typedef char elem_t;

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

/* Remove todos os numeros da lista */
void libera(Lista *p_l);

/* Exibe o conteudo da lista */
void exibe(Lista *p_l, int pos);

#endif