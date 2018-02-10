/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_str.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 16:07:58 by cquillet          #+#    #+#             */
/*   Updated: 2018/02/10 17:56:42 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	let_str_null(t_format *f)
{
	f->s_int = ft_strdup("(null)");
	return ((f->l_int = 6));
}

int			get_string(va_list ap, t_format *f)
{
	char	*s;

	s = va_arg(ap, char *);
	if (s == NULL)
		return (let_str_null(f));
	f->l_int = ft_strlen(s);
	f->s_int = ft_strcpy(ft_strnew(f->l_int), s);
	return (f->l_int);
}

/*
** If a precision is specified, no more bytes than the number specified
** are written, but no partial multibyte characters are written.
*/

int			get_wstring(va_list ap, t_format *f)
{
	wchar_t		*s;
	int			len;
	int			len_char;
	int			i;

	s = va_arg(ap, wchar_t *);
	if (s == NULL)
		return (let_str_null(f));
	len = 0;
	while (s[len] != 0)
	{
		len_char = len_wchar(s[len]);
		if ((f->l_int + len_char > f->precision) && f->precision_defined)
			break ;
		f->l_int += len_char;
		len++;
	}
	if (!(f->s_int = (char *)malloc(f->l_int * sizeof(char))))
		return (0);
	i = 0;
	while (len--)
		i += wchar_to_char(f->s_int + i, *s++);
	return (f->l_int);
}
