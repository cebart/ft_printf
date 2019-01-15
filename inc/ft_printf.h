#ifndef FT_PRINTF_H_INCLUDED
#define FT_PRINTF_H_INCLUDED
#include <stdarg.h>
# include "../libft/libft.h"
#define BUFF_SIZE 5000

int     ft_printf(const char *format, ...);
int     itos(int nbr, int base, int min, int zero);
void    minuscules(char *lettre);
int		ft_isconversion(int c);
int     options(const char *s, va_list *ap, int *i);
void    do_flag(char c, int *res);
void    get_flags(const char *s, int *i, int *res);
void    sharp_flag(char *temp, int *j, int *res);
void    zero_flag(char *temp, int *j, int *res);
#endif // FT_PRINTF_H_INCLUDED
