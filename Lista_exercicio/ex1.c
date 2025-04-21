#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct regLista {
                    char RA[14];
                    char siglaCurso[6];
                    float nota;
                    int falta;
                    struct regLista *prox;  //prox apontara para o proximo item da lista
                };               //Descritor
typedef struct regLista LAluno; // Apelida a RegLista
 
typedef struct {LAluno *inicio, *final;} TLista; //Auxiliares
 
//Funções (Implementeção)
void ImprimeLista(TLista *, char *);
void InicializaLista(TLista *);
int ExcluiCurso(TLista *, char *);
int main(void)
{  
    TLista lista;
    LAluno *aux, *ant;
    char RA[14], siglaCurso[6];
    float nota;
    int faltas;
 
    InicializaLista(&lista);
    while (1)
    {   printf("Informe o RA do aluno\n");
        scanf("%s", RA);
        if (strcmp(RA, "XXX") == 0)    
            break;
       
        printf("Informe a disciplina\n");
        scanf("%s", siglaCurso);
       
        printf("Informe a nota\n");
        scanf("%f", &nota);
       
        printf("Informe as faltas\n");
        scanf("%d", &faltas);
        /* criando uma variável struct regLista dinamicamente */
        aux = (LAluno *) malloc(sizeof(LAluno));
        if (aux == NULL)
        {   puts("Memoria insuficiente.");
            return 2;
        }
        //Preenchendo campos de forma dinâmica//        
        aux->nota = nota;
        aux->falta = faltas;
        strcpy(aux->RA, RA);
        strcpy(aux->siglaCurso, siglaCurso);
        aux->prox = NULL;
       
        /* fazendo o encadeamento do novo item na lista */
        if (lista.inicio == NULL)
            lista.inicio = aux;
        else
            lista.final->prox = aux;
       
        lista.final = aux;
    }
    ImprimeLista(&lista, "Conteudo da lista");
    while (1)      
    {   printf("Informe o curso para apagar:\n");
        scanf("%s", siglaCurso);
        if (strcmp(siglaCurso, "XXX") == 0)
            break;
        if (ExcluiCurso(&lista, siglaCurso) == 0)
        {
            printf("Disciplina não encontrada\n");
        }
        else
            ImprimeLista(&lista, "Conteudo NOVO da Lista de Alunos");
 
       
    }
    return 0;
}
 
void ImprimeLista(TLista *lista, char *cabec)
{
    LAluno *aux;
    int i = 1;
 
    /* imprimindo os valores da lista */
    if (lista->inicio == NULL)
        printf("\n\n\nLista vazia\n");
    else
    {   printf("\n\n\n%s:\n", cabec);
        aux = lista->inicio;
        while (aux != NULL)
        {  
            printf("\nAluno %d\n", i);
            printf("RA: %s\nCurso: %s\nNota: %.2f\nFaltas: %d\n", aux->RA, aux->siglaCurso, aux->nota, aux->falta);
            aux = aux->prox;
            i++;
        }
    }
    printf("\n");
}
 
void InicializaLista(TLista *lista)  //Coloca NULL nos auxiliares
{  
    lista->inicio = NULL;
    lista->final = NULL;
}
 
int ExcluiCurso(TLista *lista, char *siglaCurso)
{
    LAluno *aux, *ant;
    aux = lista->inicio;
    ant = NULL;
    while(aux != NULL)
    {
        if(strcmp(aux->siglaCurso, siglaCurso) == 0)
        {        
            if (ant == NULL)
                lista->inicio = aux->prox;
            else
                ant->prox = aux->prox;
           
            free(aux);
 
        if (lista->final == aux)
            lista->final = ant;
 
        if (ant == NULL)
            {
                aux = lista->inicio;
            }
            else
            {
                aux = ant->prox;
            }
        }
           else
        {
           ant = aux;
           aux = aux->prox;
        }
    }
   
 
    return 1;
}