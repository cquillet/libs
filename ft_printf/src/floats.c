/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 16:10:27 by cquillet          #+#    #+#             */
/*   Updated: 2018/02/10 17:56:57 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** flag # for a, A, e, E, f, F, g, and G conversions,
** the result will always contain a decimal point, even if no digits follow it
**
** flag # for g and G conversions,
** trailing zeros are not removed from the result as they would otherwise be
**
** For eEfF conversions
** If the precision is missing, it is taken as 6;
** if the precision is explicitly zero, no decimal-point character appears.
** If a decimal point appears, at least one digit appears before it.
**
** For gG conversion
** The precision specifies the number of significant digits.
** If the precision is missing, 6 digits are given;
** if the precision is zero, it is treated as 1.
*/

int			display_floats(va_list ap, t_format *f)
{
	if (!f->precision_defined)
		f->precision = 6;
	f->force_period = f->sharp;
	if (f->type == 'g' || f->type == 'G')
	{
		f->zero_not_removed = f->sharp;
		if (f->precision == 0)
			f->precision = 1;
	}
	if (f->length == LEN_LDOUBLE)
		get_longdouble(ap, f);
	else
		get_double(ap, f);
	return ((f->left) ? complete_float_left(f) : complete_float_right(f));
}

static int	correct_format_float(t_format *f)
{
	int		len_nb;

	len_nb = f->l_int + f->precision + (f->precision > 0 || f->force_period);
	len_nb += (f->sign > 0);
	if (f->min_field < len_nb)
		f->min_field = len_nb;
	return (f->min_field);
}

int			complete_float_right(t_format *f)
{
	int		i;
	int		j;
	int		len;
	int		len_nb;

	len = correct_format_float(f);
	if (!(f->repr = (char *)malloc(sizeof(char) * len)))
		return (0);
	len_nb = f->l_int + f->precision + (f->precision > 0 || f->force_period);
	len_nb += (f->sign > 0);
	i = 0;
	while (i < len - len_nb)
		f->repr[i++] = f->pad;
	if (f->sign != 0)
		f->repr[i++] = f->sign;
	j = 0;
	while (j < f->l_int)
		f->repr[i++] = f->s_int[j++];
	if (f->precision == 0 && !f->force_period)
		return (len);
	f->repr[i++] = '.';
	j = 0;
	while (j < f->precision)
		f->repr[i++] = f->s_float[j++];
	return (len);
}

int			complete_float_left(t_format *f)
{
	int		i;
	int		j;
	int		len;

	len = correct_format_float(f);
	if (!(f->repr = (char *)malloc(sizeof(char) * len)))
		return (0);
	i = 0;
	if (f->sign != 0)
		f->repr[i++] = f->sign;
	j = 0;
	while (j < f->l_int)
		f->repr[i++] = f->s_int[j++];
	if (f->precision > 0 || f->force_period)
		f->repr[i++] = f->period;
	j = 0;
	while (j < f->precision)
		f->repr[i++] = f->s_float[j++];
	while (i < len)
		f->repr[i++] = f->pad;
	return (len);
}
