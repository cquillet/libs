/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 21:05:59 by cquillet          #+#    #+#             */
/*   Updated: 2018/02/10 17:57:21 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		display_ptr(va_list ap, t_format *f)
{
	get_ptr(ap, f);
	return ((f->left) ? complete_nb_left(f) : complete_nb_right(f));
}
