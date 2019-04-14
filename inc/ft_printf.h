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
    long int        lon;
    long long int   lon_long;
    unsigned int    uns_nbr;
    size_t          uns_lon;
    size_t          uns_lon_long;
    int             nbr;
    void            *p;
    int             minus;
    int             f_zero;
    int             f_to_print;
} t_print;

int     ft_printf(const char *format, ...);
int     itos(unsigned int base, t_print f, size_t nbr);
int     signed_itos(int base, t_print f, long long nbr);
void    entier(char c, va_list *ap, int *res, t_print f);
void     conver_entier(char c, int *res, t_print f, long long int nbr);
void    unsi_e(char c, va_list *ap, int *res, t_print f);
void    conver_unsi_e(char c, int *res, t_print f, size_t nbr);
void    minuscules(char *lettre);
int		ft_isconversion(int c);
char    check_long(char c, t_print *f);
int     options(const char *s, va_list *ap, int *i);
void    do_flag(char c, int *res);
t_print get_flags(const char *s, int *i, int *res, t_print f);
void    sharp_flag(char *temp, int **j, int *res);
void    zero_flag(char *temp, int **j, t_print *f);
t_print set_struct(void);
/*void    del_struct(t_print f);*/
void    print_nbr(char *buff, int *res, t_print f);
#endif // FT_PRINTF_H_INCLUDED
