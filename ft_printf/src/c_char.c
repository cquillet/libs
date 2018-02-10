/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_char.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 14:44:47 by cquillet          #+#    #+#             */
/*   Updated: 2018/02/10 17:55:41 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_shortshort(va_list ap, t_format *f)
{
	signed char		i;
	unsigned char	u;
	signed char		*n;

	if (f->type == 'i' || f->type == 'd')
	{
		i = (signed char)va_arg(ap, int);
		return (signed_nb((intmax_t)i, f));
	}
	else if (f->type == 'n')
	{
		n = va_arg(ap, signed char *);
		*n = (signed char)(f->nb_printed);
		return ((f->l_int = 0));
	}
	u = (unsigned char)va_arg(ap, int);
	return (unsigned_nb((uintmax_t)u, f));
}

int		get_char(va_list ap, t_format *f)
{
	char		c;

	c = (char)va_arg(ap, int);
	if (!(f->s_int = (char *)malloc(sizeof(char))))
		return (0);
	f->s_int[0] = c;
	return ((f->l_int = 1));
}

int		get_percent(t_format *f)
{
	f->s_int = ft_strdup("%");
	if (f->s_int == NULL)
		return (0);
	return ((f->l_int = 1));
}
