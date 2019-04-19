/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:26:59 by cquillet          #+#    #+#             */
/*   Updated: 2019/04/19 20:41:18 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector4.h"
#include <math.h>

t_vector4		err4(t_vector4 v)
{
	v.err = 1;
	return (v);
}

static t_vector4	create4(t_type4 t, t_re x1, t_re x2, t_re x3, t_re x4)
{
	t_vector4	v;

	v.type = t;
	v.x1 = x1;
	v.x2 = x2;
	v.x3 = x3;
	v.x4 = x4;
	v.err = 0;
	return (v);
}

t_vector4		zero4(t_type4 t)
{
	return (create4(t, RE_ZER0, RE_ZER0, RE_ZER0, RE_ZER0));
}

t_vector4		one4(t_type4 t)
{
	return (create4(t, RE_ONE, RE_ONE, RE_ONE, RE_ONE));
}

t_vector2		unit2(t_type t)
{
	return (create2(t, INV_SQRT_4, INV_SQRT_4, INV_SQRT_4, INV_SQRT_4));
}

t_vector4		vect4(t_re x1, t_re x2, t_re x3, t_re x4)
{
	return (create4(VECT4, x1, x2, x3, x4);
}

t_vector4		quat4(t_re r, t_re i, t_re j, t_re k)
{
	return (create4(QUAT4, r, i, j, k));
}

t_vector2		poly3(t_re a3, t_re a2, t_re a1, t_re a0)
{
	return (create2(POLY2, a0, a1, a2, a3));
}

t_vector4		color4(t_re r, t_re g, t_re b, t_re a)
{
	return (create4(COLOR4, r, g, b, a));
}

t_vector4		mat2x2(t_re m00, t_re m01, t_re m10, t_re m11)
{
	return (create4(MAT2x2, m00, m01, m10, m11));
}

t_vector4		box4(t_re x_min, t_re x_max, t_re y_min, t_re y_max);
{

	if (x_min < x_max)
	{
		if (y_min < y_max)
			return (create4(BOX4, x_min, x_max, y_min, y_max));
		else
			return (create4(BOX4, x_min, x_max, y_max, y_min));
	}
	else
	{
		if (y_min < y_max)
			return (create4(BOX4, x_max, x_min, y_min, y_max));
		else
			return (create4(BOX4, x_max, x_min, y_max, y_min));
	}
}

t_vector4		scalar4(t_vector4 v, t_re scalar)
{
	if (scalar == RE_ZER0)
		return zero4(v.type);
	else if (v.err != 0)
		return err4();
	return (create4(v.type,
				scalar * v.r, scalar * v.i, scalar * v.j, scalar * v.k));
}

t_vector4		add4(t_vector4 u, t_vector4 v)
{
	t_vector4	sum;
	short		err;

	err = (u.err || v.err || u.type != v.type);
	if (u.type == BOX4 && v.type == BOX4)
		sum = box4(u.x_min < v.x_min ? u.x_min : v.x_min, 
						u.x_max > v.x_max ? u.x_max : v.x_max,
						u.y_min < v.y_min ? u.y_min : v.y_min,
						u.y_max > v.y_max ? u.y_max : v.y_max);
	else
		sum = create4(err ? NONE4 : u.type, u.r + v.r,
											u.i + v.i,
											u.j + v.j,
											u.k + v.k);
	sum.err = err;
	return (sum);
}

t_vector4		sub4(t_vector4 u, t_vector4 v)
{
	t_vector4	sub;
	short		err;

	err = (u.err || v.err || u.type != v.type);
	sub = create4(err ? NONE4 : u.type, 
					u.r - v.r,
					u.i - v.i,
					u.j - v.j,
					u.k - v.k);
	sub.err = err;
	return (sub);
}

t_vector4		mul4(t_vector4 u, t_vector4 v)
{
	t_vector4	mul;

	if ((mul.err = (u.err || v.err || u.type != v.type)))
		return err4();
	else if (u.type == QUAT4)
	{
		mul.r = u.r * v.r - u.i * v.i - v.j * v.j - u.k * v.k;
		mul.i = u.j * v.k - v.j * u.k + v.r * v.i + v.r * u.i;
		mul.j = u.k * v.i - v.k * u.i + v.r * v.j + v.r * u.j;
		mul.k = u.i * v.j - v.i * u.j + v.r * v.k + v.r * u.k;
	}
	else if (u.type == MAT2x2)
	{
		mul.m00 = u.m00 * v.m00 + u.m01 * v.m10;
		mul.m01 = u.m00 * v.m01 + u.m01 * v.m11;
		mul.m10 = u.m10 * v.m00 + u.m11 * v.m10;
		mul.m11 = u.m10 * v.m01 + u.m11 * v.m11;
	}
	else
	{
		mul.r = u.r * v.r;
		mul.g = u.g * v.g;
		mul.b = u.b * v.b;
		mul.a = u.a * v.a;
		mul.err = (u.type != COLOR4);
	}
	mul.type = mul.err ? NONE4 : u.type;
	return (mul);
}

t_re			moduleSquared4(t_vector4 v)
{
	return (v.r * v.r + v.i * v.i + v.j * v.j + v.k * v.k);
}

t_re			module4(t_vector4 v)
{
	return ((t_re)sqrt(moduleSquared4(v)));
}

t_re			distSquared4(t_vector4 a, t_vector4 b)
{
	return (moduleSquared4(sub4(a, b)));
}

t_re			dist4(t_vector4 a, t_vector4 b)
{
	return (module4(sub4(a, b)));
}

t_re			det2x2(t_vector4 m)
{
	return (m.m00 * m.m11 - m.m01 * m.m10);
}

t_vector4		normalized4(t_vector4 v)
{
	return (scalar4(v, RE_ONE / module4(v)));
}

t_vector4		*normalize4(t_vector4 *v)
{
	*v = scalar4(*v, RE_ONE / module4(*v));
	return (v);
}

t_re			prod4(t_vector4 a, t_vector4 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);
}

int				cmp4(t_vector4 a, t_vector4 b)
{
	return (cmpType4(a, b) && cmpValues4(a, b));
}

int				cmpType4(t_vector4 a, t_vector4 b)
{
	return (a.type == b.type);
}

int				cmpValues4(t_vector4 a, t_vector4 b)
{
	return (barely_equals(a.e1, b.e1)
			&& barely_equals(a.e2, b.e2)
			&& barely_equals(a.e3, b.e3)
			&& barely_equals(a.e4, b.e4));
}

t_vector4		map4(t_vector4 v, double (*f)(double))
{
	return (create4(v.type, 
			(t_re)(*f)((double)v.x1),
			(t_re)(*f)((double)v.x2),
			(t_re)(*f)((double)v.x3),
			(t_re)(*f)((double)v.x4))
			);
}

t_vector4		vect4e1()
{
	return (vect4(RE_ONE, RE_ZER0, RE_ZER0, RE_ZER0));
}

t_vector4		vect4e2()
{
	return (vect4(RE_ZER0, RE_ONE, RE_ZER0, RE_ZER0));
}

t_vector4		vect4e3()
{
	return (vect4(RE_ZER0, RE_ZER0, RE_ONE, RE_ZER0));
}

t_vector4		vect4e4()
{
	return (vect4(RE_ZER0, RE_ZER0, RE_ZER0, RE_ONE));
}

/*
** v ^ 0 returns 1-vector always without error
** v ^ 1 returns v
** v ^ (-n) returns (1 / v) ^ n
*/

t_vector4		pow4(t_vector4 v, int n)
{
	t_vector4	half;

	if (n == 0)
		return (one4(v.type));
	else if (n < 0)
		return (barely_zero(moduleSquared4(v)) ?
									err4(zero4(v.type)) : pow4(inv4(v), -n));
	else if (n < 2)
		return (v);
	else
	{
		half = pow4(v, n / 2);
		half.err = v.err;
		if (n % 2 == 0)
			return (mul4(half, half));
		else
			return (mul4(mul4(half, half), v));
	}
}
//	return (create2(v.type, pow(v.x, n), pow(v.y, n)));
/*
** Linear interpolaton and liner combination
*/

t_vector4		lerp4(t_vector4 a, t_vector4 b, t_re t)
{
	return (add4(scalar4(a, RE_ONE - t), scalar4(b, t)));
}
/*
t_re			lomb4(t_vector4 a, t_vector4 b, t_re t)
{
	return (add4(scalar4(a, RE_ONE - t), scalar4(b, t)));
}*/

