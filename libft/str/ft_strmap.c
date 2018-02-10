/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:37:20 by cquillet          #+#    #+#             */
/*   Updated: 2016/11/15 20:59:55 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*alloc;
	size_t	i;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	alloc = (char *)malloc((i + 1) * sizeof(char));
	if (alloc == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		alloc[i] = (*f)(s[i]);
		i++;
	}
	alloc[i] = '\0';
	return (alloc);
}
