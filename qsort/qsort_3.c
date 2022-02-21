#include <stdio.h>
#include <stdlib.h>

int cmp (const void* n1, const void* n2);

int main (void)
{
    int size = 0;
    scanf ("%d", &size);
    int* data = (int*) calloc (size, sizeof (int));
    for (int i = 0; i < size; i++)
    {
        scanf ("%d", data + i);
    }
    qsort (data, size, sizeof (int), cmp);
    for (int i = 0; i < size; i++)
    {
        printf ("%d ", data[i]);
    }
    printf ("\n");
    free (data);
    return 0;
}

int cmp (const void* pn1, const void* pn2)
{
    return *(int*)pn2 - *(int*)pn1;
}