/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_size_t.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 21:42:54 by cquillet          #+#    #+#             */
/*   Updated: 2018/02/10 17:56:37 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_size_t(va_list ap, t_format *f)
{
	size_t		i;
	size_t		u;
	size_t		*n;

	if (f->type == 'i' || f->type == 'd')
	{
		i = va_arg(ap, size_t);
		return (signed_nb((intmax_t)i, f));
	}
	else if (f->type == 'n')
	{
		n = va_arg(ap, size_t *);
		*n = f->nb_printed;
		return ((f->l_int = 0));
	}
	u = va_arg(ap, size_t);
	return (unsigned_nb((uintmax_t)u, f));
}
