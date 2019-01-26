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
        (*f).flag = ft_strnew(i);
        k = 0;
        while (i-- > 0)
        {
            (*f).flag[k] = '0';
            k++;
        }
}

void    minus_flag(char *temp, int **j, t_print *f)                          //   renvoyer juste le nbr puis afficher dans print ' ' jusqu'a nbr
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
        i = ft_atoi(nbr);
        (*f).flag = ft_strnew(i);
        k = 0;
        while (i-- > 0)
        {
            (*f).flag[k] = ' ';
            k++;
        }
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
    if (temp[*i] == '+')                             //   /!\ prend une place en cas de 0 ou -
    {
        f.plus = 1;
        (*i)++;
    }
    if (temp[*i] == '-')
        minus_flag(temp, &i, pf);
    return (f);
}
