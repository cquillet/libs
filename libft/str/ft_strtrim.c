/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:09:07 by cquillet          #+#    #+#             */
/*   Updated: 2016/11/10 02:17:49 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*alloc;
	long	i;
	long	j;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	j = i;
	while (s[j])
		j++;
	while (j > i && (s[j - 1] == ' ' || s[j - 1] == '\t' || s[j - 1] == '\n'))
		j--;
	alloc = (char *)malloc((j - i + 1) * sizeof(char));
	if (alloc == NULL)
		return (NULL);
	alloc[j - i] = '\0';
	while (j--)
		alloc[j - i] = s[j];
	return (alloc);
}
