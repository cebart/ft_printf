# include "../inc/ft_printf.h"

int     ft_printf(const char *format, ...)
{
    int res;
    int i;

    i = -1;
    res = 0;
    va_list ap;
    va_start(ap, format);

    while (format[++i] != '\0')
	{
        if (format[i] == '%')
        {
            i++;
            res += options(format, &ap, &i);
        }
		else
        {
            ft_putchar(format[i]);
            res++;
        }
	}
    va_end(ap);
    return (res);
}
