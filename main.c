#include <stdio.h>
#include <stdlib.h>

int main()
{
    ft_putnbr(ft_printf("Hello %d %u world! !\n", 14, 14, 14));
    ft_putendl("vrai printf :");
    ft_putnbr(printf("Hello %d %u world! !\n", 14, 14, 14));
    return 0;
}
