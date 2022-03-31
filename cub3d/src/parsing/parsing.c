/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:41:14 by hzona             #+#    #+#             */
/*   Updated: 2021/12/28 13:31:18 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static t_map	*map_init(void)
{
	t_map	*map;
	int		i;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		cub_error("Error map: malloc t_map *map");
	map->row = 0;
	map->col = 0;
	map->f_colour = -1;
	map->c_colour = -1;
	i = -1;
	while (++i < 4)
		map->wall_texture_path[i] = NULL;
	map->door_texture_path = NULL;
	i = -1;
	while (++i < 8)
		map->sprites_texture_path[i] = NULL;
	map->sprite_tex_num = 0;
	map->player_x = -1;
	map->player_y = -1;
	map->player_z = '\0';
	map->sprites_num = 0;
	map->doors_num = 0;
	map->arr = NULL;
	return (map);
}

static void	map_array_init(t_map *map)
{
	map->arr = ft_dyn_arr_mal_char(map->row, map->col);
	if (map->arr == NULL)
		cub_error("Error map: malloc map->arr");
	map->tex = (t_tex *)malloc(sizeof(t_tex) * 4);
	if (!map->tex)
		cub_error("Error maloc: map->tex");
	map->spr = (t_tex *)malloc(sizeof(t_tex) * map->sprite_tex_num);
	if (!map->spr)
		cub_error("Error maloc: map->tex");
	map->door = (t_tex *)malloc(sizeof(t_tex) * 1);
	if (!map->door)
		cub_error("Error maloc: map->door");
}

t_map	*parsing_map(char *map_file)
{
	t_map	*map;
	t_list	*head_map;

	map = map_init();
	head_map = parsing_read_map(map_file, map);
	if (!head_map)
		cub_error("Error map: malloc t_list *head_map");
	map_array_init(map);
	parsing_list_to_array(head_map, map);
	ft_lstclear(&head_map, free);
	parsing_check_map_circuit(map);
	return (map);
}
