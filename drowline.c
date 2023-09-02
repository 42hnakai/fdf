/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drowline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:33:25 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/02 13:49:42 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// WANT TO CHANGE FUNC NAME TO "GET_LINE_PARAMS"
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

int get_x(int y, t_line_params line_params)
{
	return ((int)((y - line_params.intercept) / line_params.slope));
}

int get_y(int x, t_line_params line_params)
{
	return ((int)(line_params.slope * x + line_params.intercept));
}

void ft_swap(double *a, double *b)
{
	double c;
	c = *a;
	*a = *b;
	*b = c;
}

void drowline(double x1, double x2, double y1, double y2, t_data img)
{
	int x;
	int y;
	t_line_params line_params;

	if (x1 == x2)
	{
		if (y2 < y1)
		{
			ft_swap(&y1, &y2);
		}
		y = y1 + 1;
		while (y1 <= y && y <= y2)
		{
			my_mlx_pixel_put(&img, x1, y, 0x00FFFF);
			y++;
		}
	}
	else if (y1 == y2)
	{
		if (x2 < x1)
		{
			ft_swap(&x1, &x2);
		}
		x = x1 + 1;
		while (x1 <= x && x <= x2)
		{
			my_mlx_pixel_put(&img, x, y1, 0x00FF0000);
			x++;
		}
	}
	else
	{
		line_params = make_line_wq(x1, x2, y1, y2);
		if (x2 < x1)
		{
			ft_swap(&x1, &x2);
		}
		x = x1 + 1;
		while (x1 <= x && x <= x2)
		{
			y = get_y(x, line_params);
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			x++;
		}
		if (y2 < y1)
		{
			ft_swap(&y1, &y2);
		}
		y = y1 + 1;
		while (y1 <= y && y <= y2)
		{
			x = get_x(y, line_params);
			my_mlx_pixel_put(&img, x, y, 0x00FFFF);
			y++;
		}
	}
}
