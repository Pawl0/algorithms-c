#include <stdio.h>
#include <stdlib.h>

int *inverte(int *array, int tam)
{
    int *newArray = (int *)malloc(tam * sizeof(int));

    for (int i = 0; i < tam; i++)
    {
        newArray[i] = array[tam - i - 1];
    }
    return newArray;
}

int main()
{
    int array[] = {5, 4, 3, 2, 1};
    int tam = sizeof(array) / sizeof(int);
    int *arrayInvertido = inverte(array, tam);
    printf("Vetor invertido: ");
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", arrayInvertido[i]);
    }

    return 0;
}
