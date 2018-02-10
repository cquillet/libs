/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 15:41:04 by cquillet          #+#    #+#             */
/*   Updated: 2018/02/10 17:57:07 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** For diuoxX conversions
** The default precision is 1. When 0 is printed with an explicit precision 0,
** the output is empty.
**
** If a precision is given with a numeric conversion (d, i, o, u, x, and X),
** the 0 flag is ignored.
*/

int			display_integers(va_list ap, t_format *f)
{
	if (!f->precision_defined)
		f->precision = 1;
	else
		f->pad = ' ';
	if (f->length == NO_LEN)
		get_int(ap, f);
	else if (f->length == LEN_SSHORT)
		get_shortshort(ap, f);
	else if (f->length == LEN_SHORT)
		get_short(ap, f);
	else if (f->length == LEN_LONG)
		get_long(ap, f);
	else if (f->length == LEN_LLONG)
		get_longlong(ap, f);
	else if (f->length == LEN_INTMAX)
		get_intmax(ap, f);
	else if (f->length == LEN_SIZET)
		get_size_t(ap, f);
	else
		get_ptrdiff_t(ap, f);
	if (f->type == 'n')
		return (0);
	return ((f->left) ? complete_nb_left(f) : complete_nb_right(f));
}
