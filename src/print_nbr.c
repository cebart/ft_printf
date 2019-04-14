# include "../inc/ft_printf.h"

void    print_nbr(char *buff, int *res, t_print f)
{
    int i;
    int j;

    i = 0;
    j = 8;
    if (buff[i] == 0)
        ft_putchar('0');
    while (buff[i])
        i++;
    if (f.zero && (j - i))
    {
        j = j - i;
         while (j--)
         {
            ft_putchar('0');
            (*res)++;
         }
    }
    if (f.f_zero)
    {

        j = 0;
        f.f_to_print = f.f_to_print - ft_strlen(buff);
        while (j < f.f_to_print)
        {
            ft_putchar('0');
            j++;
            (*res)++;
        }
        while (--i >= 0)
        {
            ft_putchar(buff[i]);
            (*res)++;
        }
    }
    else
    {
        j = 0;
        while (--i >= 0)
        {
            ft_putchar(buff[i]);
            (*res)++;
            j++;
        }
        if (f.minus == 1)
        {
            while (j < f.f_to_print)
            {
                    ft_putchar(' ');
                    j++;
                    (*res)++;
            }
        }
    }
    ft_strdel(&buff);
}
