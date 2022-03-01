#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char* dig;
    int   n;
    char  sign;
} LongN;

LongN getLongN (char* s);

int main (void)
{
    LongN a = getLongN ("+1234");

    printf ("a.n = %d\n", a.n);

    for (int i = a.n - 1; i >= 0; i--)
    {
        printf ("%d ", a.dig[i]);
    }
    putchar ('\n');
    
    return 0;
}

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

LongN getLongN (char* s)
{
    LongN num = {};
    int i = 0;
    Skip_Spaces (s, &i);
    if (s[i] == '-')
    {
        i++;
        num.sign = 1;
    }
    else if (s[i] == '+')
    {
        i++;
        num.sign = 0;
    }
    else
    {
        num.sign = 0;
    }
    Skip_Spaces (s, &i);

    int digitnum = 0;

    while (s[i] >= '0' && s[i] <= '9')
    {
        i++;
        digitnum++;
    }
    num.n = digitnum/2 + digitnum%2;

    num.dig = (char*) calloc (num.n, sizeof (char));
    i--;
    int j = 0;
    while (j < num.n && i >= 0)
    {
        if (i > 0 && s[i - 1] >= '0' && s[i - 1] <= '9')
        {
            num.dig[j] = (s[i] - '0') + (s[i - 1] - '0') * 10;
        }
        else
        {
            num.dig[j] = s[i] - '0';
        }
        i -= 2;
        j++;
    }
    return num;
}