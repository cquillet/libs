/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_re.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:55:34 by cquillet          #+#    #+#             */
/*   Updated: 2019/04/19 18:27:16 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_RE
# define TYPE_RE

# ifndef __TYPEDEF_RE__
#  include "type_re_as_double.h"
# endif

# define INV_SQRT_2 0.70710678_RE_SUFFIX
# define INV_SQRT_3 0.57735027_RE_SUFFIX
# define INV_SQRT_4 0.5_RE_SUFFIX

t_re				ft_absf(t_re a);

int					barely_zero(t_re a);
int					barely_equals(t_re a, t_re b);

#endif
