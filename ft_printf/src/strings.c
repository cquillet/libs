/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 16:06:33 by cquillet          #+#    #+#             */
/*   Updated: 2018/02/10 17:57:37 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			display_str(va_list ap, t_format *f)
{
	if (f->length == LEN_LONG)
		get_wstring(ap, f);
	else
		get_string(ap, f);
	return ((f->left) ? complete_str_left(f) : complete_str_right(f));
}

/*
** if a precision is specified, no more than the number specified are written.
*/

static int	correct_format_str(t_format *f)
{
	if (f->precision_defined && f->precision < f->l_int)
		f->l_int = f->precision;
	if (f->min_field < f->l_int)
		f->min_field = f->l_int;
	return (f->min_field);
}

int			complete_str_right(t_format *f)
{
	int		i;
	int		j;
	int		len;

	len = correct_format_str(f);
	if (!(f->repr = (char *)malloc(sizeof(char) * len)))
		return (0);
	i = 0;
	while (i < len - f->l_int)
		f->repr[i++] = f->pad;
	j = 0;
	while (i < len)
		f->repr[i++] = f->s_int[j++];
	return (len);
}

int			complete_str_left(t_format *f)
{
	int		i;
	int		len;

	len = correct_format_str(f);
	if (!(f->repr = (char *)malloc(sizeof(char) * len)))
		return (0);
	i = 0;
	while (i < f->l_int)
	{
		f->repr[i] = f->s_int[i];
		i++;
	}
	while (i < len)
		f->repr[i++] = f->pad;
	return (len);
}
