#ifndef FT_PRINTF_H_INCLUDED
#define FT_PRINTF_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
# include "../libft/libft.h"
#define BUFF_SIZE 50000


typedef struct		s_print
{
    char            *flag;
    int             plus;
    int             min;
    int             zero;
    size_t          lon;
    size_t          lon_long;
    unsigned int    uns_nbr;
    int             nbr;
    void            *p;
    int             minus;
    int             f_zero;
    int             f_to_print;
} t_print;

int     ft_printf(const char *format, ...);
int     itos(int base, t_print f, unsigned long long nbr);
int     signed_itos(int base, t_print f, long long nbr);
void    entier(char c, va_list *ap, int *res, t_print f);
void    unsi_e(char c, va_list *ap, int *res, t_print f);
void    conver_unsi_e(char c, int *res, t_print f, size_t nbr);
void    minuscules(char *lettre);
int		ft_isconversion(int c);
int     options(const char *s, va_list *ap, int *i);
void    do_flag(char c, int *res);
t_print get_flags(const char *s, int *i, int *res, t_print f);
void    sharp_flag(char *temp, int **j, int *res);
void    zero_flag(char *temp, int **j, t_print *f);
t_print set_struct(void);
/*void    del_struct(t_print f);*/
void    print_nbr(char *buff, int *res, t_print f);
#endif // FT_PRINTF_H_INCLUDED
