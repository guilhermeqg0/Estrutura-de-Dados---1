/* Exercicio 1.3 - Dinamica sem nó cabeça */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dinamica.h"

/*
 * Implementacao de lista sem nó cabeça.
 
/* Inicializa uma lista */
void inicLista(Lista *p_l){
    *p_l = NULL;
}
 
/* Verifica se a lista está vazia ou nao */
int listaVazia(Lista *p_l){
 
    if ((*p_l) == NULL)
    {
        return 1;
    }
 
    return 0;
}
 
/* Insere um elemento no inicio da lista */
void insereInicio(Lista *p_l, elem_t e){
    No_lista *novo;
    novo = (No_lista*)malloc(sizeof(No_lista));
 
    if ((*p_l) == NULL)
    {
        novo->info = e;
        novo->prox = NULL;
        *p_l = novo;
    }
    else
    {
        novo->prox = *p_l;
        novo->info = e;
        (*p_l) = novo;
    }
}
 
/* Insere um elemento no final da lista */
void insereFim(Lista *p_l, elem_t e){
    No_lista *novo, *aux;
    aux = *p_l;
    novo = (No_lista*)malloc(sizeof(No_lista));
 
    if ((*p_l) == NULL)
    {
        *p_l = novo;
        novo->info = e;
        novo->prox = NULL;
    }
    else
    {
        novo->info = e;
        novo->prox = NULL;
 
        while(aux->prox != NULL)
        {
            aux = aux->prox;
        }
 
        aux->prox = novo;
    }
}
 
/* Insere um elemento na lista de maneira ordenada.
   Caso a lista nao esteja ordenada, ordena antes da insercao */
void insereOrdenado(Lista *p_l, elem_t e){
    No_lista *atual, *proximo, *novo;
    atual = *p_l;
    novo = (No_lista*)malloc(sizeof(No_lista));
    novo->info = e;
 
    if (atual == NULL)
    {
        *p_l = novo;
        novo->prox = NULL;
        return;
    }
    else if (atual->prox == NULL)
    {
        if (atual->info > e)
        {
            novo->prox = atual;
            *p_l = novo;
            return;
        }
        else
        {
            atual->prox = novo;
            novo->prox = NULL;
            return;
        }
    }
    else if (atual->prox != NULL && e < atual->info)
    {
        *p_l = novo;
        novo->prox = atual;
        return;
    }
 
    proximo = atual->prox;
 
    while (atual->prox != NULL)
    {
        if (proximo->info > e && atual->info < e)
        {
            novo->prox = proximo;
            atual->prox = novo;
            return;
        }
 
        atual = atual->prox;
        proximo = proximo->prox;
    }
 
    novo->prox = NULL;
    atual->prox = novo;
}
 
/* Verifica se a lista esta ordenada */
int ordenada(Lista *p_l){
    No_lista *atual, *antes;
    atual = *p_l;
    antes = NULL;
 
    if (atual == NULL)
    {
        return 0;
    }
 
    antes = atual;
    atual = atual->prox;
 
    while (atual != NULL)
    {
        if (antes->info > atual->info)
        {
            return 0;
        }
 
        antes = atual;
        atual = atual->prox;
    }
 
    return 1;
}
 
/* Ordena a lista */
void ordena(Lista *p_l){
    No_lista *menor, *atual, *inicio, *antes, *antesMenor, *nova;
    atual = *p_l;
    menor = *p_l;
    inicio = *p_l;
 
    while (inicio != NULL)      //Laço para andar a lista por fora de ponta a ponta
    {
        antes = inicio;
        antesMenor = inicio;
        atual = inicio->prox;
 
        while (atual != NULL)       //Laço que pega o próximo elemento da lista e a percorre inteira
        {
            if (atual->info < menor->info)     //Caso o info do atual seja menor que o do MENOR, armazena o menor na variavel MENOR e o seu antecessor no antesMenor
            {
                menor = atual;
                antesMenor = antes;
            }
 
            atual = atual->prox;     //Andando a lista
            antes = antes->prox;
        }
 
        antesMenor->prox = NULL;
        nova = menor;
        *p_l = nova;
        nova->prox = NULL;
    }
}
 
/* Remove o elemento que esta no inicio da lista.
   Retorna 0 caso a lista esteja vazia */
int removeInicio(Lista *p_l, elem_t *p_e){
    No_lista *aux;
    aux = *p_l;
 
    if (aux == NULL)
    {
        return 0;
    }
     
    *p_l = aux->prox;
    *p_e = aux->info;
    free(aux);
 
    return 1;
}
 
/* Remove o elemento que esta no final da lista.
   Retorna 0 caso a lista esteja vazia */
int removeFim(Lista *p_l, elem_t *p_e){
    No_lista *aux;
    aux = *p_l;
 
    if (aux == NULL)
    {
        return 0;
    }
    else if (aux->prox == NULL)
    {
        *p_e = aux->info;
        free(aux->prox);
        aux = NULL;
        return 1;
    }
 
    while (aux->prox->prox != NULL)
    {
        aux = aux->prox;
    }
 
    *p_e = aux->prox->info;
    free(aux->prox);
    aux->prox = NULL;
 
    return 1;
}
 
/* Remove o numero de valor e.
   Retorna 0 caso este numero não tenha sido encontrado */
int removeValor(Lista *p_l, elem_t e){
    No_lista *atual, *proximo;
    atual = *p_l;
 
    if (atual == NULL)
    {
        return 0;
    }
    else if (atual->prox == NULL && atual->info == e)
    {
        free(atual);
        *p_l = NULL;
        return 1;
    }
    else if (atual->prox != NULL && atual->info == e)
    {
        proximo = atual->prox;
        free(atual);
        *p_l = proximo;
        return 1;
    }
     
    proximo = atual->prox;
 
    while (proximo != NULL)
    {
        if (proximo->info == e)
        {
            atual->prox = proximo->prox;
            free(proximo);
            proximo = atual->prox;
            return 1;
        }
 
        proximo = proximo->prox;
        atual = atual->prox;
    }
 
    return 0;
}
 
/* Inverte os elementos de uma lista */
void inverte(Lista *p_l){
    No_lista *antes, *atual, *proximo;
    antes = NULL;
    atual = *p_l;
    while (atual != NULL)
    {
        proximo = atual->prox;
        atual->prox = antes;
        antes = atual;
        atual = proximo;
    }
 
    *p_l = antes;
}
 
/* Remove todos os numeros da lista */
void libera(Lista *p_l){
    No_lista *aux;
    aux = *p_l;
 
    while ((*p_l) != NULL)
    {
        (*p_l) = (*p_l)->prox;
        free(aux);
        aux = *p_l;
    }
 
    *p_l = NULL;
}
 
/* Exibe o conteudo da lista */
void exibe(Lista *p_l){
    Lista aux;
    aux = *p_l;
    while(aux != NULL){
        printf("%d ", aux->info);
        aux = aux->prox;
    }
}

int media(Lista *p_l);