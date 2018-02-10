/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 19:26:38 by cquillet          #+#    #+#             */
/*   Updated: 2018/02/10 17:57:41 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		type_exists(char c)
{
	if (!c)
		return (0);
	return (type_is_nb(c) || type_is_char(c) || type_is_str(c) ||
			type_is_ptr(c) || type_includes_long(c));
}

int		type_is_char(char c)
{
	return (c == 'c' || c == 'C' || c == '%');
}

int		type_is_str(char c)
{
	return (c == 's' || c == 'S');
}

int		type_is_ptr(char c)
{
	return (c == 'p');
}

int		type_includes_long(char c)
{
	return (c && ft_strchr("CDOSUB", c));
}
