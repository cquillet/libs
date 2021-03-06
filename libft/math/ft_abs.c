/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 20:29:38 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/23 17:16:50 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_abs(int a)
{
	return (a < 0 ? -a : a);
}

t_re		ft_absf(t_re a)
{
	return (a < 0. ? -a : a);
}
