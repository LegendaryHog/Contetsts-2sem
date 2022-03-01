#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

typedef struct
{
	int x, y;
}
Coord;

typedef struct
{
    Coord* pt;
    int n;
}
Points;

Points* getPoints (FILE* file)
{
    Points* points = (Points*) calloc (1, sizeof (Points));
    points->pt     = (Coord*)  calloc (8, sizeof (Coord));
    int size = 8;
    int i = 0;
    while (fscanf (file, "%d%d", &points->pt[i].x, &points->pt[i].y) != EOF)
    {
        i++;
        if (i == size)
        {
            size *= 2;
            points->pt = (Coord*) realloc (points->pt, size * sizeof (Coord));
            for (int j = size * sizeof (Coord) / 2; j < size * sizeof (Coord); j++)
            {
                *((char*)points->pt + j) = 0;
            }
        }
    }
    points->n = i;
    if (points->n < 2)
    {
        free (points->pt);
        free (points);
        return NULL;
    }
    return points;
}

void distPr(FILE* fout, Points* points)
{
    if (points == NULL)
    {
        printf ("NO\n");
        return;
    }
    if (points->n == 0)
    {
        printf ("NO\n");
        free (points->pt);
        free (points);
        return;
    }

    for (int i = 0; i < points->n; i++)
    {
        for (int j = i + 1; j < points->n; j++)
        {
            int x1 = points->pt[i].x;
            int y1 = points->pt[i].y;
            int x2 = points->pt[j].x;
            int y2 = points->pt[j].y;
            fprintf (fout, "(%d, %d) (%d, %d) %0.2f\n", x1, y1, x2, y2, sqrt((float)(x1 - x2)*(x1 - x2) + (float)(y1 - y2)*(y1 - y2)));
        }
    }
    free (points->pt);
    free (points);   
}

int main (void)
{
    Points* points = getPoints (stdin);

    distPr (stdout, points);
    return 0;
}
