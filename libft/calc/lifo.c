/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:52:36 by cquillet          #+#    #+#             */
/*   Updated: 2017/11/03 20:09:10 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lifo.h"

t_lifo		create_lifo()
{
	t_lifo	l;

	l.len = 0;
	l.head = NULL;
	return (l);
}

t_lifo		*lifo_push(t_lifo *s, t_list *e)
{
	if (!e)
		return (s);
	if (!s)
		*s = create_lifo();
	e->next = s->head;
	s->head = e;
	s->len++;
	return (s);
}

t_list		*lifo_pop(t_lifo *s)
{
	t_list	*e;

	if (!s->len || !s)
		return (NULL);
	e = s->head;
	s->head = s->head->next;
	s->len--;
	return (e);
}

int			lifo_empty(t_lifo s)
{
	return (!s.len);
}

t_list		*lifo_top(t_lifo s)
{
	return (s.head);
}

t_lifo		*lifo_swap(t_lifo *s)
{
	t_list	*first;

	if (!s || s->len < 2)
		return (NULL);
	first = s->head;
	first->next = s->head->next->next;
	s->head = s->head->next;
	s->head->next = first;
	return (s);
}
