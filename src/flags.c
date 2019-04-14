# include "../inc/ft_printf.h"

void    sharp_flag(char *temp, int **j, int *res)
{
        int k;

        k = **j;
        while (!ft_isconversion(temp[k]))
            k++;
        if (temp[k] == 'o')
        {
            ft_putchar('0');
            (*res)++;
        }
        else if (temp[k] == 'x')
        {
            ft_putstr("0x");
            (*res) += 2 ;
        }
        else if (temp[k] == 'X')
        {
            ft_putstr("0X");
            (*res) += 2 ;
        }
        (**j)++;
}

void    zero_flag(char *temp, int **j, t_print *f)
{
        int     i;
        char    *nbr;
        int     k;

        i = 0;
        k = **j;
        (*f).f_zero = 1;
        while (ft_isdigit(temp[**j]))
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
        (*f).f_to_print = (*f).f_to_print + ft_atoi(nbr);
}

void    minus_flag(char *temp, int **j, t_print *f)
{
        int     i;
        char    *nbr;
        int     k;

        i = 0;
        k = **j;
        (*f).minus = 1;
        while (ft_isdigit(temp[(**j)]) || temp[(**j)] == '-')
        {
            (**j)++;
            i++;
        }
        nbr = ft_strnew(i - 1);
        i = 0;
        while (ft_isdigit(temp[++k]))
        {
            nbr[i] = temp[k];
            i++;
        }
        (*f).f_to_print = (*f).f_to_print + ft_atoi(nbr);
}

t_print    get_flags(const char *s, int *i, int *res, t_print f)
{
    char    *temp;

    temp = ft_strdup(s);
    if (temp[*i] == '#')
        sharp_flag(temp, &i, res);
    if (temp[*i] == '0')
        zero_flag(temp, &i, &f);
    if (temp[*i] == '+')
    {
        f.plus = 1;
        f.f_to_print--;
        (*i)++;
    }
    if (temp[*i] == '-')
        minus_flag(temp, &i, &f);
    if ((temp[*i] == 'l' && temp[(*i) + 1] == 'l') || temp[*i] == 'L')
    {
        f.lon_long = 1;
        f.uns_lon_long = 1;
        (*i) += 2;
    }
    else if (temp[*i] == 'l')
    {
        f.lon = 1;
        f.uns_lon = 1;
        (*i)++;
    }
    return (f);
}
