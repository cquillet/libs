/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_re.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:58:53 by cquillet          #+#    #+#             */
/*   Updated: 2019/04/19 18:17:24 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type_re.h"

t_re		ft_absf(t_re a)
{
	return (a < RE_ZERO ? -a : a);
}

int			barely_zero(t_re a)
{
	return (ft_abs(a) < MARGIN_ERROR);
}

int			barely_equals(t_re a, t_re b)
{
	return (barely_zero(a - b));
}
