/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:47:33 by cquillet          #+#    #+#             */
/*   Updated: 2017/11/03 20:09:28 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIFO_H
# define LIFO_H

# include "libft.h"
# include "unistd.h"

typedef struct		s_lifo
{
	size_t			len;
	struct s_list	*head;
}					t_lifo;


t_lifo		create_lifo();
t_lifo		*lifo_push(t_lifo *s, t_list *e);
t_list		*lifo_pop(t_lifo *s);
int			lifo_empty(t_lifo s);
t_list		*lifo_top(t_lifo s);
t_lifo		*lifo_swap(t_lifo *s);

#endif
