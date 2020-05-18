#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int conteudo;
    struct no *esquerda, *direita;
} No;

typedef struct
{
    No *raiz;
} ArvB;

No *inserirNovaVersao(No *raiz, int valor)
{
    if (raiz == NULL)
    {
        No *novo = (No *)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    }
    else
    {
        if (valor < raiz->conteudo)
        {
            raiz->esquerda = inserirNovaVersao(raiz->esquerda, valor);
        }
        if (valor > raiz->conteudo)
        {
            raiz->direita = inserirNovaVersao(raiz->direita, valor);
        }
        return raiz;
    }
}

void imprimir(No *raiz)
{
    if (raiz != NULL)
    {
        imprimir(raiz->esquerda);
        printf("%d ", raiz->conteudo);
        imprimir(raiz->direita);
    }
}

int main()
{
    int op, valor;
    ArvB arv;
    arv.raiz = NULL;

    No *raiz = NULL;

    do
    {
        printf("\n0 - sair \n1 - inserir\n2 - imprimir\n");
        scanf("%d", &op);

        switch (op)
        {
        case 0:
            printf("\nSaindo...\n");
            break;
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            raiz = inserirNovaVersao(raiz, valor);
            break;
        case 2:
            printf("\nImpressao da arvore binaria:\n");
            imprimir(raiz);
            break;
        default:
            printf("\nOpcao invalida\n");
            break;
        }
    } while (op != 0);
    return 0;
}