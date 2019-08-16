/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:11:25 by cquillet          #+#    #+#             */
/*   Updated: 2019/08/16 15:24:48 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type_re.h"

#ifndef VECTOR2_H
# define VECTOR2_H

/*
**
**				For dimensions 2, 3, 4
**
**	0	NONE
**	1	VECT		vector
**	2	NORM		normalized vector
**	3	POL			vector in polar coordinates
**	4	CPLX/QUAT	complex number / quaternion
**	5	POLY		polynomial
**
**
**				For dimensions 3, 4
**
**	6	COLOR		color
**
**
**				For dimension 4 only
**
**	7	HOMO4		vector in homogeous coordinates
**	8	MAT2x2		2 x 2 matrix
**	9	BOX4		box
**	10	PARAM4		parametric vector
**
*/

typedef enum e_type2 { NONE2 = 0, VECT2, NORM2, POL2, CPLX, POLY1 } t_type2;

typedef struct	s_vector2
{
	union {
		t_re	e1;
		t_re	x;
		t_re	r;
		t_re	re;
		t_re	a0;
	};
	union {
		t_re	e2;
		t_re	y;
		t_re	azi;
		t_re	im;
		t_re	a1;
	};
	t_type2		type;
	short		err;
}				t_vector2;

t_vector2		vect2(t_re x, t_re y);
t_vector2		norm2(t_re x, t_re y);
t_vector2		pol2(t_re r, t_re theta);
t_vector2		cplx2(t_re re, t_re im);
t_vector2		quat2(t_re re, t_re im);
t_vector2		poly1(t_re a1, t_re a0);

t_vector2		toPol2(t_vector2 v);
t_vector2		toVect2(t_vector2 v);

t_vector2		err2(t_vector2 v);
t_vector2		one2(t_type2 t);
t_vector2		zero2(t_type2 t);
t_vector2		unit2(t_type2 t);
t_vector2		v10(t_type2 t);
t_vector2		v01(t_type2 t);

t_vector2		scalar2(t_vector2 v, t_re scalar);
t_vector2		neg2(t_vector2 v);
t_vector2		add2(t_vector2 u, t_vector2 v);
t_vector2		sub2(t_vector2 u, t_vector2 v);
t_vector2		mul2(t_vector2 u, t_vector2 v);
t_vector2		pow2(t_vector2 u, int power);

int				cmp2(t_vector2 a, t_vector2 b);
int				cmpType2(t_vector2 a, t_vector2 b);
int				cmpValues2(t_vector2 a, t_vector2 b);

t_vector2		conj2(t_vector2 z);
t_vector2		inv2(t_vector2 v);

t_re			moduleSquared2(t_vector2 v);
t_re			module2(t_vector2 v);
t_re			distSquared2(t_vector2 a, t_vector2 b);
t_re			dist2(t_vector2 a, t_vector2 b);
t_re			prod2(t_vector2 a, t_vector2 b);
t_re			eval2(t_vector2 p, t_re x);

t_vector2		normalized2(t_vector2 v);
t_vector2		*normalize2(t_vector2 *v);
t_vector2		map2(t_vector2 v, double (*f)(double));
t_vector2		lerp2(t_vector2 a, t_vector2 b, t_re t);

void			print2(t_vector2 v);

#endif
