/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_re.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:55:34 by cquillet          #+#    #+#             */
/*   Updated: 2019/04/15 19:54:58 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_RE
# define TYPE_RE

# ifndef TYPEDEF_RE_AS
#  include "type_re_as_double.h"
# endif

t_re				ft_absf(t_re a);

int					barely_zero(t_re a);
int					barely_equals(t_re a, t_re b);

#endif