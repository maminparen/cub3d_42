/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:39:18 by hzona             #+#    #+#             */
/*   Updated: 2021/12/27 20:41:06 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	parsing_check_texture_main(char *s)
{
	if ((s[0] == 'N' && s[1] == 'O' && s[2] == ' ') || \
		(s[0] == 'S' && s[1] == 'O' && s[2] == ' ') || \
		(s[0] == 'W' && s[1] == 'E' && s[2] == ' ') || \
		(s[0] == 'E' && s[1] == 'A' && s[2] == ' ') || \
		(s[0] == 'F' && s[1] == ' ') || \
		(s[0] == 'C' && s[1] == ' '))
	{
		return (1);
	}
	return (0);
}

static int	parsing_check_texture_sprite(char *s, t_map *map)
{
	if ((s[0] == 'S' && s[1] == '0' && s[2] == ' '
			&& map->sprite_tex_num == 0) || (s[0] == 'S'
			&& s[1] == '1' && s[2] == ' ' && map->sprite_tex_num == 1) || \
			(s[0] == 'S' && s[1] == '2' && s[2] == ' ' && map->sprite_tex_num \
			== 2) || (s[0] == 'S' && s[1] == '3' && s[2] == ' '
			&& map->sprite_tex_num == 3) || (s[0] == 'S' && s[1] == '4' && s[2] \
			== ' ' && map->sprite_tex_num == 4) || (s[0] == 'S' && s[1] == '5' \
			&& s[2] == ' ' && map->sprite_tex_num == 5) || (s[0] == 'S' && s[1] \
			== '6' && s[2] == ' ' && map->sprite_tex_num == 6) || \
		(s[0] == 'S' && s[1] == '7' && s[2] == ' ' && map->sprite_tex_num == 7))
	{
		map->sprite_tex_num += 1;
		return (1);
	}
	else if (s[0] == 'D' && s[1] == ' ')
	{
		return (1);
	}
	return (0);
}

int	parsing_texture(char *s, t_map *map)
{
	while (*s && (*s == ' ' || *s == '\t'))
		s++;
	if (parsing_check_texture_main(s))
		parsing_texture_main(ft_split(s, ' '), map);
	else if (parsing_check_texture_sprite(s, map))
		parsing_texture_sprite(ft_split(s, ' '), map);
	else
	{
		if (map->wall_texture_path[0] && \
			map->wall_texture_path[1] && \
			map->wall_texture_path[2] && \
			map->wall_texture_path[3] && \
			map->f_colour != -1 && \
			map->c_colour != -1)
			return (0);
		else
			cub_error("Error map: miss texture path");
	}	
	return (1);
}
