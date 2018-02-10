/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 15:50:08 by cquillet          #+#    #+#             */
/*   Updated: 2018/02/10 17:56:31 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_short(va_list ap, t_format *f)
{
	signed short	i;
	unsigned short	u;
	short int		*n;

	if (f->type == 'i' || f->type == 'd')
	{
		i = (signed short)va_arg(ap, int);
		return (signed_nb((intmax_t)i, f));
	}
	else if (f->type == 'n')
	{
		n = va_arg(ap, short int *);
		*n = (short int)(f->nb_printed);
		return ((f->l_int = 0));
	}
	u = (unsigned short)va_arg(ap, int);
	return (unsigned_nb((uintmax_t)u, f));
}
