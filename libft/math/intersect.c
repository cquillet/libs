/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:27:43 by cquillet          #+#    #+#             */
/*   Updated: 2019/04/05 18:22:01 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"


t_pv			planePvIntersectLine(t_pv plane, t_pv line)
{
	t_pv		out;
	t_re		d;

	if ((d = mul3(plane.n, line.dir)) == 0f)
		return (errPV());
	return (mul3(plane.n, sub3(plane.ori, line.ori)) / d);
}

t_pv			planeIntersectLine(t_vector4 plane, t_pv line)
{
	return (errPv());
}

t_ray			planePvIntersectRay(t_pv plane, t_ray *in)
{
	t_ray		out;

	return (out);
}

t_ray			planeIntersectRay(t_vector4 plane, t_ray *in)
{
	t_ray		out;

	return (out);
}

t_pv			tri3IntersectLine(t_tri3 t, t_pv r)
{

}

t_ray			tri3Intersect(t_tri3 t, t_ray *r)
{
	t_vector3	u;
	t_vector3	v;

	
}
