/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 19:19:04 by hnakai            #+#    #+#             */
/*   Updated: 2023/08/24 20:09:01 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map_info **get_z_axis(t_map_info **map_info, char *line)
{
	int		i;
	int		j;
	char	**splits;

	i = 0;
	j = 0;
	splits = ft_split(line, ' ');
	map_info[i][j].z_axis = ft_atoi(splits[i][0]);
	return (map_info);
}

t_map_info **get_map_info()
{
	int fd;
	char *line;
	int i;
	int j;

	i = 0;
	j = 0;
	t_map_info **map_info;

	// "10-2.fdf" ファイルを開く
	fd = open("10-2.fdf", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		exit(1);
	}
	// get_next_lineを使ってファイルから一行ずつ読み込み、それを表示する
	while ((line = get_next_line(fd)) != NULL)
	{
		get_z_axis(line);
		free(line);
		j++;
	}
	// ファイルディスクリプタを閉じる
	if (close(fd) == -1)
	{
		perror("Error closing file");
		exit(1);
	}
	return (map_info);
}