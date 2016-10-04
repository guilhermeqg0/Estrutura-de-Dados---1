/*
 * Implementacao de listas com nó cabeça.
 */

#ifndef LISTAD_H
#define LISTAD_H

typedef struct no {
  char nome[144];
  int idade;
  char *carro[144];
  int n_car;
  char *pet[144];
  int n_pet;
  struct no *prox;
} No_lista;

typedef No_lista Pessoa;

/* Inicializa uma lista */
void inicLista(Pessoa *p_l);

/* Verifica se a lista está vazia ou nao */
int listaVazia(Pessoa *p_l);

/* Insere um elemento no final da lista */
//void insereFim(Pessoa *p_l, char nome, int idade, char carro, char pet);

void cadastra_usuario(Pessoa *p_l, char nome, int idade);

void exibe(Pessoa *p_l);
/*
int strlen_lista(Lista *p_l);
void strcmp_lista(Lista *p_l1, Lista *p_l2);
void strcpy_lista(Lista *p_l1, Lista *p_l2);
void strcat_lista(Lista *p_l1, Lista *p_l2);*/
#endif
