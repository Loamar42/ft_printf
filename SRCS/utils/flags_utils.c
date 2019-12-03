/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:02:56 by loamar            #+#    #+#             */
/*   Updated: 2019/11/29 16:03:06 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/ft_printf.h"

t_flags	*flags_init(void)
{
	t_flags *flags;

	if (!(flags = (t_flags*)malloc(sizeof(t_flags))))
		return (NULL);
	flags->flag = '\0';
	flags->width = NULL;
	flags->precision = NULL;
	return (flags);
}

void	free_flags(t_flags *flags)
{
	flags->flag = '\0';
	free(flags->width);
	free(flags->precision);
	free(flags);
}

int		ft_isflag(t_flags *flags, char c)
{
	int i;

	if (c == flags->flag)
		return (1);
	else
	{
		i = 0;
		while (flags->width[i] != '\0')
		{
			if (flags->width[i] == c)
				return (1);
			i++;
		}
		i = 0;
		while (flags->precision[i] != '\0')
		{
			if (flags->precision[i] == c)
				return (1);
			i++;
		}
	}
	return (0);
}

/*
** get_stars permet de gerer le *
** en renvoyant l'arg sous forme de string car arg est un char *
*/

char	*get_stars(va_list ap, t_flags *flags)
{
	char	*arg;
	int		width;

	width = va_arg(ap, int);
	if (width < 0)
	{
		flags->flag = '-';
		width = -width;
	}
	arg = ft_itoa(width);
	return (arg);
}

/*
** Flag loop permet de gerer le cas d'erreur avec
** plusieur 0 et plusieur moin , sachant que le
** moin domine sur le zero
*/

char	flag_loop(const char *format, char flag, int *index)
{
	char final_flag;

	final_flag = flag;
	(*index)++;
	while (format[*index] == '0' || format[*index] == '-')
	{
		if (format[*index] == '-')
			final_flag = '-';
		(*index)++;
	}
	return (final_flag);
}
