/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drowline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:33:25 by hnakai            #+#    #+#             */
/*   Updated: 2023/08/29 23:15:19 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line_params make_line_wq(double x1, double x2, double y1, double y2)
{
	double diff_x;
	double diff_y;
	t_line_params line_params;

	diff_x = x2 - x1;
	diff_y = y2 - y1;
	line_params.slope = diff_y / diff_x;
	line_params.intercept = y1 - line_params.slope * x1;
	return (line_params);
}

int get_y(int x, t_line_params line_params)
{
	return ((int)line_params.slope * x + line_params.intercept);
}

void drowline(double x1, double x2, double y1, double y2, t_data img)
{
	int x;
	int y;
	t_line_params line_params;

	x = x1;
	y = y1;
	if (x1 == x2)
	{
		while (y1 <= y && y <= y2)
		{
			my_mlx_pixel_put(&img, x1, y, 0x00FF0000);
			y++;
		}
	}
	else if (y1 == y2)
	{
		while (x1 <= x && x <= x2)
		{
			my_mlx_pixel_put(&img, x, y1, 0x00FF0000);
			x++;
		}
	}
	else
	{
		line_params = make_line_wq(x1, x2, y1, y2);
		while (x1 <= x && x <= x2)
		{
			y = get_y(x, line_params);
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			x++;
		}
	}
}