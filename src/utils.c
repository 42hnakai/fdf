/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:59:13 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/06 21:37:59 by hnakai           ###   ########.fr       */
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
	printf("%s", massage);
	return (-1);
}

void check_fd(int fd)
{
	if (fd == -1)
	{
		printf("[ERROR!] missing to open file!\n");
		exit(1);
	}
}

void check_close(int fd)
{
	if (close(fd) == -1)
	{
		printf("[ERROR!] missing to close file!\n");
		exit(1);
	}
}
