#include <stdio.h>
#include <stdlib.h>

int cmp (const void* n1, const void* n2);

int main (void)
{
    int size = 0;
    scanf ("%d", &size);
    long long* data = (long long*) calloc (size, sizeof (long long));
    for (int i = 0; i < size; i++)
    {
        scanf ("%lld", data + i);
    }
    qsort (data, size, sizeof (long long), cmp);
    for (int i = 0; i < size; i++)
    {
        printf ("%lld ", data[i]);
    }
    printf ("\n");
    free (data);
    return 0;
}

int cmp (const void* pn1, const void* pn2)
{
    return *(long long*)pn2 - *(long long*)pn1;
}