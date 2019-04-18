/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_re_as_long_double.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:42:30 by cquillet          #+#    #+#             */
/*   Updated: 2019/04/15 19:54:56 by cquillet         ###   ########.fr       */
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
*/

#ifndef TYPE_RE_AS_LONG_DOUBLE_H
# define TYPE_RE_AS_LONG_DOUBLE_H

# ifndef TYPEDEF_RE_AS
#  define TYPEDEF_RE_AS

typedef long double t_re;

# endif

# ifndef MARGIN_ERROR
#  define MARGIN_ERROR (t_re)(1e-19)
# endif

# include "type_re.h"

#endif
