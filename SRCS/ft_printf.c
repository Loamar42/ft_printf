/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 15:17:46 by loamar            #+#    #+#             */
/*   Updated: 2019/11/29 15:18:06 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

static void	manage_argument(const char *f, t_printf *v, t_flags *fl, va_list ap)
{
	v->check = 0;
	v->index++;
	fl = get_flags(f, ap, v);
	if (v->check > 0)
		v->index += v->check;
	v->type = get_type(f, v->index);
	if (fl != NULL && v->type == '\0')
		v->index++;
	else
	{
		v->arg = get_arg(v->type, ap, &(v->index), fl);
		if (v->check > 0)
		{
			ft_putstr(v->arg);
			v->size += ft_strlen(v->arg);
		}
		else
			ft_display(v->arg, v->type, fl, &(v->size));
		v->index++;
	}
}

int			ft_printf(const char *format, ...)
{
	t_printf	vars;
	t_flags		*flags;
	va_list		ap;

	vars.index = 0;
	vars.size = 0;
	va_start(ap, format);
	while (format[vars.index] != '\0')
	{
		if (format[vars.index] == '%')
			manage_argument(format, &vars, flags, ap);
		else
		{
			write(1, &format[vars.index], 1);
			vars.size++;
			vars.index++;
		}
	}
	va_end(ap);
	return (vars.size);
}
