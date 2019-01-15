#include <stdio.h>
#include <stdlib.h>
# include "inc/ft_printf.h"

int main()
{
    char c = 'c';
    int r = 0;
    void *v;

    v = &c;
    r = printf("%c %s %010d %u %#X %o %X %#o %s %p %%!\n", c, "toto", 15, 15, 15, 15, 15, 70, "tata", v);
    ft_putnbr(r);
    ft_putchar('\n');
    r = 0;
    r = ft_printf("%c %s %010d %u %#X %o %X %#o %s %p %%!\n", c, "toto", 15, 15, 15, 15, 15, 70, "tata", v);
    ft_putnbr(r);
    ft_putchar('\n');

    return 0;
}
