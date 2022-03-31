/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_map_circuit.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:37:47 by hzona             #+#    #+#             */
/*   Updated: 2021/12/27 20:37:48 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	parsing_check_map_circuit(t_map *map)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->row)
	{
		x = 0;
		while (x < map->col)
		{
			if (map->arr[y][x] != '1' && map->arr[y][x] != ' ' && \
					(x == 0 || y == 0 || \
					x == map->col - 1 || y == map->row - 1 || \
					map->arr[y - 1][x] == ' ' || \
					map->arr[y + 1][x] == ' ' || \
					map->arr[y][x - 1] == ' ' || \
					map->arr[y][x + 1] == ' ' || \
					map->arr[y - 1][x - 1] == ' ' || \
					map->arr[y - 1][x + 1] == ' ' || \
					map->arr[y + 1][x - 1] == ' ' || \
					map->arr[y + 1][x + 1] == ' '))
				cub_error("Error map: wrong map circuit");
			x++;
		}
		y++;
	}
}
