# include "../inc/ft_printf.h"

void    print_nbr(char *buff, int *res, t_print f)
{
    int i;
    int j;
    int temp;

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
    if (f.flag && f.flag[0] != '\0' && f.f_zero)
    {
        i = 0;
        temp = ft_strlen(f.flag) - 1;
        while (buff[i])
        {
            f.flag[temp] = buff[i];
            temp--;
            i++;
        }
        ft_putstr(f.flag);
        (*res) = ft_strlen(f.flag);
    }
    else if (f.flag && f.flag[0] != '\0' && f.minus)
    {
        j = 0;
        while (--i >= 0)
        {
            f.flag[j] = buff[i];
            j++;
        }
        ft_putstr(f.flag);
        (*res) = ft_strlen(f.flag);
    }
    else
    {
        while (--i >= 0)
        {
            ft_putchar(buff[i]);
            (*res)++;
        }
    }
}
