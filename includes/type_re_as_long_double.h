/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_re_as_long_double.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:42:30 by cquillet          #+#    #+#             */
/*   Updated: 2019/08/16 16:39:20 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**
** long double is either
** x86 extended-precision floating-point format 
** 		(80 bits, but typically 96 or 128 bits in memory with padding bytes), or
** the non-IEEE "double-double" (128 bits), or
** IEEE 754 quadruple-precision floating-point format (128 bits), or
** the same as double
**
** x86 extended precision format
** 1 bit for the sign,
** 15 bits for the exponent, and
** 63+1 bits for the value,
**
** i.e. float has 7 decimal digits of precision.
**
** long double
** 10 byte
** 3.4E-4932 to 1.1E+4932
** 19 decimal places
**
** suffix: l or L
**
*/

#ifndef TYPE_RE_AS_LONG_DOUBLE_H
# define TYPE_RE_AS_LONG_DOUBLE_H

# ifndef __TYPEDEF_RE_DEFINE__
#  define __TYPEDEF_RE_DEFINE__

typedef long double t_re;

#  define RE_ZERO 0.0L
#  define RE_ONE 1.0L

#  define INV_SQRT_2 0.70710678L
#  define INV_SQRT_3 0.57735027L
#  define INV_SQRT_4 0.5L

#  define _RE_SUFFIX L

# endif

# ifndef MARGIN_ERROR
#  define MARGIN_ERROR 1e-19L
# endif
/*
# include "type_re.h"
*/
#endif
