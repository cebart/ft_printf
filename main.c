#include <stdio.h>
#include <stdlib.h>
# include "inc/ft_printf.h"

int main()
{
    char c = 'c';
    int r = 0;
    void *v;
    char *s;

    v = &c;
    s = ft_strnew(10);
    r = printf("%% test %p %c %s %d %u %#X %o %#x %#o %s %p %010d %d!\n", s, c, "toto", 10, 1542, 15, 15, 15, 15,"tata", v, 79, -81);
    ft_putnbr(r);
    ft_putchar('\n');
    r = 0;
    r = ft_printf("%% test %p %c %s %d %u %#X %o %#x %#o %s %p %010d %d!\n", s, c, "toto", 10, 1542, 15, 15, 15, 15,"tata", v, 79, -81);
    ft_putnbr(r);
    ft_putchar('\n');

    return (0);
}
