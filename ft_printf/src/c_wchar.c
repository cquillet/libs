/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_wchar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 17:03:13 by cquillet          #+#    #+#             */
/*   Updated: 2018/02/10 17:56:48 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_wchar(va_list ap, t_format *f)
{
	wint_t		c;

	c = va_arg(ap, wint_t);
	f->l_int = len_wchar(c);
	if (!(f->s_int = (char *)malloc(f->l_int * sizeof(char))))
		return (0);
	wchar_to_char(f->s_int, c);
	return (f->l_int);
}

int		len_wchar(wint_t c)
{
	int		len;

	if (c < 0x80)
		return (1);
	len = 1;
	while (c >= (0x40 << (5 * len++)))
		;
	return (len);
}

int		wchar_to_char(char *dst, wint_t c)
{
	int		n;
	int		ret;
	char	mask;

	if (c < 0x80)
	{
		dst[0] = (char)c;
		return (1);
	}
	ret = len_wchar(c);
	n = ret;
	mask = 0x80;
	while (--n)
	{
		dst[n] = ((0x3f & c) | 0x80);
		c >>= 6;
		mask = ((mask >> 1) | 0x80);
	}
	dst[0] = mask | c;
	return (ret);
}
