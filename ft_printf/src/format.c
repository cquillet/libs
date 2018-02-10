/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 21:14:22 by cquillet          #+#    #+#             */
/*   Updated: 2018/02/10 17:57:02 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** A negative field width is taken as a '-' flag followed by a positive
** field width.
**
** If the precision is given as just '.', or the precision is negative,
** the precision is taken to be zero.
**
** If the 0 and - flags both appear, the 0 flag is ignored.
*/

int			check_fields(t_format *f)
{
	if (f->type == 0 || f->min_field == -2147483648)
		return (f->type == 0);
	f->left = (f->min_field < 0) || f->left;
	if (f->min_field < 0)
		f->min_field = -f->min_field;
	if (f->precision < 0)
		f->precision = 0;
	if (f->left)
		f->pad = ' ';
	if (!type_is_nb(f->type))
		f->pad = (type_is_char(f->type) || type_is_str(f->type) ||
										type_is_ptr(f->type)) ? f->pad : ' ';
	if (f->sharp && (f->base == 16 || f->base == 2))
		f->sharp = 2;
	if (f->type == 'u' || f->base != 10)
		f->sign = 0;
	return (1);
}

t_format	*init_format(t_format *f)
{
	f->sharp = 0;
	f->left = 0;
	f->pad = ' ';
	f->sign = 0;
	f->force_period = 0;
	f->base = 10;
	f->prefix_conv = 0;
	f->zero_not_removed = 0;
	f->min_field = 0;
	f->period = '.';
	f->precision_defined = 0;
	f->precision = 0;
	f->length = NO_LEN;
	f->type = 0;
	f->repr = NULL;
	f->s_int = NULL;
	f->s_float = NULL;
	f->l_int = 0;
	f->round = 0;
	return (f);
}

void		free_format(t_format *f)
{
	ft_strdel(&(f->repr));
	ft_strdel(&(f->s_int));
	ft_strdel(&(f->s_float));
}
