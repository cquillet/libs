/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:07:51 by cquillet          #+#    #+#             */
/*   Updated: 2019/04/10 21:17:51 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect_print.h"

void			print2(t_vector2 v)
{
	if (v.type == VECT2)
		printf("x=%8.5Lf\ny=%8.5Lf\n", v.x, v.y);
	else if (v.type == CPLX)
		printf("Re=%8.5Lf\nIm=%8.5Lf\n", v.re, v.im);
	else
		printf("x1=%8.5Lf\nx2=%8.5Lf\n", v.x1, v.x2);
	if (v.err || v.type == NONE2)
		printf("\t\tERROR = %d\n", v.err);
	printf("\n");
}


void			print3(t_vector3 v)
{
	if (v.type == VECT3)
		printf("x=%8.5Lf\ny=%8.5Lf\nz=%8.5Lf\n", v.x, v.y, v.z);
	else if (v.type == QUAT3)
		printf("i=%8.5Lf\nj=%8.5Lf\nk=%8.5Lf\n", v.i, v.j, v.z);
	else if (v.type == COLOR3)
		printf("r=%1.5Lf\ng=%1.5Lf\nb=%1.5Lf\n", v.r, v.g, v.b);
	else
		printf("x1=%8.5Lf\nx2=%8.5Lf\nx3=%8.5Lf\n", v.x1, v.x2, v.x3);
	if (v.err || v.type == NONE3)
		printf("\t\tERROR = %d\n", v.err);
	printf("\n");
}

void			print4(t_vector4 v)
{
	if (v.type == QUAT4)
		printf("r=%8.5Lf\ni=%8.5Lf\nj=%8.5Lf\nk=%8.5Lf\n", v.r, v.i, v.j, v.z);
	else if (v.type == COLOR4)
		printf("r=%1.5Lf\ng=%1.5Lf\nb=%1.5Lf\na=%1.5Lf\n", v.r, v.g, v.b, v.a);
	else if (v.type == MAT2x2)
		printf("|%8.5Lf\t|\t%8.5Lf|\n|%8.5Lf\t|\t%8.5Lf|\n", v.m00, v.m01, v.m10, v.m11);
	else
		printf("x1=%8.5Lf\nx2=%8.5Lf\nx3=%8.5Lf\nx4=%8.5Lf\n", v.x1, v.x2, v.x3, v.x4);
	if (v.err || v.type == NONE4)
		printf("\t\tERROR = %d\n", v.err);
	printf ("\n");
}

