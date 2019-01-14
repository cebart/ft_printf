# include "../inc/ft_printf.h"

void     unsi_e(char c, va_list* ap, int *res)
{
    unsigned int e;

    e = 0;
    if (c == 'o')
    {
        e = va_arg(*ap, unsigned int);
        *res += itos(e, 8, 0) + 1;
    }
    if (c == 'u')
    {
        e = va_arg(*ap, unsigned int);
        *res += itos(e, 10, 0);
    }
    if (c == 'X')
    {
        e = va_arg(*ap, unsigned int);
        *res += itos(e, 16, 0) + 2;
    }
    if (c == 'x')
    {
        e = va_arg(*ap, unsigned int);
        *res += itos(e, 16, 1) + 2;
    }
}

void     entier(char c, va_list* ap, int *res)
{
    int e;

    e = 0;
 //    unsigned char  ch;
     if (c == 'b')
    {
        e = va_arg(*ap, int);
        *res += itos(e, 2, 0);
    }
 //   if (c = 'i')
    if (c == 'd')
    {
        e = va_arg(*ap, int);
        *res += itos(e, 10, 0);
    }
    if (c == '%')
    {
        ft_putchar(c);
        (*res)++;
    }
/*    if (c == 'c')
    {
        ch = va_arg(ap, int);
        ft_putchar(ch);
        res++;
    }*/
}

int     options(char c, va_list* ap)
{
     int        res;

    res = 0;
    if (c == 'b' || c == 'i' || c == 'd' || c == 'c' || c == '%')
        entier(c, ap, &res);
    if (c == 'o' || c == 'u' || c == 'x' || c == 'X')
        unsi_e(c, ap, &res);
    return (res);
}
