/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_re_as_double.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:45:45 by cquillet          #+#    #+#             */
/*   Updated: 2019/04/15 19:54:57 by cquillet         ###   ########.fr       */
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
*/

#ifndef TYPE_RE_AS_DOUBLE_H
# define TYPE_RE_AS_DOUBLE_H

# ifndef TYPEDEF_RE_AS
#  define TYPEDEF_RE_AS

typedef double t_re;

# endif

# ifndef MARGIN_ERROR
#  define MARGIN_ERROR (t_re)(1e-15)
# endif

# include "type_re.h"

#endif
