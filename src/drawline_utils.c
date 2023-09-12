/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 23:40:19 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/12 22:53:12 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	help_drawline(t_map_info start, t_map_info end,
		t_line_params line_params, t_data img)
{
	if (start.x == end.x)
	{
		if (start.y < end.y)
			draw_yline(start, end, img);
		else
			draw_yline(end, start, img);
	}
	else if (start.x < end.x)
		drawline_by_x(start, end, line_params, img);
	else
		drawline_by_x(end, start, line_params, img);
	if (start.y == end.y)
	{
		if (start.x < end.x)
			draw_xline(start, end, img);
		else
			draw_xline(end, start, img);
	}
	else if (start.y < end.y)
		drawline_by_y(start, end, line_params, img);
	else
		drawline_by_y(end, start, line_params, img);
}

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
