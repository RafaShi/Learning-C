#include <stdio.h>
#include <stdlib.h>

struct regLista	{ 	float valor;
					struct regLista *prox;
				};	
typedef struct regLista TNum;
typedef struct {TNum *inicio, *final;} TListas; //descritor 1

void ImprimeLista(TListas, char *);
void InicializaLista(TListas *);
int LerLista(TListas *);
void somaListas(TListas *, TListas *, TListas *);
				
int main(void)
{	
	TListas lista1, lista2, listasoma;

	InicializaLista(&lista1);
	InicializaLista(&lista2);
	InicializaLista(&listasoma);
	
	printf("Informe os valores da primeira lista:\n");
	LerLista(&lista1);
	printf("Informe os valores da segunda lista:\n");
	LerLista(&lista2);
	
	ImprimeLista(lista1, "Conteudo da lista 1");
	ImprimeLista(lista2, "Conteudo da lista 2");
	
	printf("Soma das listas:");
	somaListas(&lista1, &lista2, &listasoma);
	ImprimeLista(listasoma, "Conteudo da lista soma");
	
	return 0;
}

void ImprimeLista(TListas lista, char *cabec)
{	
	TNum *aux;

	/* imprimindo os valores da lista */
	if (lista.inicio == NULL)
		printf("\n\n\nLista vazia\n");
	else
	{	printf("\n\n\n%s:\n", cabec);
	
		aux = lista.inicio;
		while (aux != NULL)
		{	printf("%.2f\n", aux->valor);
			
			aux = aux->prox;
		}
	}
	printf("\n");
}

void InicializaLista(TListas *lista)
{	/* inicializando o conjunto de descritores da lista */
	lista->inicio = NULL;
	lista->final = NULL;
}
int LerLista(TListas *lista)
{
	float valores;
	TNum *aux;
	while (1)
	{	
		scanf("%f", &valores);

		if (valores < 0)
			break;

		aux = (TNum *) malloc(sizeof(TNum));
		
		if (aux == NULL)
		{	puts("Memoria insuficiente para continuar ...");
			return 2;
		}
		
		/* preenchendo os campos da variável criada dinamicamente */		
		aux->valor = valores;
		aux->prox = NULL;
		
		/* fazendo o encadeamento do novo item na lista */
		if (lista->inicio == NULL)
			lista->inicio = aux;
		else
			lista->final->prox = aux;

		lista->final = aux;
	}
	return 0;
}

void somaListas(TListas *lista1, TListas *lista2, TListas *listasoma)
{
	TNum *l1, *l2, *aux;
	float soma;
	l1 = lista1->inicio;
	l2 = lista2->inicio;
	while(l1 != NULL || l2!=NULL)
	{
		soma = 0;
		if (l1!=NULL)
		{
			soma = soma + l1->valor;
			l1 = l1->prox;
		}
		if (l2!=NULL)
		{
			soma = soma + l2->valor;
			l2 = l2->prox;
		}
		aux = (TNum *) malloc(sizeof(TNum));
		
		if (aux == NULL)
		{	puts("Memoria insuficiente para continuar ...");
			break;
		}
		aux->valor = soma;
		aux->prox = NULL;
		if (listasoma->inicio == NULL)
			listasoma->inicio = aux;
		else
			listasoma->final->prox = aux;
		listasoma->final = aux;
	}
}