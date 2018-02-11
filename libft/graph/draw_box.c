/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 19:42:11 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/23 19:14:34 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "box.h"
#include "graphics.h"
#include "libft.h"

unsigned int	*img_box_mask(t_mlx m, unsigned int *img_data, t_box mask,
															unsigned int color)
{
	unsigned int	*new_data;
	int				x;
	int				y;
	size_t			N;

	N = m.win.width * m.win.height * sizeof(*img_data);
	new_data = (unsigned int*)malloc(N);
	ft_memcpy(new_data, img_data, N);
	y = mask.y_min;
	while (y <= mask.y_max)
	{
		new_data[y * m.win.width + mask.x_min] = color;
		if (y == mask.y_min || y == mask.y_max)
		{
			x = mask.x_min;
			while (++x < mask.x_max)
				new_data[y * m.win.width + x] = color;
		}
		new_data[y * m.win.width + mask.x_max] = color;
		y++;
	}
	return (new_data);
}
