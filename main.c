#include <stdio.h>
#include <stdlib.h>
# include "inc/ft_printf.h"
#include <limits.h>

int main()
{
    char c = 'c';
    int r = 0;
    long int l = LONG_MAX;
    void *v;
    char *s;

    v = &c;
    s = ft_strnew(10);
    r = printf("%% test %p %c %s %+-10d %ld %#X %s %lo %lu %c %#lo %s %p %010d %d!\n", s, c, "toto", 10, l, 89, "test", l, l, c, l,"tata", v, 79, -81);
    ft_putnbr(r);
    ft_putchar('\n');
    r = 0;
    r = ft_printf("%% test %p %c %s %+-10d %d %#X %s %lo %lu %c %#lo %s %p %010d %d!\n", s, c, "toto", 10, l, 89, "test", l, l, c, l,"tata", v, 79, -81);
    ft_putnbr(r);
    ft_putchar('\n');
    return (0);
}


