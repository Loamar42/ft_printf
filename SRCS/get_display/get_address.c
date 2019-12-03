/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_address.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 19:26:35 by loamar            #+#    #+#             */
/*   Updated: 2019/11/30 19:26:37 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/ft_printf.h"

char		*get_address(long adr)
{
	char	*arg;

	if (adr < 0)
	{
		if (!(arg = ft_ltohex_spe(adr)))
			return (NULL);
	}
	else if (!(arg = ft_ltohex(adr)))
		return (NULL);
	return (arg);
}
