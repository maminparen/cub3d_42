/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture_sprite.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:39:12 by hzona             #+#    #+#             */
/*   Updated: 2021/12/27 20:39:13 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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

void	parsing_texture_sprite(char **split_line, t_map *map)
{
	if (!split_line)
		cub_error("Error split: in parsing identifier");
	if (ft_strcmp(split_line[0], "D") == 0)
		parsing_tex(split_line, &map->door_texture_path);
	else if (**split_line == 'S')
		parsing_tex(split_line, \
						&map->sprites_texture_path[map->sprite_tex_num - 1]);
	ft_free_split(split_line);
}
