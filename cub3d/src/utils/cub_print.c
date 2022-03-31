/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:41:34 by hzona             #+#    #+#             */
/*   Updated: 2021/12/27 20:44:02 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	tttt_print_parsing(t_map *map)
{
	int	i;

	printf("map->wall_texture_path:\n");
	i = -1;
	while (++i < 4)
		printf("\t%d %s\n", i + 1, map->wall_texture_path[i]);
	printf("map->sprites_texture = %d:\n", map->sprite_tex_num);
	i = -1;
	while (++i < map->sprite_tex_num)
		printf("\t%d %s\n", i + 1, map->sprites_texture_path[i]);
	printf("map->door_texture_path:\n\t%s\n", map->door_texture_path);
	printf("map->f_colour = %d\n", map->f_colour);
	printf("map->c_colour = %d\n", map->c_colour);
	printf("map->player_x = %d\n", map->player_x);
	printf("map->player_y = %d\n", map->player_y);
	printf("map->player_z = %c\n", map->player_z);
	printf("sprites_num = %d\n", map->sprites_num);
	printf("doors_num = %d\n", map->doors_num);
	printf("map->col = %d\n", map->col);
	printf("map->row = %d\n", map->row);
}

void	tttt_print_map(t_map *map)
{
	int		x;
	int		y;

	printf("\n");
	y = 0;
	while (y < map->row)
	{
		x = 0;
		while (x < map->col)
		{
			printf("%c", map->arr[y][x]);
			x++;
		}
		printf("$\n");
		y++;
	}
}
