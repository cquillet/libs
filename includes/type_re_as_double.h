/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_re_as_double.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:45:45 by cquillet          #+#    #+#             */
/*   Updated: 2019/04/19 18:28:33 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**
** double has 2x more precision then float.
**
** double is a 64 bit IEEE 754 double precision Floating Point Number
** 1 bit for the sign,
** 11 bits for the exponent, and
** 52 bits for the value,
**
** i.e. double has 15 decimal digits of precision.
**
** double
** 8 bytes
** 2.3E-308 to 1.7E+308
** 15 decimal places
**
** suffix: none or other than f, F, l, L
**
*/

#ifndef TYPE_RE_AS_DOUBLE_H
# define TYPE_RE_AS_DOUBLE_H

# ifndef __TYPEDEF_RE__
#  define __TYPEDEF_RE__

typedef double t_re;

#  define MARGIN_ERROR 1e-15
#  define RE_ZERO 0.0
#  define RE_ONE 1.0
#  define _RE_SUFFIX

# endif

# include "type_re.h"

#endif
