/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:18:03 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/23 16:24:18 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*alloc;
	char	*ptr;

	alloc = (char *)malloc(size);
	if (alloc == NULL)
		return (NULL);
	ptr = alloc;
	while (size--)
	{
		*ptr = 0;
		ptr++;
	}
	return ((void *)alloc);
}
