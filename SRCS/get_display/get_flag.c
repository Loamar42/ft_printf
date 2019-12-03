/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 15:20:07 by loamar            #+#    #+#             */
/*   Updated: 2019/11/29 15:20:46 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/ft_printf.h"

/*
** get_flag permet de récupérer le flag 0 ou -
** elle renvoie un '\0'dans le cas où il n'y a pas de flag 0 ou -
*/

static char	get_flag(const char *format, int *index)
{
	char	flag;

	if (format[*index] == '0')
	{
		flag = flag_loop(format, '0', index);
		return (flag);
	}
	else if (format[*index] == '-')
	{
		flag = flag_loop(format, '-', index);
		return (flag);
	}
	return ('\0');
}

/*
** get_width permet de récupérer le flag width dans la chaine format
*/

char		*get_width(const char *format, int *index)
{
	char	*width;
	int		size;
	int		i;

	i = *index;
	size = 0;
	while (ft_isdigit(format[i++]))
		size++;
	if (!(width = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (ft_isdigit(format[*index]))
		width[i++] = format[(*index)++];
	width[i] = '\0';
	return (width);
}

/*
** get_precision permet de récupérer le flag précision dans la chaine format
*/

char		*get_precision(const char *format, int *index)
{
	char	*precision;
	int		size;
	int		i;

	i = *index;
	size = 0;
	while (ft_isdigit(format[i++]))
		size++;
	if (!(precision = (char *)malloc((sizeof(char) * (size + 1)))))
		return (NULL);
	i = 0;
	while (ft_isdigit(format[*index]))
		precision[i++] = format[(*index)++];
	precision[i] = '\0';
	return (precision);
}

/*
** get flags permet de récupérer tous les flags suivants:
** -flag (0 ou -)
** -width (number ou *)
** -precision (.number ou .*)
*/

t_flags		*get_flags(const char *format, va_list ap, t_printf *v)
{
	t_flags	*flags;
	int		z;

	flags = flags_init();
	if (format[v->index] == '0' || format[v->index] == '-')
		flags->flag = get_flag(format, &(v->index));
	if (ft_isdigit(format[v->index]))
		flags->width = get_width(format, &(v->index));
	if (format[v->index] == '*')
	{
		z = 0;
		flags->width = get_width(get_stars(ap, flags), &z);
		(v->index)++;
	}
	flags = get_flags2(format, flags, ap, v);
	return (flags);
}
