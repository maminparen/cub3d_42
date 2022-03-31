/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_list_to_array.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:37:52 by hzona             #+#    #+#             */
/*   Updated: 2021/12/27 20:37:53 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	parsing_arr_row(int y, char *line, t_map *map)
{
	int	x;

	x = 0;
	while (*line)
	{
		if (*line >= '0' && *line <= '1')
			map->arr[y][x] = *line;
		else if (*line == ' ')
			map->arr[y][x] = ' ';
		else if (*line == 'D')
			map->arr[y][x] = *line;
		else if (*line >= '2' && *line <= '2' + map->sprite_tex_num)
			map->arr[y][x] = *line;
		else if (*line >= 'N' || *line >= 'S' || *line >= 'W' || *line >= 'E')
			map->arr[y][x] = '0';
		else
			cub_error("Error map: wrong symbol in map");
		line++;
		x++;
	}
	while (x < map->col)
	{
		map->arr[y][x] = ' ';
		x++;
	}
}

void	parsing_list_to_array(t_list *head, t_map *map)
{
	int	y;

	y = 0;
	while (head)
	{
		parsing_arr_row(y, head->content, map);
		head = head->next;
		y++;
	}
}
