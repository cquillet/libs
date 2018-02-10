/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 18:19:30 by cquillet          #+#    #+#             */
/*   Updated: 2018/02/10 17:57:27 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		readstr(char *s, t_format *f)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != '%')
		i++;
	f->nb_printed += i;
	return (write(1, s, i));
}

int		display_arg(va_list ap, t_format *f)
{
	int		len;

	if (f->type == 0)
		return (0);
	len = 0;
	if (type_is_char(f->type))
		len = display_char(ap, f);
	else if (type_is_str(f->type))
		len = display_str(ap, f);
	else if (type_is_int(f->type))
		len = display_integers(ap, f);
	else if (type_is_ptr(f->type))
		len = display_ptr(ap, f);
	else if (type_is_float(f->type))
		len = display_floats(ap, f);
	f->nb_printed += write(1, f->repr, len);
	free_format(f);
	return (len);
}

int		distinguish_format(char **p, t_format *f, va_list ap)
{
	char	*s;

	s = *p;
	if (*s == '\0')
		return (0);
	if (*s == '%')
	{
		*p = read_format(s + 1, f, ap);
		if (!check_fields(f))
			return (-1);
		return (display_arg(ap, f));
	}
	return (0);
}

int		ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			len;
	int			ret_value;
	char		*s;
	t_format	f;

	ret_value = 0;
	va_start(ap, fmt);
	s = (char *)fmt;
	f.nb_printed = 0;
	while (*s != '\0')
	{
		s += (len = readstr(s, &f));
		ret_value += len;
		len = distinguish_format(&s, init_format(&f), ap);
		ret_value += len;
	}
	va_end(ap);
	return (ret_value);
}
