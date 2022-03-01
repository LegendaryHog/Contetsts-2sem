#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int Middle (int* data, size_t size);

int main (void)
{
    FILE* file = fopen ("input.dat", "rb");
    struct stat filestat = {};
    stat ("input.dat", &filestat);
    int* data = (int*) calloc (filestat.st_size, 1);
    size_t size = fread (data, sizeof (int), filestat.st_size / sizeof (int), file);
    printf ("%d\n", Middle (data, size));
    free (data);
    return 0;
}

int Middle (int* data, size_t size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += data[i];
    }
    return sum / (int)size;
}