#ifndef FT_PRINTF_H_INCLUDED
#define FT_PRINTF_H_INCLUDED
#include <stdarg.h>
# include "../libft/libft.h"
#define BUFF_SIZE 5000

int     ft_printf(const char *format, ...);
int     itos(int nbr, int base, int min);
void    minuscules(char *lettre);
int     options(char c, va_list* ap);

#endif // FT_PRINTF_H_INCLUDED
