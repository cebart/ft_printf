# include "../inc/ft_printf.h"

void     unsi_e(char c, va_list *ap, int *res, t_print f)
{
    if (c == 'p')
    {
        f.p = va_arg(*ap, void *);
        f.zero = 1;
        f.nbr = (int)f.p;
        *res += itos(16, f, f.nbr);
    }
    else
    {
        c = check_long(c, &f);
        if (f.uns_lon_long)
        {
            f.uns_lon_long = va_arg(*ap, unsigned long long int);
            conver_unsi_e(c, res, f, f.uns_lon_long);
        }
        else if (f.uns_lon)
        {
            f.uns_lon = va_arg(*ap, unsigned long int);
            conver_unsi_e(c, res, f, f.uns_lon);
        }
        else
        {
            f.uns_nbr = va_arg(*ap, unsigned int);
            conver_unsi_e(c, res, f, f.uns_nbr);
        }
    }
}

void    conver_unsi_e(char c, int *res, t_print f, size_t nbr)
{
        if (c == 'o')
            *res += itos(8, f, nbr);
        if (c == 'u')
            *res += itos(10, f, nbr);
        if (c == 'X')
            *res += itos(16, f, nbr);
        if (c == 'x')
        {
            f.min = 1;
            *res += itos(16, f, nbr);
        }
}

void     entier(char c, va_list *ap, int *res, t_print f)
{
    if (c == '%')
    {
        ft_putchar('%');
        (*res)++;
    }
    else
    {
        c = check_long(c, &f);
        if (f.lon_long)
        {
            f.lon_long = va_arg(*ap, long long int);
            conver_entier(c, res, f, f.lon_long);
        }
        else if (f.lon)
        {
            f.lon = va_arg(*ap, long int);
            conver_entier(c, res, f, f.lon);
        }
        else
        {
            f.nbr = va_arg(*ap, int);
            conver_entier(c, res, f, f.nbr);
        }
    }
}

void     conver_entier(char c, int *res, t_print f, long long int nbr)
{
        if (c == 'b')
            *res += itos(2, f, nbr);
        if (c == 'd' || c == 'i')
        {
            if (f.nbr >=0)
                *res += itos(10, f, nbr);
            else
                *res += signed_itos(10, f, nbr);
        }
        if (c == 'c')
        {
            ft_putchar(nbr);
            (*res)++;
        }
}

void     alpha_str(char c, va_list *ap, int *res)
{
    char *s;

    s = va_arg(*ap, char *);
    if (c == 's')
    {
        ft_putstr(s);
        *res = ft_strlen(s);
    }
}

int     options(const char *s, va_list *ap, int *i)
{
    int     res;
    t_print flag_plus;

    res = 0;
    flag_plus = set_struct();
    if (!ft_isconversion(s[*i]))
        flag_plus = get_flags(s, i, &res, flag_plus);
    if (ft_isconversion(s[*i]))
    {
        if (s[*i] == 'b' || s[*i] == 'i' || s[*i] == 'd'
                || s[*i] == 'c' || s[*i] == '%' || s[*i] == 'D')
            entier(s[*i], ap, &res, flag_plus);
        if (s[*i] == 'o' || s[*i] == 'u' || s[*i] == 'x' || s[*i] == 'X'
                || s[*i] == 'p' || s[*i] == 'O' || s[*i] == 'U')
            unsi_e(s[*i], ap, &res, flag_plus);
        if ( s[*i] == 's')
            alpha_str(s[*i], ap, &res);
    }
    return (res);
}
