/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 12:00:10 by loamar            #+#    #+#             */
/*   Updated: 2019/11/29 15:12:37 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

int		print_pre_and_num(char *arg, t_flags *flags, char type, t_count *count)
{
	int	ret;

	ret = 0;
	if (count->check == 0)
		count->check = print_n_ox(arg, type, flags);
	if (ft_atoi(flags->precision) == 0 && ft_atoi(arg) == 0)
		ft_putstr("");
	else if (count->check == 1 || count->check == 2)
		ret = num_noradd(arg, flags, type, count);
	else if (count->check == 0)
		num_else(arg, flags, type);
	return (ret);
}

void	print_space(int nb_space_to_print)
{
	if (nb_space_to_print > 0)
		ft_putspace(nb_space_to_print);
}

int		get_char_number2(char *arg, t_flags *flags, char type, int precision)
{
	int	nb_char;

	if (precision == 0 && (type == 's' || type == '%'))
		return ((type == '%') ? 1 : 0);
	if (precision == 0 && ft_atoi(arg) == 0 && check_type_num(type) == 1)
		return (0);
	if (precision == 0 && type == 'x' && check_basexlower(arg) == 1)
		return (0);
	if (precision == 0 && type == 'X' && check_basexupper(arg) == 1)
		return (0);
	if (check_type_num(type) == 1 && (precision == 0 || precision == 1))
	{
		if (arg[0] == '-')
			return (ft_strlen(arg) - 1);
	}
	return (nb_char = (type == 's') ? precision : ft_strlen(arg));
}

int		get_char_number3(char *arg, t_flags *flags, char type, int precision)
{
	int	nb_char;

	if (ft_atoi(arg) < 0 && precision > (ft_strlen(arg) - 1))
		nb_char = precision;
	if (ft_atoi(arg) > 0 && precision > ft_strlen(arg))
		nb_char = precision;
	return (nb_char);
}

int		check_space(char *arg, char type, t_flags *fl, t_count *count)
{
	int	precision;

	if (fl->precision)
		precision = ft_atoi(fl->precision);
	if (type == 'p' && fl->width && ft_atoi(fl->width) > 2)
		return (count->nb_s - 2);
	if (ft_atoi(arg) < 0 && (count->nb_s < 2) && fl->precision)
		return (0);
	if (ft_atoi(arg) < 0 && (count->nb_s % count->nb_c != 0) && fl->precision)
		return (count->nb_s % count->nb_c);
	if (ft_atoi(arg) < 0 && count->nb_s == (count->nb_c + 1) && fl->precision)
		return (count->nb_s - 1);
	if (ft_atoi(arg) < 0 && count->nb_s > (count->nb_c + 1) && fl->precision)
		return (count->nb_s - 1);
	return (count->nb_s);
}
