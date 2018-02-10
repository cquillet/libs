/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:53:32 by cquillet          #+#    #+#             */
/*   Updated: 2018/02/10 17:55:48 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	double_nb(double nb, t_format *f)
{
	int		l_float;
	int		int_part;

	if (!(f->s_float = (char *)malloc((f->precision + 1) * sizeof(char))))
		return (0);
	l_float = 0;
	while (l_float < f->precision + 1)
	{
		nb *= 10;
		int_part = (int)nb;
		f->s_float[l_float++] = int_part + '0';
		nb -= int_part;
	}
	return (f->precision);
}

int			get_double(va_list ap, t_format *f)
{
	double		n;
	int			len;
	intmax_t	int_part;
	int			round;

	n = va_arg(ap, double);
	int_part = (intmax_t)n;
	len = double_nb(n - int_part, f);
	if (f->precision > 0 && f->s_float[f->precision] >= '5')
	{
		round = f->precision - 1;
		f->s_float[round]++;
		while (round >= 0 && f->s_float[round] > '9')
		{
			f->s_float[round--] = '0';
			if (round < 0)
				f->round = 1;
			else
				f->s_float[round]++;
		}
	}
	len = signed_nb(int_part + f->round, f);
	len += f->force_period;
	return (len);
}
