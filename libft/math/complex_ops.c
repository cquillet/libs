/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 19:33:47 by cquillet          #+#    #+#             */
/*   Updated: 2018/02/10 16:54:36 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex.h"
#include "libft.h"

t_re			cplx_mod2(t_cplx z)
{
	return ((z.re * z.re) + (z.im * z.im));
}

t_2f			cplx_2f(t_cplx z)
{
	return (create_2f(z.re, z.im));
}

int				cplx_cmp(t_cplx x, t_cplx y)
{
	return (!(barely_equals(x.re, y.re) && barely_equals(x.im, y.im)));
}

void			cplx_print(t_cplx z, int precision)
{
	if (sizeof(t_re) == sizeof(double))
		ft_printf("%.*f %+.*fi\n", precision, z.re, precision, z.im);
	else if (sizeof(t_re) == sizeof(long double))
		ft_printf("%.*Lf %+.*Lfi\n", precision, z.re, precision, z.im);
}
