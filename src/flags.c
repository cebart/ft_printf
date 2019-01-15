# include "../inc/ft_printf.h"

void    sharp_flag(char *temp, int *j, int *res)
{
        while (!ft_isconversion(temp[*j]))
            (*j)++;
        if (temp[*j] == 'o')
        {
            ft_putchar('0');
            (*res)++;
        }
        else if (temp[*j] == 'x')
        {
            ft_putstr("0x");
            (*res) += 2 ;
        }
        else if (temp[*j] == 'X')
        {
            ft_putstr("0X");
            (*res) += 2 ;
        }
}

void    zero_flag(char *temp, int *j, int *res)                                 /* /!\ affiche le nombre de zero + la convertion aulieu de nombre de zero - nb print par convertion */
{
        int     i;
        int     tp;
        char    *nbr;

        tp = *j;
        i = 0;
        while (ft_isdigit(temp[tp++]))
            i++;
        nbr = ft_strnew(i);
        i = 0;
        while (ft_isdigit(temp[(*j)++]))
        {
            nbr[i] = temp[(*j)];
            i++;
        }
        i = ft_atoi(nbr);
        while (--i > 0)
        {
            ft_putchar('0');
            (*res)++;
        }
}
void    get_flags(const char *s, int *i, int *res)
{
    char    *temp;
    int     j;

    temp = ft_strdup(s);
    j = *i;
    if (temp[j] == '#')
        sharp_flag(temp, &j, res);
    if (temp[j] == '0')
        zero_flag(temp, &j, res);
}
