/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:04:01 by loamar            #+#    #+#             */
/*   Updated: 2019/11/29 16:06:40 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
**---------------------INCLUDES------------------------
*/

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

/*
**----------------STRUCTURES-------------------
*/

typedef struct	s_printf
{
	int			check;
	int			index;
	int			size;
	char		*arg;
	char		type;
}				t_printf;

typedef struct	s_count
{
	int			nb_c;
	int			nb_s;
	int			check;
}				t_count;

typedef struct	s_flags
{
	char	flag;
	char	*width;
	char	*precision;
}				t_flags;

/*
**----------------PROTOTYPES PRINCIPAUX-------------------
*/

int				ft_printf(const char *format, ...);
t_flags			*get_flags(const char *format, va_list ap, t_printf *v);
t_flags			*get_flags2(const char *form, t_flags *fl, va_list ap,
				t_printf *v);
t_flags			*get_flags3(t_flags *fl, va_list ap, t_printf *v);
char			get_type(const char *format, int index);
char			*get_arg(char type, va_list ap, int *index, t_flags *fl);
void			ft_display(char *arg, char type, t_flags *flags,
				int *ret_size);
void			ft_display3(char *arg, char type, t_flags *fl, t_count *count);
int				print_pre_and_num(char *arg, t_flags *flags, char type,
				t_count *count);
char			*get_address(long adr);

/*
**----------------PROTOTYPES SECONDAIRES-------------------
*/

char			*get_width(const char *format, int *index);
char			*get_precision(const char *format, int *index);
void			ft_put_space_zero(char *arg, char type, t_flags *fl, int nb);
int				ft_isflag(t_flags *flags, char c);
t_flags			*flags_init(void);
void			free_flags(t_flags *flags);
char			flag_loop(const char *format, char flag, int *index);
char			*get_stars(va_list ap, t_flags *flags);
int				print_n_ox(char *arg, char type, t_flags *flags);
int				get_char_number2(char *arg, t_flags *flags, char type,
				int precision);
int				get_char_number3(char *arg, t_flags *flags, char type,
				int precision);

/*
**----------------PROTOTYPES TERTIAIRES-------------------
*/

int				check_basexlower(char *arg);
int				check_basexupper(char *arg);
t_count			*init_count(void);
int				num_noradd(char *arg, t_flags *flags, char type,
				t_count *count);
void			num_else(char *arg, t_flags *flags, char type);
int				check_type_i(char c);
int				check_type_num(char c);
int				check_addr(char type, int check);
int				return_except(char *arg, t_flags *flags, int nb_char_to_print,
				char type, int check);
void			print_space(int nb_space_to_print);
int				check_type_ex(char c);
int				check_space(char *arg, char type, t_flags *fl, t_count *count);

#endif
