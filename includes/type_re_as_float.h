/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_re_as_float.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:38:16 by cquillet          #+#    #+#             */
/*   Updated: 2019/04/15 18:59:40 by cquillet         ###   ########.fr       */
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
*/

#ifndef TYPE_RE_AS_FLOAT_H
# define TYPE_RE_AS_FLOAT_H

# ifndef TYPEDEF_RE_AS
#  define TYPEDEF_RE_AS

typedef float t_re;

# endif

# ifndef MARGIN_ERROR
#  define MARGIN_ERROR (t_re)0.0000001
# endif

# include "type_re.h"

#endif
