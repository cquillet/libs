/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 19:17:12 by cquillet          #+#    #+#             */
/*   Updated: 2019/08/16 16:43:49 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "../../includes/vector2.h"
#include "../../includes/vector3.h"
#include "../../includes/vector4.h"
*/
#include "vector2.h"
#include "vector3.h"
#include "vector4.h"
#include "vect_print.h"

#include <stdio.h>

int main (int ac, char **av)
{
	t_vector2 a2;
	t_vector2 b2;

	t_vector3 a3;
	t_vector3 b3;

	t_vector4 a4;
	t_vector4 b4;

	printf("\n\n************ 2 **************\n\n");

	a2 = vect2(1.f, 0.f);
	b2 = vect2(0.f, 1.f);

	print2(a2);
	print2(b2);
	print2(mul2(a2, b2));

	a2.type = CPLX;
	b2.type = CPLX;

	print2(a2);
	print2(b2);
	print2(mul2(a2, b2));

	printf("\n\n************ 3 **************\n\n");

	a3 = vect3(1.f, 0.f, 0.f);
	b3 = vect3(0.f, 1.f, 0.f);

	print3(a3);
	print3(b3);
	print3(mul3(a3, b3));

	a3.type = COLOR3;
	b3.type = COLOR3;

	print3(a3);
	print3(b3);
	print3(mul3(a3, b3));

	printf("\n\n************ 4 **************\n\n");

	a4 = vect4(1.f, 0.f, 0.f, 0.f);
	b4 = vect4(0.f, 1.f, 0.f, 0.f);

	print4(a4);
	print4(b4);
	print4(mul4(a4, b4));

	a4.type = MAT2x2;
	b4.type = MAT2x2;

	print4(a4);
	print4(b4);
	print4(mul4(a4, scalar4(b4, 2.f)));

	b4.type = COLOR4;

	print4(b4);
	print4(mul4(a4, scalar4(b4, 2.f)));

	return (0);
}
