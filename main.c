#include <stdio.h>
#include <stdlib.h>
# include "inc/ft_printf.h"
#include <limits.h>

int main()
{
    char c = 'c';
    int r = 0;
    long int l = LONG_MAX;
    long long int lon = LONG_LONG_MAX;
    void *v;
    char *s;

    v = &c;
    s = ft_strnew(10);
    r = printf("%% test %p %c %s %+-10d %li %#X %s %lld %lu %c %#lo %s %p %010d %d!\n", s, c, "toto", 10, l, 89, "test", lon, l, c, l,"tata", v, 79, -81);
    ft_putnbr(r);
    ft_putchar('\n');
    r = 0;
    r = ft_printf("%% test %p %c %s %+-10d %li %#X %s %lld %lu %c %#lo %s %p %010d %d!\n", s, c, "toto", 10, l, 89, "test", lon, l, c, l,"tata", v, 79, -81);
    ft_putnbr(r);
    ft_putchar('\n');
    return (0);
}


/*
    - PB avec long long
    - z & j ??
    - To do :
        - h & hh
        - S & C
        - taille mini
        - precision
*/
