#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char copia[50], palavra[50];
    int i, j, tamanho;

    printf("Digite algo: ");
    fgets(palavra, 50, stdin);

    tamanho = strlen(palavra);
    strcpy(copia, palavra);

    j = tamanho - 2;
    for (i = 0; i < tamanho - 2; i++)
    {
        if (palavra[i] != copia[j])
        {
            printf("Nao e palindromo");
            return 0;
        }
        j--;
    }

    printf("E palindromo!\n\n");

    printf("Tamanho: %d\nPalavra digitada: %sPalavra copiada: %s", tamanho, palavra, copia);

    return 0;
}