/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_int.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 14:45:07 by cquillet          #+#    #+#             */
/*   Updated: 2018/02/10 17:55:52 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_int(va_list ap, t_format *f)
{
	signed int		i;
	unsigned int	u;
	int				*n;

	if (f->type == 'i' || f->type == 'd')
	{
		i = va_arg(ap, signed int);
		return (signed_nb((intmax_t)i, f));
	}
	else if (f->type == 'n')
	{
		n = va_arg(ap, int *);
		*n = (int)(f->nb_printed);
		return ((f->l_int = 0));
	}
	u = va_arg(ap, unsigned int);
	return (unsigned_nb((uintmax_t)u, f));
}

/*
** The number of characters written so far is stored into the integer
** indicated by the int * (or variant) pointer argument.
** No argument is converted.
*/

int		get_ptrdiff_t(va_list ap, t_format *f)
{
	ptrdiff_t	p;
	ptrdiff_t	*n;

	if (f->type != 'n')
	{
		p = va_arg(ap, ptrdiff_t);
		return (unsigned_nb((unsigned long long)p, f));
	}
	else
	{
		n = va_arg(ap, ptrdiff_t *);
		*n = f->nb_printed;
	}
	return (0);
}
