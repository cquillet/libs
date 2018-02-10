/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 20:53:07 by cquillet          #+#    #+#             */
/*   Updated: 2018/02/10 17:57:32 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** A - overrides a 0 if both are given.
** A + overrides a space if both are used.
*/

static int	read_flags(char *s, t_format *f, int len)
{
	if (*s == '\0')
		return (len);
	if (*s == '#')
		f->sharp = 1;
	else if (*s == '-')
		f->left = 1;
	else if (*s == '+' || (*s == ' ' && f->sign != '+'))
		f->sign = *s;
	else if (*s == '0' && !f->left)
		f->pad = '0';
	if (ft_strchr("#-+ 0'I", *s))
		return (read_flags(s + 1, f, len + 1));
	return (len);
}

static int	read_field(char *s, t_format *f, int field, va_list ap)
{
	int		len;
	long	n;
	int		sign;

	if (*s == '*' && field == WIDTH_FIELD)
		f->min_field = va_arg(ap, int);
	else if (*s == '*' && field == PRECISION_FIELD)
		f->precision = va_arg(ap, int);
	if (*s == '*')
		return (1 + read_field(s + 1, f, field, ap));
	sign = (*s == '-');
	len = (*s == '-' || *s == '+');
	if (s[len] < '0' || s[len] > '9')
		return (len);
	n = 0;
	while ('0' <= s[len] && s[len] <= '9')
		n = n * 10 + (s[len++] - '0');
	if (field == WIDTH_FIELD)
		f->min_field = n;
	else if (field == PRECISION_FIELD)
		f->precision = sign ? 0 : n;
	return (len + read_field(s + len, f, field, ap));
}

static int	read_length(char *s, t_format *f, char prec)
{
	if (*s == '\0')
		return (0);
	if (*s == 'j')
		f->length = LEN_INTMAX;
	else if (*s == 'z')
		f->length = LEN_SIZET;
	else if (*s == 't')
		f->length = LEN_PTRDIFF;
	else if (*s == 'L')
		f->length = LEN_LDOUBLE;
	else if (f->length < LEN_LLONG && *s == 'l' && *s == prec)
		f->length = LEN_LLONG;
	else if (f->length < LEN_LONG && *s == 'l')
		f->length = LEN_LONG;
	else if (f->length < LEN_SHORT && *s == 'h' && s[0] != s[1] && *s != prec)
		f->length = LEN_SHORT;
	else if (f->length < LEN_SSHORT && *s == 'h')
		f->length = LEN_SSHORT;
	else if (*s != 'l' && *s != 'h')
		return (0);
	return (1 + read_length(s + 1, f, s[0]));
}

static int	read_type(char *s, t_format *f)
{
	if (type_exists(*s))
		f->type = *s;
	else
		return ((f->l_int = 0));
	if (type_includes_long(*s))
	{
		f->type = ft_tolower(*s);
		f->length = (f->length == LEN_LONG) ? LEN_LLONG : LEN_LONG;
	}
	if (f->type == 'x' || f->type == 'X' || f->type == 'p')
		f->base = 16;
	else if (f->type == 'o')
		f->base = 8;
	else if (f->type == 'b')
		f->base = 2;
	return (1);
}

char		*read_format(char *s, t_format *f, va_list ap)
{
	s += read_flags(s, f, 0);
	s += read_field(s, f, WIDTH_FIELD, ap);
	if (*s == '.')
	{
		s += (f->precision_defined = 1);
		s += read_field(s, f, PRECISION_FIELD, ap);
	}
	s += read_length(s, f, 0);
	s += read_type(s, f);
	return (s);
}
