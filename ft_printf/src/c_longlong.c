/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longlong.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 15:59:19 by cquillet          #+#    #+#             */
/*   Updated: 2018/02/10 17:56:17 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_longlong(va_list ap, t_format *f)
{
	signed long long	i;
	unsigned long long	u;
	long long int		*n;

	if (f->type == 'i' || f->type == 'd')
	{
		i = va_arg(ap, signed long long);
		return (signed_nb((intmax_t)i, f));
	}
	else if (f->type == 'n')
	{
		n = va_arg(ap, long long int *);
		*n = (long long int)(f->nb_printed);
		return ((f->l_int = 0));
	}
	u = va_arg(ap, unsigned long long);
	return (unsigned_nb((uintmax_t)u, f));
}
