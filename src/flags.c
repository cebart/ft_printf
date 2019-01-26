# include "../inc/ft_printf.h"

void    sharp_flag(char *temp, int **j, int *res)
{
        while (!ft_isconversion(temp[**j]))
            (**j)++;
        if (temp[**j] == 'o')
        {
            ft_putchar('0');
            (*res)++;
        }
        else if (temp[**j] == 'x')
        {
            ft_putstr("0x");
            (*res) += 2 ;
        }
        else if (temp[**j] == 'X')
        {
            ft_putstr("0X");
            (*res) += 2 ;
        }
}

char    *zero_flag(char *temp, int **j)                                 /* /!\ affiche le nombre de zero + la convertion aulieu de nombre de zero - nb print par convertion */
{
        int     i;
        char    *nbr;
        char    *str;
        int     k;

        i = 0;
        k = **j;
        while (ft_isdigit(temp[(**j)]))
        {
            (**j)++;
            i++;
        }
        nbr = ft_strnew(i);
        i = 0;
        while (ft_isdigit(temp[k++]))
        {
            nbr[i] = temp[k];
            i++;
        }
        i = ft_atoi(nbr);
        str = ft_strnew(i);
        k = 0;
        while (i-- > 0)
        {
            str[k] = '0';
            k++;
        }
        return (str);
}

char    *get_flags(const char *s, int *i, int *res)
{
    char    *temp;
    char    *flag;

    temp = ft_strdup(s);
    if (temp[*i] == '#')
        sharp_flag(temp, &i, res);
    if (temp[*i] == '0')
    {
        flag = zero_flag(temp, &i);
        return (flag);
    }
    return (0);
}
