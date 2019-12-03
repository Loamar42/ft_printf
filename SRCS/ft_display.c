/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 11:53:48 by loamar            #+#    #+#             */
/*   Updated: 2019/11/29 14:55:10 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

static int		get_char_number(char *arg, t_flags *flags, char type)
{
	int			precision;
	int			nb_char;

	if (!flags || !flags->precision)
		return ((type == 'c') ? 1 : ft_strlen(arg));
	precision = ft_atoi(flags->precision);
	if (precision < 0)
		return (ft_strlen(arg));
	if (check_type_num(type) == 1 && flags->precision)
		nb_char = get_char_number3(arg, flags, type, precision);
	if (precision > ft_strlen(arg))
		nb_char = (type == 's') ? ft_strlen(arg) : precision;
	else
		nb_char = get_char_number2(arg, flags, type, precision);
	return ((type == 'c' || type == '%') ? 1 : nb_char);
}

static int		get_space_number(t_flags *flags, int nb_c)
{
	int			width;

	if (!flags || !flags->width)
		return (0);
	width = ft_atoi(flags->width);
	if (width > nb_c)
		return (width - nb_c);
	else
		return (0);
}

void			ft_put_space_zero(char *arg, char type, t_flags *fl, int nb_p)
{
	if (!fl || !fl->precision)
		ft_putzero(nb_p);
	else if (ft_atoi(fl->precision) != 0)
		ft_putspace(nb_p);
	else
		ft_putzero(nb_p);
}

static int		ft_print(char *arg, t_flags *fl, char type, t_count *count)
{
	int			ret;

	ret = 0;
	if (type == 'c')
		write(1, &arg[0], 1);
	else if (count->nb_c > ft_strlen(arg) && check_type_num(type) == 0)
	{
		count->check = print_n_ox(arg, type, fl);
		ft_putzero(count->nb_c - ft_strlen(arg));
		ft_putstr(arg);
	}
	else if (check_type_num(type) == 1 && fl->precision)
		ret += print_pre_and_num(arg, fl, type, count);
	else
	{
		if (count->check == 0)
			count->check = print_n_ox(arg, type, fl);
		if (type == 'p')
			ret += count->check;
		count->check = check_addr(type, count->check);
		while (count->check < count->nb_c)
			write(1, &arg[count->check++], 1);
	}
	return (ret);
}

void			ft_display(char *arg, char type, t_flags *flags, int *size)
{
	t_count		*count;

	count = init_count();
	count->nb_c = get_char_number(arg, flags, type);
	count->nb_s = get_space_number(flags, count->nb_c);
	if (check_type_i(type) == 1 || type == 'p')
		count->nb_s = check_space(arg, type, flags, count);
	*size += count->nb_c + count->nb_s;
	if (flags->flag == '-')
	{
		*size += ft_print(arg, flags, type, count);
		print_space(count->nb_s);
	}
	else if (flags->flag == '0')
	{
		ft_display3(arg, type, flags, count);
		*size += ft_print(arg, flags, type, count);
	}
	else
	{
		print_space(count->nb_s);
		*size += ft_print(arg, flags, type, count);
	}
	free(flags);
}
