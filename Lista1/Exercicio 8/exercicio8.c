#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Lista
{
	FILE *arq;
	char *nome;
	struct Lista *prox;
	
}Lista;

void inicialista(Lista *p_l)//sem no cabeça
{
	p_l->nome = NULL;
	p_l->arq = NULL;
	p_l = NULL;
	p_l->prox = NULL;
}

void lerArq(Lista *p_l, char c[], int num)
{
		Lista *novo_no;
		char txt;
		
		novo_no = malloc(sizeof(Lista));

		novo_no->prox = NULL;

		novo_no->arq = NULL;

		novo_no->nome = NULL;

		novo_no->nome = malloc(sizeof(strlen(c)));

		novo_no->nome = c;
	
		if(p_l == NULL)
		{
			p_l = novo_no;
		}
		else
		{
			p_l->prox = novo_no;
		}	
		
	printf("Arquivo %d, %s\n",num, novo_no->nome);	

	novo_no->arq = fopen(novo_no->nome,"r");

	if(novo_no->arq == NULL)
	{
		printf("Arquivo Inexistente\n");
		return;
	}

	while((txt = fgetc(novo_no->arq)) != EOF)
	{
		putchar(txt);

	}
	fclose(novo_no->arq);
}

void libera(Lista *p_l)
{
	if(p_l != NULL)
	{
		Lista *aux;
		
		while(p_l != NULL)
		{	
			aux = p_l->prox;


			p_l = p_l->prox;
			
			free(aux);
		}
	}	
		
}

