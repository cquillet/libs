/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_intmax.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 21:34:52 by cquillet          #+#    #+#             */
/*   Updated: 2018/02/10 17:55:58 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_intmax(va_list ap, t_format *f)
{
	intmax_t	i;
	uintmax_t	u;
	intmax_t	*n;

	if (f->type == 'i' || f->type == 'd')
	{
		i = va_arg(ap, intmax_t);
		return (signed_nb(i, f));
	}
	else if (f->type == 'n')
	{
		n = va_arg(ap, intmax_t *);
		*n = (intmax_t)(f->nb_printed);
		return ((f->l_int = 0));
	}
	u = va_arg(ap, uintmax_t);
	return (unsigned_nb(u, f));
}
