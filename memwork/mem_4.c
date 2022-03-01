#include <stdio.h>
#include <stdlib.h>

typedef int Data;

struct Stack {
    int n;
    int size;
    Data* a; 
};

struct Stack* stack_create (int size);
void stack_push (struct Stack* s, Data x);
Data stack_pop(struct Stack* s);
Data stack_get(struct Stack* s);
void stack_print(struct Stack * s);
int  stack_size(struct Stack * s);
int  stack_is_empty(struct Stack * s);
void stack_clear(struct Stack * s);
void stack_destroy(struct Stack * s);

struct Stack* stack_create (int size)
{
    struct Stack* stk = (struct Stack*) calloc (1, sizeof (struct Stack));
    stk->n = 0;
    stk->size = size;
    stk->a = (Data*) calloc (stk->size, sizeof (Data));
    return stk;
}

void stack_push (struct Stack* s, Data x)
{
    if (s->n == s->size)
    {
        s->size *= 2;
        s->a = (Data*) realloc (s->a, s->size * sizeof (Data));
    }

    s->a[s->n] = x;
    s->n++;
}

Data stack_pop (struct Stack* s)
{
    s->n--;
    Data pop = s->a[s->n];
    s->a[s->n] = 0;
    return pop; 
}

Data stack_get (struct Stack* s)
{
    return s->a[s->n - 1];
}

void stack_print (struct Stack* s)
{
    if (s->n == 0)
    {
        printf ("Empty stack\n");
    }
    else
    {
        for (int i = 0; i < s->n; i++)
        {
            printf ("%d ", s->a[i]);
        }
        printf ("\n");
    }
}

int stack_size (struct Stack* s)
{
    return s->n;
}

void stack_clear (struct Stack* s)
{
    for (int i = 0; i < s->n; i++)
    {
        s->a[i] = 0;
    }
    s->n = 0;
}

void stack_destroy (struct Stack* s)
{
    free (s->a);
    free (s);
}

int stack_is_empty(struct Stack * s)
{
    if (s->n == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main (void)
{
    int x = 0;
    struct Stack* stk = stack_create (16); 
    do
    {
        scanf ("%d", &x); 
        stack_push (stk, x);
    } while (getchar () != '\n');

    while (stack_is_empty (stk) == 0)
    {
        printf ("%d ", stack_pop (stk));
    }
    printf ("\n");
    stack_destroy (stk);
    return 0;
}
