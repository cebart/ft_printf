# include "../inc/ft_printf.h"

void    minuscules(char *lettre)
{
    int i;

    i = 10;
    while (lettre[i])
        lettre[i++] += 32;
}

int     signed_itos(int base, t_print f, long long nbr)
{
        int res;

        res = 0;
        ft_putchar('-');
        res++;
        nbr = -nbr;
        res += itos(base, f, nbr);
        return (res);
}

int    itos(int base, t_print f, unsigned long long nbr)
{
    char *buff;
    char lettre[] = "0123456789ABCDEF";
    int i;
    int temp;
    int res;

    i = 0;
    temp = nbr;
    res = 0;
    if(f.plus)
    {
        res++;
        ft_putchar('+');
    }
    while (temp >= base)
	{
		temp = temp / base;
		i++;
	}
    buff = ft_strnew(i);
	i = 0;
	temp = 0;
    if (f.min != 0)
        minuscules(lettre);
    while(nbr != 0)
    {
        temp = nbr % base;
        buff[i] = lettre[temp];
        i++;
        nbr = nbr/base;
    }
    print_nbr(buff, &res, f);
    return (res);
}

