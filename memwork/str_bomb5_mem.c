#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* replace (const char* src);

int main (void)
{
    char* str = replace ("i have a bomb. you have few bombs.");
    printf ("%s\n", str);
    free (str);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* replace (const char* src)
{
    size_t len1 = strlen ("bomb");
    size_t len2 = strlen ("watermelon");
    char* str = (char*) calloc ((len2 / len1 + 1) * strlen (src), sizeof (char*));
    size_t ip_src = 0;
    size_t ip_str = 0;

    for ( ; ; )
    {
        if (src[ip_src] == '\0')
        {
            break;
        }
        else if (strlen (src + ip_src) < len1)
        {
            strcpy (str + ip_str, src + ip_src);
            break;
        }
        else if (strncmp (src + ip_src, "bomb", len1) == 0)
        {
            strcpy (str + ip_str, "watermelon");
            ip_str += len2;
            ip_src += len1;
        }
        else
        {
            str[ip_str] = src[ip_src];
            ip_src++;
            ip_str++;
        }
    }

    return (char*) realloc (str, strlen (str) + 1);
}