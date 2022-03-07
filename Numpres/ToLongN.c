#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char  dig[100];
    int   n;
    char  sign;
} LongN;

size_t Skip_Spaces (char* str, int* ptr_i)
{
   size_t counter = 0;
   while (str[*ptr_i] == ' ' || str[*ptr_i] == '\t')
   {
       (*ptr_i)++;
       counter++;
   }
   return counter;
}

LongN* getLongN (char* s)
{
    LongN* num = (LongN*) calloc (1, sizeof (LongN) + 100*sizeof(char));
    int i = 0;
    Skip_Spaces (s, &i);
    if (s[i] == '-')
    {
        i++;
        num->sign = 1;
    }
    else if (s[i] == '+')
    {
        i++;
        num->sign = 0;
    }
    else
    {
        num->sign = 0;
    }
    Skip_Spaces (s, &i);

    int digitnum = 0;

    while (s[i] >= '0' && s[i] <= '9')
    {
        i++;
        digitnum++;
    }
    num->n = digitnum/2 + digitnum%2;

    i--;

    int j = 0;

    while (j < num->n && i >= 0)
    {
        if (i > 0 && s[i - 1] >= '0' && s[i - 1] <= '9')
        {
            num->dig[j] = (s[i] - '0') + (s[i - 1] - '0') * 10;
        }
        else
        {
            num->dig[j] = s[i] - '0';
        }
        i -= 2;
        j++;
    }
    return num;
}

LongN* copyLN(const LongN* b)
{
    LongN* cpy = (LongN*) calloc (1, sizeof (LongN) + 100*sizeof(char));
    cpy->n = b->n;
    cpy->sign = b->sign;
    for (int i = 0; i < b->n; i++)
    {
        cpy->dig[i] = b->dig[i];
    }
    return cpy;
}

void showDigit(const LongN* a)
{
    if (a->sign == 0)
    {
        printf ("+ ");
    }
    else
    {
        printf ("- ");
    }

    for (int i = a->n - 1; i >= 0; i--)
    {
        printf ("%d ", a->dig[i]);
    }
    putchar ('\n');
}

void destroyLN (LongN* a)
{
    free (a);
}