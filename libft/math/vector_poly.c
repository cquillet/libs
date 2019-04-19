/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_poly.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:38:43 by cquillet          #+#    #+#             */
/*   Updated: 2019/04/19 19:28:02 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector2.h"
#include "vector3.h"
#include "vector4.h"
#include <math.h>

#include <stdio.h>

t_vector3		poly3_derivative(t_vector4 p)
{
	return (poly2(3._RE_SUFFIX * p.a3, 2._RE_SUFFIX * p.a2, a1));
}

t_vector2		poly2_derivative(t_vector3 p)
{
	return (poly1(2._RE_SUFFIX * p.a2, a1));
}

t_re			poly1_derivative(t_vector2 p)
{
	return (p.a1);
}

t_vector4		poly2_intregal(t_vector3 p, t_re valueForZero)
{
	return (poly3(p.a2 / 3._RE_SUFFIX, 0.5_RE_SUFFIX * p.a1, a0, valueForZero));
}

t_vector3		poly1_intregal(t_vector2 p, t_re valueForZero)
{
	return (poly2(0.5_RE_SUFFIX * p.a1, a0, valueForZero));
}

t_vector2		real_intregal(t_re p, t_re valueForZero)
{
	return (poly1(p, valueForZero));
}

t_vector2		*poly1_solve(t_vector2 p)
{
	t_vector2	*solution;

/*	if (p.a1 == 0.f)
		return (NULL);
	if (!(solution = (t_vector2 *)malloc(sizeof(t_vector2))))
		*solution = create2(-p.a0 / p.a1);
	else
	*/
	return (&solution);

}

t_vector3		downgrade4(t_vector4 v)
{
	t_vector3	u;

	u = create3(NONE3, v.x1, v.x2, v.x3);
	u.err = v.err;
	if (v.type == MAT2x2 || v.type == BOX4)
		u.err = 1;
	else if (v.type == HOMO4)
		u.type = VECT3;
	else
		u.type = (t_type3)v.type;
	return (u);
}

t_vector2		downgrade3(t_vector3 v)
{
	t_vector2	u;

	if (v.type == QUAT3)
		return (err2(cplx2(NONE3, RE_ZERO, v.x1)));
	else
		u = create2(NONE3, v.x1, v.x2);
	u.err = v.err;
	if (v.type == COLOR3)
		u.err = 1;
	else
		u.type = (t_type3)v.type;
	return (u);
}

t_re			downgrade2(t_vector2 v)
{
	return (v.x);
}

t_vector4		vect3to4(t_vector3 v)
{
	return (upgrade3(v, (v.type == POLY2) ? RE_ONE : RE_ZERO));
}

t_vector4		upgrade3(t_vector3 v, t_re x4)
{
	t_vector4	u;

	u = create4(NONE3, v.x1, v.x2, v.x3, x4);
	u.err = v.err;
	u.type = (t_type4)v.type;
	return (u);
}

t_vector3		upgrade2(t_vector2 v)
{
	if (v.type == VECT2)
		return (vect3(v.x, v.y, RE_ZERO));
	else if (v.type == CPLX)
		return (quat3(v.im, RE_ZERO, RE_ZERO));
	else if (v.type == POLY1)
		return (poly2(RE_ONE, v.a1, v.a0));
	else
		return (create3(NONE3, v.x1, v.x2, RE_ZERO));
}

t_vector2		dimBox4(t_vector4 box)
{
	return (box2(box.x_max - box.x_min, box.y_max - box.y_min));
}

t_vector2		center4(t_vector4 box)
{
	return (scalar2(vect2(box.x_min + box.x_max, b.y_min + b.y_max),
															0.5_RE_SUFFIX));
}

/*
**
** -1 : out of the box
**  0 : on the frontier
**  1 : inside the box
**
*/

int				isInBox4(t_vector4 box, t_vector2 p)
{
	if (p.x < box.x_min || p.x > box.x_max)
		return (-1);
	else if (p.y < box.y_min || p.y > box.y_max)
		return (-1);
	else
		return (p.x > box.x_min && p.x < box.x_max &&
								p.y > box.y_min && p.y < box.y_max);
}

t_vector3		mulPoly1By1(t_vector2 p1, t_vector2 p2)
{
	return (poly2(p1.a1 * p2.a1,
					p1.a0 * p2.a1 + p1.a1 * p2.a0,
					p1.a0 * p2.a0));
}

t_vector4		mulPoly2By1(t_vector3 p1, t_vector2 p2)
{
	return (poly3(p1.a2 * p2.a1,
					p1.a2 * p2.a0 + p1.a1 * p2.a1,
					p1.a1 * p2.a0 + p1.a0 * p2.a1,
					p1.a0 * p2.a0));
}

t_vector4		mulPoly1By2(t_vector2 p1, t_vector3 p2)
{
	return (mulPoly2By1(p2, p1));
}

t_vector2		*poly2_solve(t_vector3 p)
{
	return (NULL);
}

t_vector2		*poly3_solve(t_vector4 p)
{
	return (NULL);
}

int				poly2_solve(t_vector3 p, t_vector2 *solutions)
{
	t_re		discri;
	t_re		root;

	if (p.a2 == RE_ZERO)
		return (0);
	discri = p.a1 * p.a1 - 4._RE_SUFFIX * p.a2 * p.a1;
	if (discri < RE_ZERO)
		return (0);
	else if (discri == RE_ZERO)
	{
		solutions = (t_vector2 *)malloc(sizeof(t_vector2));
		*solutions = vect2(-p.a1 / 2._RE_SUFFIX / p.a2, RE_ZERO);
		return (1);
	}
	solutions = (t_vector2 *)malloc(sizeof(t_vector2));
	root = (t_re)sqrt(discri);
	*solutions = vect2((-p.a1 - root) / 2.RE_SUFFIX / p.a2,
							(-p.a1 + root) / 2._RE_SUFFIX / p.a2);
	return (2);
}
