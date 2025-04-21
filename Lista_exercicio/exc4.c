#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX    21
struct regPilha {
	char palavra;
	struct regPilha *prox;
};
typedef struct regPilha TPilha;

struct descrPilha{
	TPilha *topo;
	
};
typedef struct descrPilha DPilha;
DPilha descritor;
void push (DPilha *, char);
char pop (DPilha *);
void inicializaPilha(DPilha *);
int verifica(char *);
int main (void)
{
	char palavra[MAX];
	while(1)
	{
		printf("Digite a palavra (FIM para encerrar)\n");
		scanf("%s", palavra);
		if (strcmp(palavra, "FIM")==0)
		{
			break;
		}
		if (verifica(palavra))
		{
			printf("%s : Palindromo!\n", palavra);
		}
		else
		{
			printf("%s : Não Palindromo!\n", palavra);
		}
		
	}
	return 0;
}

void inicializaPilha(DPilha *descritor)
{
	descritor->topo = NULL;
}
void push(DPilha *descritor, char palavra)
{
	TPilha *aux = (TPilha *) malloc(sizeof(TPilha));
	if (aux == NULL)
	{
		puts("Erro de alocação, memória insuficiente!");
		exit(1);
	}
	aux->palavra = palavra;
	aux->prox = descritor->topo;
	
	descritor->topo = aux;
}

char pop(DPilha *descritor)
{
	char let;
	if (descritor->topo==NULL)
	{
		return '\0';
	}
	TPilha *aux = descritor->topo;
	let = aux->palavra;
	descritor->topo = aux->prox;
	
	free(aux);
	
	return let;
}

int verifica(char *palavra)
{
	int i=0;
	DPilha pilha;
	inicializaPilha(&pilha);

	for (i; i<strlen(palavra)/2;i++)
	{
		push(&pilha, tolower(palavra[i]));
	}
	if (strlen(palavra)%2!=0) //ingnora letra se impar;
	{
		i++;
	}
	for(; i<strlen(palavra);i++)
	{
		char letra = pop(&pilha);
		if(tolower(palavra[i]) != letra)
		{
			return 0;
		}
	
	}
	return 1;
}