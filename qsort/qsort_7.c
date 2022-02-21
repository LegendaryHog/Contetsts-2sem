#include <stdio.h>
#include <stdlib.h>

int cmp (const void* pn1, const void* pn2);

int main (void)
{
    int size = 0;
    int size_chet = 0;
    scanf ("%d", &size);
    int* data = (int*) calloc (size, sizeof (int));
    for (int i = 0; i < size; i++)
    {
        scanf ("%d", data + i);
    }
    int* chet = (int*) calloc (size, sizeof (int));
    for (int i = 0; i < size; i++)
    {
        if (data[i] % 2 == 0)
        {
            chet[size_chet] = data[i];
            size_chet++; 
        }
    }
    qsort (chet, size_chet, sizeof (int), cmp);
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        if (data[i] % 2 == 0)
        {
            printf ("%d ", chet[j]);
            j++;
        }
        else
        {
            printf ("%d ", data[i]);
        }
    }
    printf ("\n");
    free (data);
    free (chet);
    return 0;
}

int cmp (const void* pn1, const void* pn2)
{
    return *(int*)pn1 - *(int*)pn2;
}