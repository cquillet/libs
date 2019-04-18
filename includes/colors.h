/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 10:50:44 by cquillet          #+#    #+#             */
/*   Updated: 2019/04/04 16:04:49 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# include "int_2d.h"
# include "float_2f.h"

# ifndef INTENSITY_MAX
#  define INTENSITY_MAX 0xFF
# endif

# ifndef GAMMA_KORR
#  define GAMMA_KORR 0.8
# endif

# ifndef BASIC_COLORS
#  define BASIC_COLORS
#  define WHITE 0xFFFFFF
#  define DARK_OCEAN 0x006699
#  define PALE_OCEAN 0x00FFFF
#  define GREEN_LAND 0x00CD00
#  define BROWN_MOUTAIN 0x660000
# endif

typedef union			u_col
{
	unsigned int		rgba;
	struct
	{
		unsigned char	b;
		unsigned char	g;
		unsigned char	r;
		unsigned char	a;
	};
}						t_col;

unsigned int	color_from_wavelength(double wavelength);

unsigned int	spectrum_color(int value, int min, int max);
unsigned int	spectrum_gray(int value, int min, int max);
unsigned int	rgb_darker(unsigned int color, int value, int start, int black);
unsigned int	rgb_lighter(unsigned int color, int value, int start,
																	int white);
unsigned int	rgb_between(int value, t_2d start_end,
							unsigned int color_start, unsigned int color_end);

unsigned int	rgb_sea(int z, int zmin, int zmax);
unsigned int	rgb_land(int z, int zmin, int zmax);
unsigned int	rgb_earth(int z, int zmin, int zmax);

unsigned int	spectrum_colorf(t_re value, t_re min, t_re max);
unsigned int	spectrum_grayf(t_re value, t_re min, t_re max);
unsigned int	rgb_darkerf(unsigned int color, t_re value, t_re start,
																	t_re black);
unsigned int	rgb_lighterf(unsigned int color, t_re value, t_re start,
																	t_re white);
unsigned int	rgb_betweenf(t_re value, t_2f start_end,
							unsigned int color_start, unsigned int color_end);

#endif
