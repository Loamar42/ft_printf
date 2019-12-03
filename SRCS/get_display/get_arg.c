/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 15:19:18 by loamar            #+#    #+#             */
/*   Updated: 2019/12/01 15:34:38 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/ft_printf.h"

/*
** get arg permet de stocker dans arg l'argument voulu
** sous forme de chaine de caractere
** en fonction du type
** puis incrémente l'index
*/

static char	*ft_chartostr(char c)
{
	char	*arg;

	arg = (char *)malloc(2 * sizeof(char));
	arg[0] = c;
	arg[1] = '\0';
	return (arg);
}

static char	*get_arghex(char type, va_list ap, t_flags *fl, char *arg)
{
	arg = ft_stohex(ft_itoa(va_arg(ap, int)));
	arg = (type == 'X') ? ft_strtoupper(arg) : arg;
	return (arg);
}

static char	*get_argstring(char type, va_list ap, t_flags *fl, char *arg)
{
	if (fl->precision && ft_atoi(fl->precision) == 0)
		arg = ft_strdup("");
	else
	{
		arg = va_arg(ap, char *);
		if (arg == NULL)
			arg = ft_strdup("(null)");
	}
	return (arg);
}

char		*get_arg(char type, va_list ap, int *index, t_flags *fl)
{
	char	*arg;
	char	c;

	if (type == 'd' || type == 'i')
		arg = ft_itoa(va_arg(ap, int));
	else if (type == 's')
	{
		arg = get_argstring(type, ap, fl, arg);
	}
	else if (type == 'c' || type == '%')
	{
		c = (type == '%') ? '%' : va_arg(ap, int);
		arg = ft_chartostr(c);
	}
	else if (type == 'X' || type == 'x')
		arg = get_arghex(type, ap, fl, arg);
	else if (type == 'p')
		arg = get_address((long)va_arg(ap, void *));
	else if (type == 'u')
		arg = ft_itoa(ft_unsigned(va_arg(ap, int)));
	else
		(*index)++;
	return (arg);
}
