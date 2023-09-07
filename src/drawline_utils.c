/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 23:40:19 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/07 23:40:33 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line_params	get_params(double x1, double x2, double y1, double y2)
{
	double			diff_x;
	double			diff_y;
	t_line_params	line_params;

	diff_x = x2 - x1;
	diff_y = y2 - y1;
	line_params.slope = diff_y / diff_x;
	line_params.intercept = y1 - line_params.slope * x1;
	return (line_params);
}

int	get_x(int y, t_line_params line_params)
{
	return ((int)((y - line_params.intercept) / line_params.slope));
}

int	get_y(int x, t_line_params line_params)
{
	return ((int)(line_params.slope * x + line_params.intercept));
}

double	get_dist(double x1, double x2, double y1, double y2)
{
	double	x_diff;
	double	y_diff;
	double	dist;

	x_diff = x2 - x1;
	y_diff = y2 - y1;
	dist = sqrt(x_diff * x_diff + y_diff * y_diff);
	return (dist);
}
