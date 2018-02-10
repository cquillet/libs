/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:47:06 by cquillet          #+#    #+#             */
/*   Updated: 2016/11/10 02:48:36 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*alloc;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	alloc = (char *)malloc((len + 1) * sizeof(char));
	if (alloc == NULL)
		return (NULL);
	i = 0;
	while (s[i] && i < start)
		i++;
	j = 0;
	while (s[i + j] && j < len)
	{
		alloc[j] = s[i + j];
		j++;
	}
	alloc[j] = '\0';
	return (alloc);
}
