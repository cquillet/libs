/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector4.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 18:14:15 by cquillet          #+#    #+#             */
/*   Updated: 2019/04/19 18:25:22 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type_re.h"

#ifndef VECTOR4_H
# define VECTOR4_H

/*
**
**	0	NONE
**	1	VECT		vector
**	2	NORM		normalized vector
**	3	POL			vector in polar coordinates
**	4	CPLX/QUAT	complex number / quaternion
**	5	POLY		polynomial
**	6	COLOR		color
**	7	HOMO4		vector3 in homogeous coordinates
**	8	MAT2x2		2 x 2 matrix
**	9	BOX4		box
**	10	PARAM4		parametric vector
**
*/

typedef enum e_type4 { NONE4 = 0, VECT4, NORM4, POL4, QUAT4, POLY3, COLOR4,
										HOMO4, MAT2x2, BOX4, PARAM4 } t_type4;

typedef struct	s_vector4
{
	union {
		t_re	e1;
		t_re	x;
		t_re	r;
		t_re	m00;
		t_re	a0;
		t_re	x_min;
	};
	union {
		t_re	e2;
		t_re	y;
		t_re	azi;
		t_re	i;
		t_re	g;
		t_re	m01;
		t_re	a1;
		t_re	x_max;
	};
	union {
		t_re	e3;
		t_re	z;
		t_re	pol;
		t_re	j;
		t_re	b;
		t_re	m10;
		t_re	a2;
		t_re	y_min;
	};
	union {
		t_re	e4;
		t_re	t;
		t_re	k;
		t_re	a;
		t_re	m11;
		t_re	a3;
		t_re	y_max;
	};
	t_type4		type;
	short		err;
}				t_vector4;

t_vector4		one4(t_type4 t);
t_vector4		zero4(t_type4 t);
t_vector4		unit4(t_type4 t);
t_vector4		rot2x2(t_re angle);

t_vector4		vect4(t_re x1, t_re x2, t_re x3, t_re x4);
t_vector4		param4(t_re x, t_re y, t_re z, t_re t);
t_vector4		pol4(t_re r, t_re theta, t_re phi, t_re t);
t_vector4		quat4(t_re x1, t_re x2, t_re x3, t_re x4);
t_vector4		poly3(t_re a3, t_re a2, t_re a1, t_re a0);
t_vector4		color4(t_re x1, t_re x2, t_re x3, t_re x4);
t_vector4		mat2x2(t_re x1, t_re x2, t_re x3, t_re x4);
t_vector4		box4(t_re x_min, t_re x_max, t_re y_min, t_re y_max);

t_vector4		neg4(t_vector4 v);
t_vector4		scalar4(t_vector4 v, t_re scalar);
t_vector4		add4(t_vector4 u, t_vector4 v);
t_vector4		sub4(t_vector4 u, t_vector4 v);
t_vector4		mul4(t_vector4 u, t_vector4 v);

int				cmp4(t_vector4 a, t_vector4 b);
int				cmpType4(t_vector4 a, t_vector4 b);
int				cmpValues4(t_vector4 a, t_vector4 b);

t_re			module4(t_vector4 v);
t_re			distSquared4(t_vector4 a, t_vector4 b);
t_re			dist4(t_vector4 a, t_vector4 b);
t_re			det2x2(t_vector4 m);

t_vector4		normalized4(t_vector4 v);
t_vector4		*normalize4(t_vector4 *v);
t_vector4		lerp4(t_vector4 a, t_vector4 b, t_re t);

void			print4(t_vector4 v);

#endif
