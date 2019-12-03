/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 15:21:43 by loamar            #+#    #+#             */
/*   Updated: 2019/11/29 15:52:00 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/ft_printf.h"

t_flags		*get_flags3(t_flags *fl, va_list ap, t_printf *v)
{
	int		z;
	int		width;
	char	*arg;

	z = 0;
	width = va_arg(ap, int);
	if (width < 0)
	{
		v->check = 1;
		if (fl->precision)
			v->check += ft_strlen(fl->precision);
		if (fl->width)
			if (ft_strlen(fl->width) > 1)
				v->check += ft_strlen(fl->width);
		if (fl->flag)
			(v->check)++;
		fl = flags_init();
	}
	else
	{
		arg = ft_itoa(width);
		fl->precision = get_precision(arg, &z);
		(v->index)++;
	}
	return (fl);
}

t_flags		*get_flags2(const char *form, t_flags *fl, va_list ap, t_printf *v)
{
	int		z;

	if (form[v->index] == '.' && ft_isdigit(form[++(v->index)]))
		fl->precision = get_precision(form, &(v->index));
	else if (form[v->index - 1] == '.' && form[(v->index)] == '*')
		fl = get_flags3(fl, ap, v);
	else if (form[v->index - 1] == '.' && form[(v->index)] == '-')
	{
		fl->flag = '-';
		if (ft_isdigit(form[(v->index)++]))
			fl->width = get_width(form, &(v->index));
	}
	else if (form[v->index - 1] == '.')
		fl->precision = ft_strdup("0");
	return (fl);
}
