/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:14:03 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/12 20:54:19 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// GET COLOR ELEMENT
t_color_elems	get_col_elem(int color)
{
	t_color_elems	color_elem;

	color_elem.b = color % 256;
	color = color / 256;
	color_elem.g = color % 256;
	color = color / 256;
	color_elem.r = color % 256;
	color = color / 256;
	color_elem.t = color % 256;
	return (color_elem);
}

// GET COLOR DIFFERENCE
t_color_elems	get_col_diff(int color1, int color2)
{
	t_color_elems	color1_elem;
	t_color_elems	color2_elem;
	t_color_elems	color_diff;

	color1_elem = get_col_elem(color1);
	color2_elem = get_col_elem(color2);
	color_diff.g = color2_elem.b - color1_elem.b;
	color_diff.b = color2_elem.g - color1_elem.g;
	color_diff.r = color2_elem.r - color1_elem.r;
	color_diff.t = color2_elem.t - color1_elem.t;
	return (color_diff);
}

// ADD COLOR
int	add_col(int color, t_color_elems color_diff, double percent)
{
	int				add_color;
	t_color_elems	color_elem;

	add_color = 0;
	color_elem = get_col_elem(color);
	color_elem.b += color_diff.b * percent;
	color_elem.g += color_diff.g * percent;
	color_elem.r += color_diff.r * percent;
	color_elem.t += color_diff.t * percent;
	add_color += color_elem.b;
	add_color += color_elem.g * 256;
	add_color += color_elem.r * 256 * 256;
	add_color += color_elem.t * 256 * 256 * 256;
	return (add_color);
}
