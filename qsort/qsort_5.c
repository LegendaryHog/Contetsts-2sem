#include <stdio.h>
#include <stdlib.h>

#define N 1024

int cmp (const void* pc1, const void* pc2);

int main (void)
{
    int  size = 0;
    char c    = 0;

    char* data = (char*) calloc (N, sizeof (char));
    do
    {
        scanf ("%c", data + size);
        size++;
    } while (data[size - 1] != '.');
    qsort (data, size - 1, sizeof (char), cmp);
    for (int i = 0; i < size; i++)
    {
        printf ("%c", data[i]);
    }
    printf ("\n");
    free (data);
    return 0;
}

int cmp (const void* pc1, const void* pc2)
{
    return *(char*)pc1 - *(char*)pc2;
}