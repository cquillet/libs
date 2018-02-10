/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longdouble.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 17:00:35 by cquillet          #+#    #+#             */
/*   Updated: 2018/02/10 17:56:09 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_longdouble(va_list ap, t_format *f)
{
	int		len;
	int		ret;

	f->s_float = (char *)malloc((f->precision + 1) * sizeof(char));
	len = get_double(ap, f);
	ret = len;
	if (f->left)
		len = complete_float_left(f);
	else
		len = complete_float_right(f);
	while (len--)
		write(1, f->repr--, 1);
	free(f->s_float);
	return (ret);
}
