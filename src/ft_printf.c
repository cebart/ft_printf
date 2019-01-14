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
		    res += options(format[++i], &ap);
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

/*static int va_somme(int n, va_list* arg)
{
    if (n == 0) return 0;
    else return = va_arg(*arg, int) + va_somme(n-1, arg);
}
*/
