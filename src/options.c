# include "../inc/ft_printf.h"

void     unsi_e(char c, va_list *ap, int *res)
{
    unsigned int e;
    void *p;

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
 //   if (c = 'i')
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

int     options(char c, va_list *ap)
{
    int        res;

    res = 0;
    if (c == 'b' || c == 'i' || c == 'd' || c == 'c' || c == '%')
        entier(c, ap, &res);
    if (c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 'p')
        unsi_e(c, ap, &res);
    if ( c == 's')
        alpha_str(c, ap, &res);
    return (res);
}
