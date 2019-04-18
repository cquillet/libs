/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:33:57 by cquillet          #+#    #+#             */
/*   Updated: 2019/04/05 15:53:39 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector2.h"
#include "vector3.h"
#include "ray.h"

#ifndef TRIANGLE_H
# define TRIANGLE_H

# ifndef TYPEDEF_CPLX
#  define TYPEDEF_CPLX

typedef long double	t_re;

# endif

typedef struct		s_tri3
{
	union
	{
		t_vector3		v1;
		t_vector3		n1;
	};
	union
	{
		t_vector3		v2;
		t_vector3		n2;
	};
	union
	{
		t_vector3		v3;
		t_vector3		n3;
	};
}					t_tri3;

t_tri3			tri3(t_vector3 v1, t_vector3 v2, t_vector3 v3);

t_re			tri3Dist();
t_vector3		tri3Intersect(t_tri3 t, t_ray r);
t_polygon		square(t_re width, t_vector2 center);
t_polygon		rect(t_re width, t_re heigh, t_vector2 center);
t_polygon		circle(t_re radius, t_vector2 center);
t_polygon		ellipse(t_re radius, t_re radius2, t_vector2 center);

t_re			area2(t_polygon p);
t_re			perimeter(t_polygon p);

int				isInPoly2(t_polygon p, t_vector2 v);

void			printPoly2(t_polygon p);

#endif
