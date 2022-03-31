/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture_main.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:39:08 by hzona             #+#    #+#             */
/*   Updated: 2021/12/27 20:39:09 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	check_pars_color(char *color)
{
	int	num;

	num = 0;
	while (*color)
	{
		num = num * 10 + *color - '0';
		if (!ft_isdigit(*color) || num > 255)
			return (0);
		color++;
	}
	return (1);
}

static void	parsing_color(char **s, int *tmp)
{
	char	**color;

	if (*tmp != -1)
		cub_error("Error map: double color floor or celling");
	if (s[2])
		cub_error("Error map: wrong color format in file");
	color = ft_split(s[1], ',');
	if (!color)
		cub_error("Error split: in parsing color");
	if (color[3])
		cub_error("Error map: wrong color format in file");
	if (check_pars_color(color[0]) && \
		check_pars_color(color[1]) && \
		check_pars_color(color[2]))
	{
		*tmp = (ft_atoi(color[0]) & 0xff) + \
				((ft_atoi(color[1]) & 0xff) << 8) + \
				((ft_atoi(color[2]) & 0xff) << 16);
	}
	else
		cub_error("Error map: wrong color");
	ft_free_split(color);
}

static void	parsing_tex(char **s, char **texture)
{
	if (*texture)
		cub_error("Error map : double texture");
	else if (s[2])
		cub_error("Error map: wrong texture format in file");
	else if (access(s[1], F_OK) == -1)
		cub_error("Error map: no textures in folder");
	else if (access(s[1], R_OK) == -1)
		cub_error("Error map: cannot read file");
	else
		*texture = ft_strdup(s[1]);
}

void	parsing_texture_main(char **split_line, t_map *map)
{
	if (!split_line)
		cub_error("Error map: malloc split texture_main");
	if (ft_strcmp(split_line[0], "NO") == 0)
		parsing_tex(split_line, &map->wall_texture_path[0]);
	else if (ft_strcmp(split_line[0], "SO") == 0)
		parsing_tex(split_line, &map->wall_texture_path[1]);
	else if (ft_strcmp(split_line[0], "WE") == 0)
		parsing_tex(split_line, &map->wall_texture_path[2]);
	else if (ft_strcmp(split_line[0], "EA") == 0)
		parsing_tex(split_line, &map->wall_texture_path[3]);
	else if (ft_strcmp(split_line[0], "F") == 0)
		parsing_color(split_line, &map->f_colour);
	else if (ft_strcmp(split_line[0], "C") == 0)
		parsing_color(split_line, &map->c_colour);
	ft_free_split(split_line);
}
