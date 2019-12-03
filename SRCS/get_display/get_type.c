/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 15:20:56 by loamar            #+#    #+#             */
/*   Updated: 2019/11/29 15:21:13 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/ft_printf.h"

/*
** ft_istype permet de verifier si le caractere envoyé en paramètre est un
** type valide ou pas
*/

static int	ft_istype(char c)
{
	if (c == 'd' || c == 'i' || c == 'u')
		return (1);
	if (c == 's' || c == 'c' || c == 'p')
		return (1);
	if (c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

/*
** get_type permet de récupérer le type de l'argument à afficher.
** Si le type n'est pas valide, on renvoie un \0
*/

char		get_type(const char *format, int index)
{
	char	type;

	type = '\0';
	if (format[index] != '\0' && (ft_istype(format[index]) == 1))
		type = format[index];
	else
		type = '\0';
	return (type);
}
