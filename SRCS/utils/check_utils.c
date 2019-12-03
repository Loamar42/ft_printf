/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 15:53:13 by loamar            #+#    #+#             */
/*   Updated: 2019/11/29 15:53:29 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/ft_printf.h"

int		check_type_i(char c)
{
	if (c == 'd' || c == 'i')
		return (1);
	return (0);
}

int		check_type_num(char c)
{
	if (c == 'd' || c == 'i' || c == 'u')
		return (1);
	return (0);
}

int		num_noradd(char *arg, t_flags *flags, char type, t_count *count)
{
	int	precision;
	int	i;
	int	ret;

	i = 0;
	precision = ft_atoi(flags->precision);
	if (count->check == 1)
	{
		i = 1;
		precision += 1;
		ret = 1;
	}
	else if (count->check == 2)
	{
		i = 2;
		precision += 2;
		ret = 2;
	}
	if (precision > ft_strlen(arg))
		ft_putzero(precision - ft_strlen(arg));
	while (arg[i])
		ft_putchar(arg[i++]);
	return (ret);
}

void	num_else(char *arg, t_flags *flags, char type)
{
	int	precision;

	precision = ft_atoi(flags->precision);
	if (precision > ft_strlen(arg))
		ft_putzero(precision - ft_strlen(arg));
	ft_putstr(arg);
}

int		check_addr(char type, int check)
{
	if (type == 'p')
		return (0);
	return (check);
}
