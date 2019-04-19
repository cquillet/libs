/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 18:23:02 by cquillet          #+#    #+#             */
/*   Updated: 2019/04/19 19:21:30 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"
#include <math.h>

t_vector3		err3(t_vector3 v)
{
	v.err = 1;
	return (v);
}

static t_vector3	create3(t_type3 t, t_re x1, t_re x2, t_re x3)
{
	t_vector3	v;

	v.type = t;
	v.x1 = x1;
	v.x2 = x2;
	v.x3 = x3;
	v.err = 0;
	return (v);
}

t_vector3		zero3(t_type3 t)
{
	return (create3(t, RE_ZER0, RE_ZER0, RE_ZER0));
}

t_vector3		one3(t_type3 t)
{
	return (create3(t, RE_ONE, RE_ONE, RE_ONE));
}

t_vector3		unit3(t_type t)
{
	return (create3(t, INV_SQRT_3, INV_SQRT_3, INV_SQRT_3));
}

t_vector3		vect3(t_re x, t_re y, t_re z)
{
	return (create3(VECT3, x, y, z));
}

t_vector3		quat3(t_re i, t_re j, t_re k)
{
	return (create3(QUAT3, i, j, k));
}

t_vector2		poly2(t_re a2, t_re a1, t_re a0)
{
	return (create2(POLY2, a0, a1, a2));
}

t_vector3		color3(t_re r, t_re g, t_re b)
{
	return (create3(COLOR3, r, g, b));
}

t_vector3		scalar3(t_vector3 v, t_re scalar)
{
	t_vector3	coeff;
	
	if (scalar == RE_ZER0)
		return zero3(v.type);
	else if (v.err != 0)
		return err3();
	coeff.x = scalar * v.x;
	coeff.y = scalar * v.y;
	coeff.z = scalar * v.z;
	coeff.type = v.type;
	return (coeff);
}

t_vector3		add3(t_vector3 u, t_vector3 v)
{
	t_vector3	sum;

	sum.x = u.x + v.x;
	sum.y = u.y + v.y;
	sum.z = u.z + v.z;
	sum.err = (u.err || v.err || u.type != v.type);
	sum.type = sum.err ? NONE3 : u.type;
	return (sum);
}

t_vector3		sub3(t_vector3 u, t_vector3 v)
{
	t_vector3	sub;

	sub.x = u.x - v.x;
	sub.y = u.y - v.y;
	sub.z = u.z - v.z;
	sub.err = (u.err || v.err || u.type != v.type);
	sub.type = sub.err ? NONE3 : u.type;
	return (sub);
}

t_vector3		mul3(t_vector3 u, t_vector3 v)
{
	t_vector3	mul;

	if ((mul.err = (u.err || v.err || u.type != v.type)))
		return err3();
	else if (u.type == VECT3 || u.type == QUAT3)
	{
		mul.x = u.y * v.z - v.y * u.z;
		mul.y = u.z * v.x - v.z * u.x;
		mul.z = u.x * v.y - v.x * u.y;
	}
	else
	{
		mul.r = u.r * v.r;
		mul.g = u.g * v.g;
		mul.b = u.b * v.b;
		mul.err = (u.type != COLOR3);
	}
	mul.type = mul.err ? NONE3 : u.type;
	return (mul);
}

t_re			moduleSquared3(t_vector3 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

t_re			module3(t_vector3 v)
{
	return ((t_re)sqrt(moduleSquared3(v)));
}

t_re			distSquared3(t_vector3 a, t_vector3 b)
{
	return (moduleSquared3(sub3(a, b)));
}

t_re			dist3(t_vector3 a, t_vector3 b)
{
	return (module3(sub3(a, b)));
}

t_vector3		normalized3(t_vector3 v)
{
	return (scalar3(v, RE_ONE / module3(v)));
}

t_vector3		*normalize3(t_vector3 *v)
{
	*v = scalar3(*v, RE_ONE / module3(*v));
	return (v);
}

t_re			prod3(t_vector3 a, t_vector3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

int				cmp3(t_vector3 a, t_vector3 b)
{
	return (cmpType3(a, b) && cmpValues3(a, b));
}

int				cmpType3(t_vector3 a, t_vector3 b)
{
	return (a.type == b.type);
}

int				cmpValues3(t_vector3 a, t_vector3 b)
{
	return (barely_equals(a.e1, b.e1)
			&& barely_equals(a.e2, b.e2)
			&& barely_equals(a.e3, b.e3));
}

t_vector3		map3(t_vector3 v, double (*f)(double))
{
	return (create3(v.type, 
			(t_re)(*f)((double)v.x1),
			(t_re)(*f)((double)v.x2),
			(t_re)(*f)((double)v.x3))
			);
}

t_vector3		lerp3(t_vector3 a, t_vector3 b, t_re t)
{
	return (add3(scalar3(a, RE_ONE - t), scalar3(b, t)));
}
