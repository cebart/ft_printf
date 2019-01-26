# include "../inc/ft_printf.h"

void    minuscules(char *lettre)
{
    int i;

    i = 10;
    while (lettre[i])
        lettre[i++] += 32;
}

int    itos(int base, t_print f)
{
    char *buff;
    char lettre[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int cmp;
    int temp;
    int res;

    cmp = 0;
    temp = 0;
    res = 0;
    buff = ft_strnew(BUFF_SIZE);
    if(f.nbr < 0)
    {
        res++;
        ft_putchar('-');
    }
    else if(f.plus)
    {
        res++;
        ft_putchar('+');
    }
    if (f.min != 0)
        minuscules(lettre);
    while(f.nbr != 0)
    {
        temp = f.nbr % base;
        temp = (temp < 0) ? -temp : temp;
        buff[cmp] = lettre[temp];
        cmp++;
        f.nbr = f.nbr/base;
    }
    print_nbr(buff, &res, f);
    return (res);
}
