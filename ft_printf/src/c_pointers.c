/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 16:10:33 by cquillet          #+#    #+#             */
/*   Updated: 2018/02/10 17:56:21 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_ptr(va_list ap, t_format *f)
{
	void		*p;
	uintmax_t	u;

	p = va_arg(ap, void *);
	u = (uintmax_t)p;
	f->sharp = 2;
	return (unsigned_nb(u, f));
}
