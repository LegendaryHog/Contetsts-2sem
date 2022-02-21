#include <stdio.h>
#include <stdlib.h>

struct Point {
    int x;
	int y;
};

int cmp_Point (const void* n1, const void* n2);

int main (void)
{
    int size = 0;
    scanf ("%d", &size);
    struct Point* data = (struct Point*) calloc (size, sizeof (struct Point));
    for (int i = 0; i < size; i++)
    {
        scanf ("%d", &(data[i].x));
        scanf ("%d", &(data[i].y));
    }
    qsort (data, size, sizeof (struct Point), cmp_Point);
    for (int i = 0; i < size; i++)
    {
        printf ("%d %d\n", data[i].x, data[i].y);
    }
    free (data);
    return 0;
}

int cmp_Point (const void* p1, const void* p2)
{
    struct Point* pt1 = (struct Point*)p1;
    struct Point* pt2 = (struct Point*)p2;
    if (pt1->x*pt1->x + pt1->y*pt1->y != pt2->x*pt2->x + pt2->y*pt2->y)
    {
        return pt1->x*pt1->x + pt1->y*pt1->y - pt2->x*pt2->x - pt2->y*pt2->y;
    }
    else if (pt1->x != pt2->x)
    {
        return pt1->x - pt2->x;
    }
    else
    {
        return pt1->y - pt2->y;
    }
}