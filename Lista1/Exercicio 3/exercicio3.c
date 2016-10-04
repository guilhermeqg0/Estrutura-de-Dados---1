/* Exercicio 3 */

//Situação inicial:

Typedef struct lista { 

int elem_t; 

struct lista prox;

 } Lista;


 //A struct não funcionará corretamente, pois está faltando um ponteiro em prox.
 //O correto seria:

 Typedef struct lista { 

int elem_t; 

struct lista *prox;

 } Lista;


