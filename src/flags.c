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

void    minus_flag(char *temp, int **j, t_print *f)                          //   faire une fonction avec zero_flag
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
    t_print *pf;

    pf = &f;
    temp = ft_strdup(s);
    if (temp[*i] == '#')
        sharp_flag(temp, &i, res);
    if (temp[*i] == '0')
        zero_flag(temp, &i, pf);
    if (temp[*i] == '+')
    {
        f.plus = 1;
        f.f_to_print--;
        (*i)++;
    }
    if (temp[*i] == '-')
        minus_flag(temp, &i, pf);
    return (f);
}
