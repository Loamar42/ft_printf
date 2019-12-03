/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 12:02:29 by loamar            #+#    #+#             */
/*   Updated: 2019/11/29 15:17:30 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

void		ft_display3(char *arg, char type, t_flags *fl, t_count *count)
{
	if (count->nb_c == 0)
		print_space(count->nb_s);
	else if (fl->flag == '0' && fl->precision)
	{
		print_space(count->nb_s);
		count->check = print_n_ox(arg, type, fl);
	}
	else if (count->nb_s > 0)
	{
		count->check = print_n_ox(arg, type, fl);
		ft_put_space_zero(arg, type, fl, count->nb_s);
	}
}

t_count		*init_count(void)
{
	t_count *count;

	if (!(count = (t_count*)malloc(sizeof(t_count))))
		return (NULL);
	count->nb_c = 0;
	count->nb_s = 0;
	count->check = 0;
	return (count);
}

int			check_basexlower(char *arg)
{
	if (ft_atoi_base(arg, "0123456789abcdef") == 0)
		return (1);
	else
		return (0);
}

int			check_basexupper(char *arg)
{
	if (ft_atoi_base(arg, "0123456789ABCDEF") == 0)
		return (1);
	else
		return (0);
}
