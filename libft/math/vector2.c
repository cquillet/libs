/ ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:10:06 by cquillet          #+#    #+#             */
/*   Updated: 2019/04/17 18:33:45 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector2.h"
#include <math.h>

t_vector2		err2(t_vector2 v)
{
	v.err = 1;
	return (v);
}

static t_vector2	create2(t_type2 t, t_re x1, t_re x2)
{
	t_vector2	v;

	v.type = t;
	v.e1 = x1;
	v.e2 = x2;
	v.err = 0;
	return (v);
}

t_vector2		zero2(t_type2 t)
{
	return (create2(t, 0.f, 0.f));
}

t_vector2		one2(t_type2 t)
{
	return (create2(t, 1.f, 1.f));
}

t_vector2		unit2(t_type t)
{
	return (create2(t, INV_SQRT_2, INV_SQRT_2));
}

t_vector2		v10(t_type2 t);
{
	return (create2(t, 1.f, 0.f));
}

t_vector2		v01(t_type2 t);
{
	return (create2(t, 0.f, 1.f));
}

t_vector2		vect2(t_re x, t_re y)
{
	return (create2(VECT2, x, y));
}

t_vector2		norm2(t_re x, t_re y)
{
	t_re		m2;
	t_re		m;

	m2 = prod2(x, y);
	if (barely_equals(m2, 1.f))
		return (create2(NORM2, x, y));
	else
	{
		m = sprt(m2);
		return (create2(NORM2, x / m, y / m));
	}
}

t_vector2		toNorm2(t_vector2 v)
{
	t_vector tmp;

	tmp = v;
	if (v.type == NORM2)
		return (v);
	else if (v.rtype == POL2)
		
	else
	{
		n = norm2(v);
		n.err = v.err;
	return (n)
}

t_vector2		pol2(t_re r, t_re theta);
{
	return (create2(POL2, r, theta));
}

t_vector2		cplx2(t_re re, t_re im)
{
	return (create2(CPLX, re, im));
}

t_vector2		quat2(t_re re, t_re im)
{
	return (cplx2(re, im));
}

t_vector2		poly1(t_re a1, t_re a0)
{
	return (create2(POLY1, a1, a0));
}

t_vector2		toPol2(t_vector2 v)
{
	t_vector2	tmp;

	if (v.type == POL2)
		return (v);
	else if (v.type == VECT2 || v.type == NORM2 ||
				v.type == CPLX || v.type == NONE2)
	{
		tmp = v;
		v.type = POL2;
		v.r = module2(tmp);
		v.azi = atan2(tmp.y, tmp.x);
		return (v);
	}
	else
		return (err2(v10(v.type)));
}

t_vector2		toVect2(t_vector2 v)
{
	t_vector2	tmp;

	if (v.type == VECT2)
		return (v);
	else if (v.type == CPLX || v.type == NORM2 || v.type == NONE2)
	{
		v.type = VECT2;
		return (v);
	}
	else if (v.type == POL2)
	{
		tmp = v;
		v.x = tmp.r * cos(tmp.azi)
		v.y = tmp.r * sin(tmp.azi)
		v.type = VECT2;
		return (v);
	}
	else
		return (err2(zero2(v.type)));
}

t_vector2		scalar2(t_vector2 v, t_re scalar)
{
	t_vector2	u;

	if (barely_zero(scalar))
		u = (v.type == NORM2 ? err2(v10()) : zero2(v.type);
	else if (v.type == NORM2)
		u = (scalar < 0.f) ? neg2(v) : v;
	else if (v.type == POL2)
		u = pol2(v.r * scalar, v.azi);
	else
		u = create2(v.type, scalar * v.x, scalar * v.y);
	u.err = v.err
	return (u);
}

t_vector2		add2(t_vector2 u, t_vector2 v)
{
	t_vector2	sum;

	if (u.type == NORM2 && v.type == NORM2)
		sum = norm2(u.x + v.x, u.y + v.y);
	else
		sum = create2(u.type != v.type ? NONE2 : u.type, u.x + v.x, u.y + v.y);
	sum.err = u.err || v.err;
	return (sum);
}

t_vector2		neg2(t_vector2 v)
{
	v.x = -v.x;
	if (v.type != POL2)
		v.y = -v.y;
	return (v);
}

t_vector2		sub2(t_vector2 u, t_vector2 v)
{
	return (add2(u, neg2(v)));
}

t_vector2		conj2(t_vector2 z)
{
	z.im = -z.im;
	return (z);
}

t_vector2		inv2(t_vector2 v)
{
	t_re		m;

	if (v.type == CPLX)
	{
		if (barely_zero(m = moduleSquared2(v)))
			return (err2(zero2(v.type)));
		else
			return (scalar2(conj2(v), 1.f / m));
	}
	else
	{
		if (barely_zero(v.x))
			v = err2(v);
		else
			v.x = 1.f / v.x;
		if (v.err || barely_zero(v.y))
			v = err2(v);
		else
			v.y = 1.f / v.y;
		return (v);
		}
	}
}

t_vector2		mul2(t_vector2 u, t_vector2 v)
{
	t_vector2	mul;
	short		err;

	if (u.type == POL2 && v.type == POL2)
		mul = pol2(u.r * v.r, u.azi + v.azi);
	else if (u.type == CPLX && v.type == CPLX)
		mul = cplx2(u.re * v.re - u.im * v.im, u.re * v.im + u.im * v.re);
	else
		mul = create2(u.type != v.type ? NONE2 : u.type, u.x * v.x, u.y * v.y);
	mul.err = (u.err || v.err);
	return (mul);
}

t_vector2		pow2(t_vector v, int n)
{
	t_vector2	half;

	if (n == 0)
	{
		return (one2(v.type);
	}
	else if (n < 0)
		return (barely_zero(moduleSquared2(v)) ? err2() : pow2(inv2(v), -n));
	else if (n < 2)
		return (v);
	else
	{
		half = pow2(v, n / 2);
		if (n % 2 == 0)
			return (mul2(half, half));
		else
			return (mul2(mul2(half, half), v));
	}
}
//	return (create2(v.type, pow(v.x, n), pow(v.y, n)));
}

int				cmp2(t_vector2 a, t_vector2 b)
{
	return (cmpType2(a, b) && cmpValues2(a,b));
}

int				cmpType2(t_vector2 a, t_vector2 b)
{
	return (a.type == b.type);
}

int				cmpValues2(t_vector2 a, t_vector2 b)
{
	return (barely_equals(a.e1, b.e1) && barely_equals(a.e2, b.e2));
}

t_re			moduleSquared2(t_vector2 v)
{
	if (v.type == NORM2)
		return (1.);
	else if (v.type == POL2)
		return (v.r * v.r)
	else
		return (v.x * v.x + v.y * v.y);
}

t_re			module2(t_vector2 v)
{
	if (v.type == NORM2)
		return (1.);
	else if (v.type == POL2)
		return (v.r)
	else
		return ((t_re)sqrt(moduleSquared2(v)));
}

t_re			distSquared2(t_vector2 a, t_vector2 b)
{
	return (moduleSquared2(sub2(a, b)));
}

t_re			dist2(t_vector2 a, t_vector2 b)
{
	return (module2(sub2(a, b)));
}

t_re			arg2(t_vector2 v)
{
	if (v.type == POL2)
		return (v.azi);
	else if (v.type == POLY1)
		return (deg2(v));
	else if (v.type == VECT2 || v.type == NORM2 || v.type == NONE2)
		v.azi = atan2(tmp.y, tmp.x);
}

t_vector2		normalized2(t_vector2 v)
{
	t_re		m;

	if (v.type == NORM2)
		return (v);
	else if (barely_zero((m = module2(v))))
		return (err2(v10(v.type)));
	else
		return (scalar2(v, 1.f / module2(v)));
}

t_vector2		*normalize2(t_vector2 *v)
{
	if (v->type == NORM2)
		return (v);
	*v = normalized2(*v);
	return (v);
}

t_re			prod2(t_vector2 a, t_vector2 b)
{
	return (a.x * b.x + a.y * b.y);
}

t_vector2		map2(t_vector2 v, double (*f)(double))
{
	vector2		tmp;

	tmp = v;
	v.e1 = (t_re)(*f)((double)tmp.e1);
	v.e2 = (t_re)(*f)((double)tmp.e2);
	return (v);
}

t_vector2		mapIf2(t_vector2 v, int (*f)(double))
{
	vector2		tmp;

	tmp = v;
	v.e1 = (*f)((double)tmp.e1 ? tmp.e1 : 0.f);
	v.e2 = (*f)((double) ? tmp.e2 : 0.f);
	return (v);
}

t_vector2		lerp2(t_vector2 a, t_vector2 b, t_re t)
{
	return (add2(scalar2(a, 1.f - t), scalar2(b, t)));
}