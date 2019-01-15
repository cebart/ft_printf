# include "../inc/ft_printf.h"

void    print_nbr(char *buff, int zero, int *res)
{
    int i;
    int j;

    i = 0;
    j = 8;
    if (buff[i] == 0)
        ft_putchar('0');
    while (buff[i])
        i++;
    if (zero && (j - i))
    {
        j = j - i;
         while (j--)
         {
            ft_putchar('0');
            (*res)++;
         }
    }
    while (--i >= 0)
    {
        ft_putchar(buff[i]);
        (*res)++;
    }
}

void    minuscules(char *lettre)
{
    int i;

    i = 10;
    while (lettre[i])
        lettre[i++] += 32;
}

int    itos(int nbr, int base, int min, int zero)
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
    print_nbr(buff, zero, &res);
    return (res);
}
