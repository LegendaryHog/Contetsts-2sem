#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char* a;
    unsigned n;
    unsigned size;
} Decimal;

void add (const Decimal* a, const Decimal* b, Decimal* res);

int main (void)
{
    Decimal a = {};
    Decimal b = {};
    a.a = (char*) calloc (1, sizeof (char));
    a.n = 0;
    a.a[0] = 0;
    a.size = 1;
    b.a = (char*) calloc (1, sizeof (char));
    b.a[0] = 0;
    b.n    = 0;
    b.size = 1;
    Decimal res = {};
    add (&a, &b, &res);
    printf ("res.n = %u\n", res.n);
    printf ("res.size = %u\n", res.size);
    for (int i = (int)res.size - 1; i >= 0; i--)
    {
        printf ("%d", res.a[i]);
    }
    printf ("\n");
    free (res.a);
    free (a.a);
    free (b.a);
    return 0;
}

void add (const Decimal* a, const Decimal* b, Decimal* res)
{
    unsigned max_sz = 0;

    Decimal* acpy = (Decimal*) calloc (1, sizeof (Decimal));
    Decimal* bcpy = (Decimal*) calloc (1, sizeof (Decimal));

    acpy->n    = a->n;
    bcpy->n    = b->n;
    acpy->size = a->size;
    bcpy->size = b->size;

    if (a->size > b->size)
    {
        max_sz = a->size + 1;
    }
    else
    {
        max_sz = b->size + 1;
    }

    res->a = (char*) calloc  (max_sz, sizeof (char));

    acpy->a = (char*) calloc (max_sz, sizeof (char));
    for (unsigned i = 0; i <= a->n; i++)
    {
        acpy->a[i] = a->a[i];
    }
    bcpy->a = (char*) calloc (max_sz, sizeof (char));
    for (unsigned i = 0; i <= b->n; i++)
    {
        bcpy->a[i] = b->a[i];
    }
    res->size  = max_sz;
    acpy->size = max_sz;
    bcpy->size = max_sz;

    for (unsigned i = 0; i < max_sz; i++)
    {
        res->a[i] = acpy->a[i] + bcpy->a[i];
    }

    for (unsigned i = 0; i < max_sz; i++)
    {
        if (i + 1 < max_sz)
        {
            res->a[i+1] += res->a[i] / 10;
        }
        res->a[i] = res->a[i] % 10;
    }

    for (long long i = (long long)res->size - 1; i >= 0; i--)
    {
        if (res->a[i] != 0)
        {
            res->n = (unsigned)i;
            break;
        }
    }
    res->a = (char*) realloc (res->a, res->n + 1);
    res->size = res->n + 1;
    free (acpy->a);
    free (acpy);
    free (bcpy->a);
    free (bcpy);
}