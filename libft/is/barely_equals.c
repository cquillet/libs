/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   barely_equals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 00:11:54 by cquillet          #+#    #+#             */
/*   Updated: 2019/04/19 18:15:15 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type_re.h"

int			barely_zero(t_re a)
{
	return (((a < ) ? -a : a) < MARGIN_ERROR);
}

int			barely_equals(t_re a, t_re b)
{
	return (barely_zero(a - b));
}
