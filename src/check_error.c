/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:57:39 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/07 18:15:52 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int check_file(int argc, char *file_name)
{
	if (argc != 2)
	{
		display_error("[ERROR!] no files!\n");
		return (-1);
	}
	size_t len;
	size_t new_len;
	len = ft_strlen(file_name);
	file_name = ft_memchr(file_name, '.', len);
	if (file_name == NULL)
	{
		display_error("[ERROR!] invalid file!\n");
		return (-1);
	}
	new_len = ft_strlen(file_name);
	if (ft_memcmp(file_name, ".fdf", new_len) != 0)
	{
		display_error("[ERROR!] invalid file!\n");
		return (-1);
	}
	else
		return (0);
}

int check_valid_size(char **elems_ary, int flag)
{
	static int x_len;
	int len;

	if (flag == 0)
		x_len = get_x_length(elems_ary);
	len = get_x_length(elems_ary);
	if (x_len != len)
	{
		free(elems_ary);
		return (-1);
	}
	return (0);
}

int check_z(char *z)
{
	if (z == NULL)
		return (0);
	else if (ft_strncmp(z, "0", ft_strlen(z)) != 0 && ft_atoi(z) == 0)
		return (-1);
	else
		return (0);
}

int check_color(char *color)
{
	int i;

	if (color == NULL)
		return (0);
	else if (!(color[0] == '0' && color[1] == 'x'))
		return (-1);
	else if (ft_strlen(color) < 3 || 10 < ft_strlen(color))
		return (-1);
	i = 2;
	while (color[i] != '\0')
	{
		if (!(('0' <= color[i] && color[i] <= '9') || ('a' <= color[i] && color[i] <= 'f') ||
			  ('A' <= color[i] && color[i] <= 'F')))
			return (-1);
		i++;
	}
	return (0);
}

int check_z_color(char **elems_ary)
{
	int i;
	char **z_color_ary;
	char *color;
	char *z;

	i = 0;
	while (elems_ary[i] != NULL)
	{
		z_color_ary = ft_split(elems_ary[i], ',');
		z = z_color_ary[0];
		if (check_z(z) == -1)
		{
			printf("[ERROR!] invalid z!\n");
			return (-1);
		}
		color = z_color_ary[1];
		if (check_color(color) == -1)
		{
			printf("[ERROR!] invalid color!\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

int check_valid_map(char *file_name)
{
	int fd;
	int i;
	char *line;
	char **elems_ary;

	i = 0;
	fd = open(file_name, O_RDONLY);
	check_fd(fd);
	while ((line = get_next_line(fd)) != NULL)
	{
		line = ft_strtrim(line, "\n");
		elems_ary = ft_split(line, ' ');
		if (check_valid_size(elems_ary, i) == -1)
		{
			printf("[ERROR!] invalid map_size\n");
			return (-1);
		}
		if (check_z_color(elems_ary) == -1)
			return (-1);
		else
			free(line);
		i++;
	}
	check_fd(fd);
	return (0);
}
