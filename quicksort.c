#include <stdio.h>

void swap(int *number, int i, int j)
{
    if (i < j)
    {
        int temp = number[i];
        number[i] = number[j];
        number[j] = temp;
    }
}

void quicksort(int number[25], int first, int last)
{
    int i, j, pivot, temp;

    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;

        while (i < j)
        {
            while (number[i] <= number[pivot] && i < last)
                i++;
            while (number[j] > number[pivot])
                j--;

            swap(number, i, j);
        }

        swap(number, pivot, j);
        quicksort(number, first, j - 1);
        quicksort(number, j + 1, last);
    }
}

int main()
{
    int i, count, number[25];

    printf("How many elements are u going to enter?: ");
    scanf("%d", &count);

    printf("Enter %d elements: ", count);
    for (i = 0; i < count; i++)
        scanf("%d", &number[i]);

    quicksort(number, 0, count - 1);

    printf("Order of Sorted elements: ");
    for (i = 0; i < count; i++)
        printf(" %d", number[i]);

    return 0;
}