/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 20:24:24 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/18 14:57:55 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_H
# define GRAPH_H

typedef struct		s_node
{
	char			*name;
	int				id;
	void			*data;
}					t_node;

typedef struct		s_graph
{
	unsigned int	N;
	t_node			*nodes;
	void			**edges;
	char			directed;
}					t_graph;

/*
The basic operations provided by a graph data structure G usually include:[1]

adjacent(G, x, y): tests whether there is an edge from the vertex x to the vertex y;
neighbors(G, x): lists all vertices y such that there is an edge from the vertex x to the vertex y;
add_vertex(G, x): adds the vertex x, if it is not there;
remove_vertex(G, x): removes the vertex x, if it is there;
add_edge(G, x, y): adds the edge from the vertex x to the vertex y, if it is not there;
remove_edge(G, x, y): removes the edge from the vertex x to the vertex y, if it is there;
get_vertex_value(G, x): returns the value associated with the vertex x;
set_vertex_value(G, x, v): sets the value associated with the vertex x to v.
						   Structures that associate values to the edges usually also provide:[1]

											 get_edge_value(G, x, y): returns the value associated with the edge (x, y);
											 set_edge_value(G, x, y, v): sets the value associated with the edge (x, y) to v.
*/

#endif
