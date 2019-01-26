# include "../inc/ft_printf.h"

t_print     set_struct(void)
{
    t_print new;

    new.flag = ft_strnew(1);   // useless ??
    new.plus = 0;
    new.min = 0;
    new.zero = 0;
    new.nbr = 0;
    new.p = NULL;
    new.minus = 0;
    new.f_zero = 0;
    new.f_to_print = 0;
    return (new);
}
