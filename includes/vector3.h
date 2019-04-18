/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 18:14:28 by cquillet          #+#    #+#             */
/*   Updated: 2019/04/15 18:27:09 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3_H
# define VECTOR3_H

# ifndef TYPEDEF_RE_AS
#  include "type_re_as_double.h"
# endif

# define INV_SQRT_3 0.57735027

typedef enum e_type3 { NONE3 = 0, VECT3, POL3, QUAT3, POLY2, COLOR3 } t_type3;

typedef struct	s_vector3
{
	union {
		t_re	e1;
		t_re	x;
		t_re	r;
		t_re	i;
		t_re	a2;
	};
	union {
		t_re	e2;
		t_re	y;
		t_re	azi;
		t_re	j;
		t_re	a1;
		t_re	g;
	};
	union {
		t_re	e3;
		t_re	z;
		t_re	pol;
		t_re	k;
		t_re	a0;
		t_re	b;
	};
	t_type3		type;
	short		err;
}				t_vector3;

t_vector3		vect3(t_re x, t_re y, t_re z);
t_vector3		pol3(t_re r, t_re theta, t_re phi);
t_vector3		quat3(t_re i, t_re j, t_re k);
t_vector3		poly2(t_re a2, t_re a1, t_re a0);
t_vector3		color3(t_re r, t_re g, t_re b);

t_vector3		toPol3(t_vector3 v);
t_vector3		toVect3(t_vector3 v);

t_vector3		scalar3(t_vector3 v, t_re scalar);
t_vector3		add3(t_vector3 u, t_vector3 v);
t_vector3		sub3(t_vector3 u, t_vector3 v);
t_vector3		mul3(t_vector3 u, t_vector3 v);

int				cmp3(t_vector3 a, t_vector3 b);
int				cmpType3(t_vector3 a, t_vector3 b);
int				cmpValues3(t_vector3 a, t_vector3 b);

t_re			moduleSquared3(t_vector3 v);
t_re			module3(t_vector3 v);
t_re			distSquared3(t_vector3 a, t_vector3 b);
t_re			dist3(t_vector3 a, t_vector3 b);

t_re			prod3(t_vector3 a, t_vector3 b);

t_vector3		normalized3(t_vector3 v);
t_vector3		*normalize3(t_vector3 *v);
t_vector3		map3(t_vector3 v, double (*f)(double));
t_vector3		lerp3(t_vector3 a, t_vector3 b, t_re t);

void			print3(t_vector3 v);

#endif
