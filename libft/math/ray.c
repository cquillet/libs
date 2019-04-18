/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:38:01 by cquillet          #+#    #+#             */
/*   Updated: 2019/04/05 17:56:19 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_pv			errPv()
{
	t_pv		e;

	e.ori = err3();
	e.n = err3();
}

t_ray			errRay()
{
	t_ray		r;

	r.from = errPv();
	r.to = errPv();
	wavelength = -1.f;
}

t_ray			ray(t_pv from, t_pv to)
{
	return (colored3Ray(from, to, zero4(COLOR4)));
}

t_ray			colored3Ray(t_pv from, t_pv to, t_vector3 color)
{
	return (colored3Ray(from, to, upgrade3(color)));
}

t_ray			colored4Ray(t_pv from, t_pv to, t_vector4 color)
{
	t_ray		r;

	r.from = from;
	r.to = to;
	r.incident = NULL;
	r.hits = 0;
	r.dist = 0.f;
	r.wavelength = 0.f;
	r.polarization = 0.f;
	r.color = color;
}

void			printPv(t_pv r)
{
	if (r.ori.err || r.dir.err)
		printf("ERR\n");
	else
	{
		write(STDOUT_FILENO, "ori: ", 5);
		print3(r.ori);
		write(STDOUT_FILENO, "dir: ", 5);
		print3(r.dir);
	}
}

void			printRay(t_ray r)
{
	printf("From\n");
	printPv(r.from);
	
	printf("To\n");
	printPv(r.from);

	print3(r.color);
}

#endif
