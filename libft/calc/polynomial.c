/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polynomal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 18:42:03 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/26 23:43:22 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "polynomial.h"
#include "printf.h"
#include "complex.h"
#include "libft.h"
#include <stdlib.h>

#include <stdio.h>
t_poly			init_poly(unsigned int deg)
{
	t_poly	p;

	p.deg = 0xffffffff;
	p.coeff = (t_cplx *)malloc((deg + 1) * sizeof(t_cplx));
	p.unset = create_tab_bin(deg + 1);
	if (!p.coeff || !p.unset)
		return (p);
	if (!deg)
	{
		let_bin(p.unset, 0, 0);
		p.coeff[0] = create_complex(0., 0.);
		p.deg = 0;
		return (p);
	}
	while (++p.deg < deg)
		let_bin(p.unset, p.deg, 1);
	let_bin(p.unset, p.deg, 0);
	p.coeff[p.deg] = create_complex(1., 0.);
	return (p);
}

/*
** return :	-1	error
**			0	P[n] = coeff (P[n] has been set fort the 1st time)
**			1	P[n] = coeff (P[n] has been changed/updated)
*/

int					poly_fill_nth_deg(t_poly *p, unsigned int n, t_cplx coeff)
{
	if (n > p->deg || !(p->coeff))
		return (-1);
	if (get_bin(p->unset, n))
	{
		p->coeff[n] = coeff;
		return (let_bin(p->unset, n, 0));
	}
	p->coeff[n] = coeff;
	p->deg = poly_test_deg(*p);
	return (1);
}

t_poly				poly_derivative(t_poly p)
{
	t_poly	d;

//	printf("DERIV DEB = %u\n", p.deg);
//	poly_print(p);
	p.deg = poly_test_deg(p);
	if (!p.deg || !p.coeff || !p.unset)
		return (init_poly(0));
	d = init_poly(p.deg - 1);
	while (p.deg)
	{
		if (!poly_is_coeff_zero(p, p.deg))
			poly_fill_nth_deg(&d, p.deg - 1,
								cplx_scalar(p.coeff[p.deg], (t_re)(p.deg)));
		p.deg--;
//		printf("DERIV WHILE = %u\n", p.deg);
//		poly_print(d);
		p.deg = poly_test_deg(p);
	}
//	printf("DERIV FIN = %u\n", p.deg);
//	poly_print(d);
	return (d);
}

t_cplx				poly_calc(t_poly p, t_cplx x)
{
	unsigned int	n;
	t_cplx			x_power_n;
	t_cplx			result;

	result = create_complex(0., 0.);
	if (!p.coeff || !p.unset)
		return (result);
	if (!poly_is_coeff_zero(p, 0))
		result = p.coeff[0];
	if (!p.deg)
		return (result);
	n = 1;
	x_power_n = x;
	while (n <= p.deg)
	{
		if (!poly_is_coeff_zero(p, n))
			result = cplx_add(result, cplx_mul(p.coeff[n], x_power_n));
		if (n++ < p.deg)
			x_power_n = cplx_mul(x_power_n, x);
	}
	return (result);
}

int				poly_print(t_poly p)
{
	int				n;

//printf("PRINT p.deg = %u, coeff=%p, unset=%p\n", p.deg, p.coeff, p.unset);
	if (!(p.deg = poly_test_deg(p)))
	{
//	printf("p.deg0 = %u\n", p.deg);
		if (p.coeff && p.unset && !get_bin(p.unset, 0))
			printf("%Lf + %+Lfi\n", p.coeff[0].re, p.coeff[0].im);
		return (1);
	}
//	printf("p.deg = %u non nul\n", p.deg);
	n = 0;
	while (p.deg)
	{
		if (n > 0)
			printf(" + \n");
		printf("%Lf %+Lfi X", p.coeff[p.deg].re, p.coeff[p.deg].im);
		if (p.deg > 1)
			printf("%u", p.deg);
		n++;
		p.deg--;
		p.deg = poly_test_deg(p);
	}
	if (!poly_is_coeff_zero(p, 0))
		printf(" + \n%Lf %+Lfi", p.coeff[p.deg].re, p.coeff[p.deg].im);
	printf("\n\n");
	return (n);
}

t_poly				poly_deg0_real(t_re real)
{
	t_poly	p;

	p = init_poly(0);
	poly_fill_nth_deg(&p, 0, create_complex(real, 0.));
	return (p);
}

t_poly				poly_deg2_real(t_re a, t_re b, t_re c)
{
	t_poly	p;

	p = init_poly(2);
	poly_fill_nth_deg(&p, 0, create_complex(c, 0.));
	poly_fill_nth_deg(&p, 1, create_complex(b, 0.));
	poly_fill_nth_deg(&p, 2, create_complex(a, 0.));
	p.deg = poly_test_deg(p);
	return (p);
}

unsigned int		poly_test_deg(t_poly p)
{
//	printf("\nPOLY TEST DEG %u\n", p.deg);
	if (!p.deg || !p.coeff || !p.unset)
		return (0);
	while (p.deg)
	{
//		printf("POLY TEST DEG NON NUL %u\n", p.deg);
		if (!poly_is_coeff_zero(p, p.deg))
			break;
		p.deg--;
	}
//	printf("POLY TEST DEG FIN %u\n", p.deg);
	return (p.deg);
}

int					poly_is_coeff_zero(t_poly p, unsigned int n)
{
	if (n > p.deg || !p.unset || !p.coeff)
		return (1);
	if (get_bin(p.unset, n))
		return (1);
	return (!cplx_cmp(p.coeff[n], create_complex(0., 0.)));
}

void				poly_del(t_poly *p)
{
	p->deg = 0;
	ft_memdel((void **)&(p->coeff));
	ft_memdel((void **)&(p->unset));
}

int					poly_cmp(t_poly p, t_poly q)
{
	p.deg = poly_test_deg(p);
	q.deg = poly_test_deg(q);
	while (p.deg && q.deg && p.deg == q.deg)
	{
		if (cplx_cmp(p.coeff[p.deg], q.coeff[q.deg]))
			return (1);
		p.deg = poly_test_deg(p);
		q.deg = poly_test_deg(q);
	}
	return (!p.deg && !q.deg && !cplx_cmp(p.coeff[0], q.coeff[0]));
}

int					poly_is_null(t_poly p)
{
	return (p.deg == 0 && poly_is_coeff_zero(p, 0));
}

t_poly				poly_add(t_poly p, t_poly q)
{
	t_poly			s;
	unsigned int	d;

	s = init_poly(d = (p.deg > q.deg ? p.deg : q.deg));
	while (d)
	{
		if (poly_is_coeff_zero(p, d) && poly_is_coeff_zero(q, d))
			;
		else if (poly_is_coeff_zero(p, d))
			poly_fill_nth_deg(&s, d, q.coeff[d]);
		else if (poly_is_coeff_zero(q, d))
			poly_fill_nth_deg(&s, d, p.coeff[d]);
		else
			poly_fill_nth_deg(&s, d, cplx_add(p.coeff[d], q.coeff[d]));
		d--;
	}
	if (poly_is_coeff_zero(p, 0) && poly_is_coeff_zero(q, 0))
		return (s);
	if (poly_is_coeff_zero(p, 0))
		poly_fill_nth_deg(&s, 0, q.coeff[0]);
	else if (poly_is_coeff_zero(q, 0))
		poly_fill_nth_deg(&s, 0, p.coeff[0]);
	else
		poly_fill_nth_deg(&s, 0, cplx_add(p.coeff[0], q.coeff[0]));
	return (s);
}

t_poly				poly_scalar(t_poly p, t_re a)
{
	t_poly		q;

	if (barely_zero(a))
		return (init_poly(0));
	p.deg = poly_test_deg(p);
	q = init_poly(p.deg);
	while (p.deg)
	{
		q.coeff[p.deg] = cplx_scalar(p.coeff[p.deg], a);
		p.deg--;
		p.deg = poly_test_deg(p);
	}
	if (!poly_is_coeff_zero(p, 0))
		q.coeff[0] = cplx_scalar(p.coeff[0], a);
	return (q);
}
