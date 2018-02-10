/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_nb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 22:24:10 by cquillet          #+#    #+#             */
/*   Updated: 2018/02/10 17:57:46 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		type_is_nb(char c)
{
	return (type_is_int(c) || type_is_float(c));
}

int		type_is_int(char c)
{
	return (c && ft_strchr("diouxXbn", c));
}

int		type_is_float_dec(char c)
{
	return (c && ft_strchr("fFeEgG", c));
}

int		type_is_float(char c)
{
	return (type_is_float_dec(c) || c == 'a' || c == 'A');
}
