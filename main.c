#include <stdio.h>
#include <stdlib.h>
# include "inc/ft_printf.h"

int main()
{
    char c = 'c';
    int r = 0;

    r = printf("%c %s!\n", c, "toto");
    ft_putnbr(r);
    ft_putchar('\n');
    r = 0;
    r = ft_printf("%c %s!\n", c, "toto");
    ft_putnbr(r);
    ft_putchar('\n');

    return 0;
}
