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
    int n1 = *(int*)pn1;
    int n2 = *(int*)pn2;
    
    if (n1%10 != n2%10)
    {
        return n1%10 - n2%10;
    }
    else if (n1%100 != n2%100)
    {
        return n1%100 - n2%100;
    }
    else if (n1%1000 != n2%1000)
    {
        return n1%1000 - n2%1000;
    }
    else if (n1%10000 != n2%10000)
    {
        return n1%10000 - n2%10000;
    }
    else
    {
        return n1 - n2;
    }
}