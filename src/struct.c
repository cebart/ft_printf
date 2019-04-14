# include "../inc/ft_printf.h"

t_print     set_struct(void)
{
    t_print new;

    new.flag = ft_strnew(1);   // useless ??
    new.plus = 0;
    new.min = 0;
    new.zero = 0;
    new.lon = 0;
    new.lon_long = 0;
    new.uns_nbr = 0;
    new.uns_lon = 0;
    new.uns_lon_long = 0;
    new.nbr = 0;
    new.p = NULL;
    new.minus = 0;
    new.f_zero = 0;
    new.f_to_print = 0;
    return (new);
}

/*void    del_struct(t_print f)
{
    ft_memdel((void **)f.flag);
    ft_memdel((void **)f.plus);
    ft_memdel((void **)f.min);
    ft_memdel((void **)f.zero);
    ft_memdel((void **)f.lon);
    ft_memdel((void **)f.lon_long);
    ft_memdel((void **)f.uns_nbr);
    ft_memdel((void **)f.nbr);
    ft_memdel((void **)f.p);
    ft_memdel((void **)f.minus);
    ft_memdel((void **)f.f_zero);
    ft_memdel((void **)f.f_to_print);
}
*/
