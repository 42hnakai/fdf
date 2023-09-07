/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:14:03 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/07 18:47:11 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// GET COLOR ELEMENT
t_color_elem get_col_elem(int color)
{
	t_color_elem color_elem;
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
t_color_elem get_col_diff(t_color_elem color_elem1, t_color_elem color_elem2)
{
	t_color_elem color_diff;
	color_diff.g = color_elem2.b - color_elem1.b;
	color_diff.b = color_elem2.g - color_elem1.g;
	color_diff.r = color_elem2.r - color_elem1.r;
	color_diff.t = color_elem2.t - color_elem1.t;
	return (color_diff);
}

// ADD COLOR
int add_col(t_color_elem color_elem, t_color_elem color_diff, double percent)
{
	int add_color;
	add_color = 0;
	color_elem.b += color_diff.b * percent;
	color_elem.g += color_diff.g * percent;
	color_elem.r += color_diff.r * percent;
	color_elem.t += color_diff.t * percent;
	// printf("add_color : %X\n",add_color);
	add_color += color_elem.b;
	add_color += color_elem.g * 256;
	add_color += color_elem.r * 256 * 256;
	add_color += color_elem.t * 256 * 256 * 256;
	return (add_color);
}
