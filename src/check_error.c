/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:57:39 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/05 14:49:49 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int check_valid_file(char *file_name)
{
	size_t len;
	size_t new_len;
	len = ft_strlen(file_name);
	file_name = ft_memchr(file_name, '.', len);
	if (file_name == NULL)
		return (-1);
	new_len = ft_strlen(file_name);
	if (ft_memcmp(file_name, ".fdf", new_len) == 0)
		return (0);
	else
		return (-1);
}

int check_valid_size(char *file_name)
{
	int fd;
	int x_len;
	int len;
	char *line;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file");
		exit(1);
	}
	if ((line = get_next_line(fd)) != NULL)
	{
		x_len = get_x_length(line);
		free(line);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		len = get_x_length(line);
		if (x_len != len)
		{
			free(line);
			return (-1);
		}
		free(line);
	}
	if (close(fd) == -1)
	{
		printf("Error closing file");
		exit(1);
	}
	return (0);
}

int check_valid_color(char *line)
{
	int i;
	char **info;
	char **color;

	i = 0;
	info = ft_split(line, ' ');
	while (info[i] != NULL)
	{
		color = ft_split(info[i], ',');
		if (color[1] != NULL)
		{
			printf("PASS\n");
			if (!(color[1][0] == '0' && color[1][1] == 'x'))
				return (-1);
			if (ft_strlen(color[1]) > 8)
				return (-1);
		}
		i++;
	}
	return (0);
}

int check_valid_map(char *file_name)
{
	int fd;
	char *line;

	if (check_valid_size(file_name) == -1)
	{
		printf("[ERROR!] invalid map_size\n");
		return (-1);
	}
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file");
		exit(1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		if (check_valid_color(line) == -1)
		{
			free(line);
			printf("[ERROR!] invalid color\n");
			return (-1);
		}
		free(line);
	}
	// CLOSE FD
	if (close(fd) == -1)
	{
		perror("Error closing file");
		exit(1);
	}
	return (0);
}