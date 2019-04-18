/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:18:25 by cquillet          #+#    #+#             */
/*   Updated: 2019/04/02 16:18:35 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUATERNION_H
# define QUATERNION_H

# ifndef TYPEDEF_CPLX
#  define TYPEDEF_CPLX

typedef long double t_re;

# endif

typedef struct	s_quat
{
	t_re		r;
	union {
		t_re	i;
		t_re	g;
	};
	union {
		t_re	j;
		t_re	b;
	};
	union {
		t_re	k;
		t_re	a;
	};
}				t_quat;

t_quat			quat_conj(t_quat x);
t_re			quat_mod(t_quat x);
t_quat			quat_scalar(t_quat x, t_re a);
t_quat			quat_inv(t_quat x);

t_quat			quat_add(t_quat x, t_quat y);
t_quat			quat_mul(t_quat x, t_quat y);
t_quat			quat_div(t_quat x, t_quat y);

void			quat_print(t_quat q);

#endif
