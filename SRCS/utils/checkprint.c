/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 15:54:38 by loamar            #+#    #+#             */
/*   Updated: 2019/11/29 16:02:42 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/ft_printf.h"

static int	ft_isinteger(char type)
{
	if (type == 'i' || type == 'd' || type == 'x' || type == 'X')
		return (1);
	return (0);
}

int			print_n_ox(char *arg, char type, t_flags *flags)
{
	if (ft_isinteger(type) == 1 && arg[0] == '-')
	{
		ft_putchar('-');
		return (1);
	}
	else if (type == 'p')
	{
		ft_putstr("0x");
		return (2);
	}
	return (0);
}

int			check_type_ex(char c)
{
	if (c == 'd' || c == 'i' || c == 'u')
		return (1);
	if (c == 'x' || c == 'X')
		return (1);
	return (0);
}
