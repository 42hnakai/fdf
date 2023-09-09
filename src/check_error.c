/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:57:39 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/09 18:30:16 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_file(int argc, char *file_name)
{
	size_t	len;
	size_t	new_len;

	if (argc != 2)
	{
		ft_printf("[ERROR!] no files!\n");
		return (-1);
	}
	len = ft_strlen(file_name);
	file_name = ft_memchr(file_name, '.', len);
	if (file_name == NULL)
	{
		ft_printf("[ERROR!] invalid file!\n");
		return (-1);
	}
	new_len = ft_strlen(file_name);
	if (ft_memcmp(file_name, ".fdf", new_len) != 0)
	{
		ft_printf("[ERROR!] invalid file!\n");
		return (-1);
	}
	else
		return (0);
}

int	check_valid_size(char **elems_ary, int flag)
{
	static int	x_len;
	int			len;

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

int	check_z_color(char **elems_ary)
{
	int		i;
	char	**z_color_ary;
	char	*color;
	char	*z;

	i = 0;
	while (elems_ary[i] != NULL)
	{
		z_color_ary = ft_split(elems_ary[i], ',');
		z = z_color_ary[0];
		if (check_z(z) == -1)
		{
			ft_printf("[ERROR!] invalid z!\n");
			return (-1);
		}
		color = z_color_ary[1];
		if (check_color(color) == -1)
		{
			ft_printf("[ERROR!] invalid color!\n");
			return (-1);
		}
		i++;
	}
	// free_double_char_n(elems_ary,get_x_length(elems_ary));
	return (0);
}

int	check_valid_map(char *file_name)
{
	int		fd;
	int		i;
	char	*line;
	char	**elems_ary;

	i = 0;
	fd = open(file_name, O_RDONLY);
	check_fd(fd);
	while ((line = get_next_line(fd)) != NULL)
	{
		line = ft_strtrim(line, "\n");
		elems_ary = ft_split(line, ' ');
		free(line);
		if (check_valid_size(elems_ary, i) == -1)
		{
			free_double_char_n(elems_ary,get_x_length(elems_ary));
			ft_printf("[ERROR!] invalid map_size\n");
			return (-1);
		}
		if (check_z_color(elems_ary) == -1)
			return (-1);
		else
			free_double_char_n(elems_ary,get_x_length(elems_ary));
		i++;
	}
	check_fd(fd);
	return (0);
}
