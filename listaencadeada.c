#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int valor;
    struct No *proximo;
} No;

typedef struct
{
    No *inicio;
    int tam;
} Lista;

//inserção no início da lista
void inserirInicio(Lista *lista, int valor)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor; // (*novo).valor = valor
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    lista->tam++;
}
//inserção no final da lista
void inserirFim(Lista *lista, int valor)
{
    No *no, *novo = (No *)malloc(sizeof(No));
    novo->valor = valor; // (*novo).valor = valor
    novo->proximo = NULL;

    if (lista->inicio == NULL)
    {
        lista->inicio = novo;
    }
    else
    {
        no = lista->inicio;
        while (no->proximo != NULL)
        {
            no = no->proximo;
        }
        no->proximo = novo;
    }
    lista->tam++;
}

//imprimir a lista
void imprimir(Lista lista)
{
    No *inicio = lista.inicio;
    int tam = lista.tam;
    printf("Tamanho da lista: %d\n\n", tam);
    printf("Lista: ");
    while (inicio != NULL)
    {
        printf("%d ", inicio->valor);
        inicio = inicio->proximo;
    }
    printf("\n\n");
}

int main()
{
    Lista lista;
    int opcao, valor;

    lista.inicio = NULL;
    lista.tam = 0;

    do
    {
        printf("1 - inserir no inicio\n2 - Imprimir\n3 - Inserir no fim\n5 - Sair\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("Digite um valor para ser inserido: ");
            scanf("%d", &valor);
            inserirInicio(&lista, valor);
            break;
        case 2:
            imprimir(lista);
            break;
        case 3:
            printf("Digite um valor para ser inserido: ");
            scanf("%d", &valor);
            inserirFim(&lista, valor);
            break;
        case 5:
            printf("Finalizando");
            inserirInicio(&lista, valor);
            break;
        default:
            printf("Opção inválida\n");
            break;
        }
    } while (opcao != 5);

    return 0;
}