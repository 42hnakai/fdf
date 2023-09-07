/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 23:55:35 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/07 23:55:49 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_z(char *z)
{
	if (z == NULL)
		return (0);
	else if (ft_strncmp(z, "0", ft_strlen(z)) != 0 && ft_atoi(z) == 0)
		return (-1);
	else
		return (0);
}

int	check_color(char *color)
{
	int	i;

	if (color == NULL)
		return (0);
	else if (!(color[0] == '0' && color[1] == 'x'))
		return (-1);
	else if (ft_strlen(color) < 3 || 10 < ft_strlen(color))
		return (-1);
	i = 2;
	while (color[i] != '\0')
	{
		if (!(('0' <= color[i] && color[i] <= '9')
			 ||('a' <= color[i] && color[i] <= 'f')
			 ||('A' <= color[i] && color[i] <= 'F')))
			return (-1);
		i++;
	}
	return (0);
}