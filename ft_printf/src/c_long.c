/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 15:59:10 by cquillet          #+#    #+#             */
/*   Updated: 2018/02/10 17:56:04 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_long(va_list ap, t_format *f)
{
	signed long		i;
	unsigned long	u;
	long int		*n;

	if (f->type == 'i' || f->type == 'd')
	{
		i = va_arg(ap, signed long);
		return (signed_nb((intmax_t)i, f));
	}
	else if (f->type == 'n')
	{
		n = va_arg(ap, long int *);
		*n = (long int)(f->nb_printed);
		return ((f->l_int = 0));
	}
	u = va_arg(ap, unsigned long);
	return (unsigned_nb((uintmax_t)u, f));
}
