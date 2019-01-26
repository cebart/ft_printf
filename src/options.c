# include "../inc/ft_printf.h"

void     unsi_e(char c, va_list *ap, int *res, t_print f)
{
    unsigned int    e;
    void            *p;

    if (c == 'p')
    {
        p = va_arg(*ap, void *);
        f.zero = 1;
        *res += itos((int)p, 16, f);
    }
    else
    {
        e = va_arg(*ap, unsigned int);
        if (c == 'o')
            *res += itos(e, 8, f);
        if (c == 'u')
            *res += itos(e, 10, f);
        if (c == 'X')
            *res += itos(e, 16, f);
        if (c == 'x')
        {
            f.min = 1;
            *res += itos(e, 16, f);
        }
    }
}

void     entier(char c, va_list *ap, int *res, t_print f)
{
    int e;

    if (c == '%')
    {
        ft_putchar('%');
        (*res)++;
    }
    else
    {
        e = va_arg(*ap, int);
        if (c == 'b')
            *res += itos(e, 2, f);
        if (c == 'd' || c == 'i')
            *res += itos(e, 10, f);
        if (c == 'c')
        {
            ft_putchar(e);
            (*res)++;
        }
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
        flag_plus.flag = get_flags(s, i, &res);
    if (ft_isconversion(s[*i]))
    {
        if (s[*i] == 'b' || s[*i] == 'i' || s[*i] == 'd' || s[*i] == 'c' || s[*i] == '%')
            entier(s[*i], ap, &res, flag_plus);
        if (s[*i] == 'o' || s[*i] == 'u' || s[*i] == 'x' || s[*i] == 'X' || s[*i] == 'p')
            unsi_e(s[*i], ap, &res, flag_plus);
        if ( s[*i] == 's')
            alpha_str(s[*i], ap, &res);
    }
    return (res);
}
