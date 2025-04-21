#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXALUNOS    50


typedef struct {char RA[14]; char siglaCurso[6]; float nota; int faltas;} TItem;
typedef struct {TItem alunos[MAXALUNOS];} TLista;

//Funções (Implementeção)
void ImprimeLista(TLista, char *, int);
int ExcluiCurso(TLista *, char *, int *);
int main(void){
	char RA[14], siglaCurso[6];
	float nota;
	int faltas, final;
	TLista lista;
	
	final = 0;
//	InicializaLista(&lista);
	while (1)
	{	printf("Informe o RA do aluno\n");
		scanf("%s", RA);
		if (strcmp(RA, "XXX") == 0)
		{
			break;
		}
		printf("Informe a disciplina\n");
		scanf("%s", siglaCurso);
		
		printf("Informe a nota\n");
		scanf("%f", &nota);
		
		printf("Informe as faltas\n");
		scanf("%d", &faltas);
		if (final < MAXALUNOS)
		{
			//alocando itens
			strcpy(lista.alunos[final].RA, RA);
			strcpy(lista.alunos[final].siglaCurso, siglaCurso);
			lista.alunos[final].nota = nota;
			lista.alunos[final].faltas = faltas;
		
			final++;
		}
		else
		{
			printf("/nLista cheia!/n");
		}
	}
	if (final == 0)
	{
		printf("Lista vazia!");
	}
	else
	{
		ImprimeLista(lista, "Conteudo da lista", final);
	}
	
	while(1)
	{
		printf("\nDigite o curso a ser excluido\n");
		scanf("%s", siglaCurso);
		if (strcmp(siglaCurso, "XXX")==0)
		{
			break;
		}
		if (ExcluiCurso(&lista, siglaCurso, &final)==0)
		{
			printf("\nDisciplina não encontrada");
		}
		else
		{
			ImprimeLista(lista, "NOVO conteudo da lista", final);
		}
	}
}

void ImprimeLista(TLista lista, char *cabec, int final)
{
	for(int i = 0; i <final; i++ )
	{
		printf("\nAluno %d:\n", i+1);
		printf("RA: %s\n", lista.alunos[i].RA);
		printf("Curso: %s\n", lista.alunos[i].siglaCurso);
		printf("Nota: %.2f\n", lista.alunos[i].nota);
		printf("Faltas: %d\n", lista.alunos[i].faltas);
	}
}

int ExcluiCurso(TLista *lista, char *siglaCurso, int *final)
{
	int ret=0;
	for(int i = 0; i<*final; i++)
	{
		if (strcmp(lista->alunos[i].siglaCurso, siglaCurso)==0)
		{
			for (int j=i; j<*final-1;j++)
			{
				lista->alunos[j] = lista->alunos[j+1];
			}
			(*final)--;
			ret=1;
			i--;
		}
	}
	if (ret==1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

