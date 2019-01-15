# include "../inc/ft_printf.h"

void     unsi_e(char c, va_list *ap, int *res)
{
    unsigned int    e;
    void            *p;

    if (c == 'p')
    {
        p = va_arg(*ap, void *);                        /* manque les 000 */
        *res += itos((int)p, 16, 0, 1);
    }
    else
    {
        e = va_arg(*ap, unsigned int);
        if (c == 'o')
            *res += itos(e, 8, 0, 0);
        if (c == 'u')
            *res += itos(e, 10, 0, 0);
        if (c == 'X')
            *res += itos(e, 16, 0, 0);
        if (c == 'x')
            *res += itos(e, 16, 1, 0);
    }
}

void     entier(char c, va_list *ap, int *res)
{
    int e;

    e = va_arg(*ap, int);
    if (c == 'b')
        *res += itos(e, 2, 0, 0);
    if (c == 'd' || c == 'i')
        *res += itos(e, 10, 0, 0);
    if (c == '%')
    {
        ft_putchar(c);
        (*res)++;
    }
    if (c == 'c')
    {
        ft_putchar(e);
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
//    char    *flag;

  //  flag = ft_strnew(10);              /* # | 0 | - | + | h | hh | l | ll | j | z */
    res = 0;
    while (!ft_isconversion(s[*i]))
    {
        get_flags(s, i, &res);
        (*i)++;
    }
    if (ft_isconversion(s[*i]))
    {
        if (s[*i] == 'b' || s[*i] == 'i' || s[*i] == 'd' || s[*i] == 'c' || s[*i] == '%')
            entier(s[*i], ap, &res);
        if (s[*i] == 'o' || s[*i] == 'u' || s[*i] == 'x' || s[*i] == 'X' || s[*i] == 'p')
            unsi_e(s[*i], ap, &res);
        if ( s[*i] == 's')
            alpha_str(s[*i], ap, &res);
    }
    return (res);
}
