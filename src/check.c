# include "../inc/ft_printf.h"

int		ft_isconversion(int c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z' || c == '-')
        return (0);
	if ((c <= 'Z' && c >= 'A') || (c <= 'z' && c >= 'a') || c == '%')
		return (1);
	return (0);
}
