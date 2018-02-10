/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 15:34:09 by cquillet          #+#    #+#             */
/*   Updated: 2018/02/10 17:57:13 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			signed_nb(intmax_t n, t_format *f)
{
	if (n < 0)
	{
		f->sign = '-';
		n = ~(n - 1);
	}
	return (unsigned_nb((uintmax_t)n, f));
}

int			unsigned_nb(uintmax_t n, t_format *f)
{
	int			len;
	uintmax_t	c;
	char		b[17];

	if (n == 0 && f->precision_defined && f->precision == 0)
		return ((f->l_int = 0));
	if (n == 0 && f->type != 'p' && f->base != 8)
		f->sharp = 0;
	ft_strcpy(b, (f->type == 'X') ? "0123456789ABCDEF" : "0123456789abcdef");
	c = n;
	while (c >= (unsigned int)f->base)
	{
		f->l_int++;
		c /= f->base;
	}
	len = (++f->l_int);
	if (!(f->s_int = (char *)malloc(f->l_int * sizeof(char))))
		return (0);
	while (len--)
	{
		f->s_int[len] = b[n % f->base];
		n /= f->base;
	}
	return (f->l_int);
}

/*
** diouxX
** When 0 is printed with an explicit precision 0, the output is empty.
**
** '#' (sharp)
** For c, d, i, n, p, s, and u conversions, this option has no effect
** For o conversions, the precision of the number is increased to force the
** first character of the output string to a zero.
** For x and X conversions, a non-zero result has the string `0x'
** (or `0X' for X conversions) prepended to it.
** For a, A, e, E, f, F, g, and G conversions, the result will always
** contain a decimal point, even if no digits follow it (normally, a decimal
** point appears in the results of those conversions only if a digit follows).
** For g and G conversions, trailing zeros are not removed from the result
** as they would otherwise be.
*/

static int	correct_format(t_format *f)
{
	if (f->sharp == 2 && f->l_int == 0 && f->type != 'p')
		f->sharp = 0;
	if (f->base == 8 && f->sharp)
		f->sharp = (f->l_int == 0 ||
							(f->s_int[0] != '0' && f->precision <= f->l_int));
	if (f->precision < f->l_int)
		f->precision = f->l_int;
	if (f->min_field < f->precision + (f->sign != 0) + f->sharp)
		f->min_field = f->precision + (f->sign != 0) + f->sharp;
	if (f->pad == '0')
		f->precision = f->min_field - (f->sign != 0) - f->sharp;
	if (f->type == 'p')
		f->type = 'x';
	return (f->min_field);
}

int			complete_nb_right(t_format *f)
{
	int		i;
	int		j;
	int		len;

	len = correct_format(f);
	if (!(f->repr = (char *)malloc(sizeof(char) * len)))
		return (0);
	i = 0;
	while (i < len - (f->precision + (f->sign != 0) + f->sharp))
		f->repr[i++] = f->pad;
	if (f->sign != 0)
		f->repr[i++] = f->sign;
	if (f->sharp)
		f->repr[i++] = '0';
	if (f->sharp && (f->base == 16 || f->base == 2))
		f->repr[i++] = f->type;
	while (i < (len - f->l_int))
		f->repr[i++] = '0';
	j = 0;
	while (i < len)
		f->repr[i++] = f->s_int[j++];
	return (len);
}

int			complete_nb_left(t_format *f)
{
	int		i;
	int		j;
	int		len;

	len = correct_format(f);
	if (!(f->repr = (char *)malloc(sizeof(char) * len)))
		return (0);
	i = 0;
	if (f->sign != 0)
		f->repr[i++] = f->sign;
	if (f->sharp)
		f->repr[i++] = '0';
	if (f->sharp && (f->base == 16 || f->base == 2))
		f->repr[i++] = f->type;
	while (i < f->precision - f->l_int + (f->sign != 0) + f->sharp)
		f->repr[i++] = '0';
	j = 0;
	while (j < f->l_int)
		f->repr[i++] = f->s_int[j++];
	while (i < len)
		f->repr[i++] = f->pad;
	return (len);
}
