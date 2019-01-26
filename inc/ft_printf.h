#ifndef FT_PRINTF_H_INCLUDED
#define FT_PRINTF_H_INCLUDED
#include <stdarg.h>
# include "../libft/libft.h"
#define BUFF_SIZE 5000


typedef struct		s_print
{
    char    *flag;
    int     plus;
    int     min;
    int     zero;
    int     nbr;
    int     base;
} t_print;

int     ft_printf(const char *format, ...);
int     itos(int nbr, int base, t_print f);
void    entier(char c, va_list *ap, int *res, t_print f);
void    unsi_e(char c, va_list *ap, int *res, t_print f);
void    minuscules(char *lettre);
int		ft_isconversion(int c);
int     options(const char *s, va_list *ap, int *i);
void    do_flag(char c, int *res);
char    *get_flags(const char *s, int *i, int *res);
void    sharp_flag(char *temp, int **j, int *res);
char    *zero_flag(char *temp, int **j);
t_print set_struct(void);
void    print_nbr(char *buff, int *res, t_print f);
#endif // FT_PRINTF_H_INCLUDED
