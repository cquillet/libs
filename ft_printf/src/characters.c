/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   characters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 18:26:31 by cquillet          #+#    #+#             */
/*   Updated: 2018/02/10 17:56:53 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		display_char(va_list ap, t_format *f)
{
	f->sign = 0;
	f->precision = 1;
	f->sharp = 0;
	if (f->type == '%')
		get_percent(f);
	if (f->type == 'c')
	{
		if (f->length == LEN_LONG)
			get_wchar(ap, f);
		else
			get_char(ap, f);
	}
	return ((f->left) ? complete_nb_left(f) : complete_nb_right(f));
}
