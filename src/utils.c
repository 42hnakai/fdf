/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:59:13 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/05 18:59:53 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void free_double(t_map_info **map_info, int i)
{
	free(map_info);
	while (i > 0)
	{
		free(map_info[i - 1]);
		i--;
	}
}

int display_error(char *massage)
{
	printf("%s\n", massage);
	return (-1);
}
