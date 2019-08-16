/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:07:51 by cquillet          #+#    #+#             */
/*   Updated: 2019/08/16 16:45:30 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect_print.h"
#include <stdio.h>

void			print2(t_vector2 v)
{
	if (v.type == VECT2)
		printf("x=%8.5f\ny=%8.5f\n", v.x, v.y);
	else if (v.type == CPLX)
		printf("Re=%8.5f\nIm=%8.5f\n", v.re, v.im);
	else
		printf("x1=%8.5f\nx2=%8.5f\n", v.e1, v.e2);
	if (v.err || v.type == NONE2)
		printf("\t\tERROR = %d\n", v.err);
	printf("\n");
}


void			print3(t_vector3 v)
{
	if (v.type == VECT3)
		printf("x=%8.5f\ny=%8.5f\nz=%8.5f\n", v.x, v.y, v.z);
	else if (v.type == QUAT3)
		printf("i=%8.5f\nj=%8.5f\nk=%8.5f\n", v.i, v.j, v.z);
	else if (v.type == COLOR3)
		printf("r=%1.5f\ng=%1.5f\nb=%1.5f\n", v.r, v.g, v.b);
	else
		printf("x1=%8.5f\nx2=%8.5f\nx3=%8.5f\n", v.e1, v.e2, v.e3);
	if (v.err || v.type == NONE3)
		printf("\t\tERROR = %d\n", v.err);
	printf("\n");
}

void			print4(t_vector4 v)
{
	if (v.type == QUAT4)
		printf("r=%8.5f\ni=%8.5f\nj=%8.5f\nk=%8.5f\n", v.r, v.i, v.j, v.z);
	else if (v.type == COLOR4)
		printf("r=%1.5f\ng=%1.5f\nb=%1.5f\na=%1.5f\n", v.r, v.g, v.b, v.a);
	else if (v.type == MAT2x2)
		printf("|%8.5f\t|\t%8.5f|\n|%8.5f\t|\t%8.5f|\n", v.m00, v.m01, v.m10, v.m11);
	else
		printf("x1=%8.5f\nx2=%8.5f\nx3=%8.5f\nx4=%8.5f\n", v.e1, v.e2, v.e3, v.e4);
	if (v.err || v.type == NONE4)
		printf("\t\tERROR = %d\n", v.err);
	printf ("\n");
}

