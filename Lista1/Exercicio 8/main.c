#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <exercicio8.h>


int main()
{

Lista l;
char caracter[200];
char c[200];
int i = 0, numArq = 0;

scanf("%[^\n]",caracter);

	for(int j = 0; j <= strlen(caracter); j++)
	{
				if(*(caracter+j) != ' ')
				{
					*(c+i) = *(caracter+j);
					i++;
				}
				
				if((*(caracter+j) != '\0') && (*(caracter+j) == ' '))
				{
					*(c+i) = '\0';
					numArq++;
					lerArq(&l, c, numArq);
					i = 0;
					printf("\n");
				}
				
				if((*(caracter+j) == '\0'))
				{
					*(c+i) = '\0';
					numArq++;
					lerArq(&l, c, numArq);
					i = 0;
					printf("\n");
				}
				
	}
	libera(&l);
}