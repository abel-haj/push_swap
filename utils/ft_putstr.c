#include "utils.h"

void    ft_putstr(char *s)
{
    size_t  i;

    i = 0;
    while (s[i])
    {
        ft_putchar(s[i]);
        i++;
    }
}