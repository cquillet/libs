/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_re_as_float.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:38:16 by cquillet          #+#    #+#             */
/*   Updated: 2019/08/16 16:39:11 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**
** float is a 32 bit IEEE 754 single precision Floating Point Number
** 1 bit for the sign,
** 8 bits for the exponent, and
** 23 bots for the value,
**
** i.e. float has 7 decimal digits of precision.
**
** float
** 4 bytes
** 1.2E-38 to 3.4E+38
** 6 decimal places
**
** suffix: f or F
**
*/

#ifndef TYPE_RE_AS_FLOAT_H
# define TYPE_RE_AS_FLOAT_H

# ifndef __TYPEDEF_RE_DEFINE__
#  define __TYPEDEF_RE_DEFINE__

typedef float t_re;

#  define RE_ZERO 0.0F
#  define RE_ONE 1.0F

#  define INV_SQRT_2 0.70710678F
#  define INV_SQRT_3 0.57735027F
#  define INV_SQRT_4 0.5F

#  define _RE_SUFFIX F

# endif

# ifndef MARGIN_ERROR
#  define MARGIN_ERROR 0.0000001F
# endif
/*
# include "type_re.h"
*/
#endif
