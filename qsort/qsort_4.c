#include <stdio.h>
#include <stdlib.h>

int cmp (const void* n1, const void* n2);

int main (void)
{
    int size = 0;
    scanf ("%d", &size);
    double* data = (double*) calloc (size, sizeof (double));
    for (int i = 0; i < size; i++)
    {
        scanf ("%lf", data + i);
    }
    qsort (data, size, sizeof (double), cmp);
    for (int i = 0; i < size; i++)
    {
        printf ("%lg ", data[i]);
    }
    printf ("\n");
    free (data);
    return 0;
}

int cmp (const void* pn1, const void* pn2)
{
    if (*(double*)pn1 > *(double*)pn2)
    {
        return 1;
    }
    else if (*(double*)pn1 < *(double*)pn2)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
