#include <stdio.h>
#include <stdlib.h>
#include "lista_no_cabeca.h"

int main(){

    int n, x, i;

    Lista l, k, p;
    inicLista(&l);
    inicLista(&k);
    inicLista(&p);

    //PRIMEIRA LISTA
    scanf("%d", &n);

    for(i=0; i < n; i++){
        scanf("%d", &x);
        insereFim(&l, x);
    }
    //SEGUNDA LISTA
    scanf("%d", &n);

    for(i=0; i < n; i++){
        scanf("%d", &x);
        insereFim(&k, x);
    }

    transfere_lista(&p, &l, &k);

    exibe(&p);


    return 0;
}
