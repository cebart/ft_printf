# include "../inc/ft_printf.h"

int		ft_isconversion(int c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z' || c == '-' || c == 'l')
        return (0);
	if ((c <= 'Z' && c >= 'A') || (c <= 'z' && c >= 'a') || c == '%')
		return (1);
	return (0);
}

char    check_long(char c, t_print *f)
{

    if ( c == 'D')
    {
       if ((*f).lon)
            (*f).lon_long = 1;
       else
            (*f).lon = 1;
       c += 32;
    }
    else if ( c == 'O' || c == 'U')
    {
       if ((*f).uns_lon)
            (*f).uns_lon_long = 1;
       else
            (*f).uns_lon = 1;
        c += 32;
    }
    return (c);
}
