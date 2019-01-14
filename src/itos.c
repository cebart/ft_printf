# include "../inc/ft_printf.h"

void    minuscules(char *lettre)
{
    int i;

    i = 10;
    while (lettre[i])
        lettre[i++] += 32;
}

int    itos(int nbr, int base, int min)
{
    char buff[BUFF_SIZE];
    char lettre[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int cmp;
    int temp;
    int res;

    cmp = 0;
    temp = 0;
    res = 0;
    if(nbr < 0)
    {
        res++;
        ft_putchar('-');
    }
    if (min != 0)
        minuscules(lettre);
    while(nbr != 0)
    {
        temp = nbr % base;
        temp = (temp < 0) ? -temp : temp;
        buff[cmp] = lettre[temp];
        cmp++;
        nbr = nbr/base;

    }
    cmp--;
    while (cmp >= 0)
    {
        ft_putchar(buff[cmp]);
        res++;
        cmp--;
    }
    return (res);
}
