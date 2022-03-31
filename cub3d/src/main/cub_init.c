/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:15:43 by hzona             #+#    #+#             */
/*   Updated: 2021/12/27 21:56:10 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	init_texture(t_cub3d *cub, t_map *map)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		map->tex[i].ptr = \
			mlx_xpm_file_to_image(cub->mlx, map->wall_texture_path[i], \
			&map->tex[i].width, &map->tex[i].height);
		if (!map->tex[i].ptr)
			cub_error("Error cub->map->tex[i].ptr");
		map->tex[i].data = (int *)mlx_get_data_addr(map->tex[i].ptr, \
			&map->tex[i].bpp, &map->tex[i].size_l, &map->tex[i].endian);
		if (!map->tex[i].data)
			cub_error("Error cub->map->tex[i].data");
	}
}

static void	init_sprite(t_cub3d *cub, t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->sprite_tex_num)
	{
		map->spr[i].ptr = \
			mlx_xpm_file_to_image(cub->mlx, map->sprites_texture_path[i], \
			&map->spr[i].width, &map->spr[i].height);
		if (!map->spr[i].ptr)
			cub_error("Error cub->map->spr[i].ptr");
		map->spr[i].data = (int *)mlx_get_data_addr(map->spr[i].ptr, \
			&map->spr[i].bpp, &map->spr[i].size_l, &map->spr[i].endian);
		if (!map->spr[i].data)
			cub_error("Error cub->map->spr[i].data");
	}
	map->door->ptr = \
		mlx_xpm_file_to_image(cub->mlx, map->door_texture_path, \
		&map->door->width, &map->door->height);
	if (!map->door->ptr)
		cub_error("Error cub->map->door->ptr");
	map->door->data = (int *)mlx_get_data_addr(map->door->ptr, \
		&map->door->bpp, &map->door->size_l, &map->door->endian);
	if (!map->door->data)
		cub_error("Error cub->map->door->data");
}

static t_player	*player_init(t_map *map, int width)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
		cub_error("Error maloc: t_player *player");
	player->x = map->player_x + 0.5;
	player->y = map->player_y + 0.5;
	if (map->player_z == 'N')
		player->angle = 90;
	else if (map->player_z == 'S')
		player->angle = 270;
	else if (map->player_z == 'W')
		player->angle = 180;
	else if (map->player_z == 'E')
		player->angle = 0;
	player->view = 60;
	player->movespeed = 0.1;
	player->rotspeed = 1.5;
	player->zbuffer = (double *)malloc(sizeof(double) * width);
	if (!player->zbuffer)
		cub_error("Error maloc: player->zbuffer");
	player->spr = NULL;
	player->door = NULL;
	return (player);
}

t_cub3d	*cub_init(char *map_file)
{
	t_cub3d	*cub;

	cub = (t_cub3d *)malloc(sizeof(t_cub3d));
	if (!cub)
		cub_error("Error malloc: t_cub3d *cub");
	cub->map = parsing_map(map_file);
	cub->mlx_width = 1280;
	cub->mlx_height = 720;
	cub->mouse = 0;
	cub->player = player_init(cub->map, cub->mlx_width);
	cub->mlx = mlx_init(cub->map);
	init_texture(cub, cub->map);
	init_sprite(cub, cub->map);
	cub->mlx_win = mlx_new_window(cub->mlx, \
		cub->mlx_width, cub->mlx_height, "cub3D");
	cub->img.img = mlx_new_image(cub->mlx, cub->mlx_width, cub->mlx_height);
	cub->img.addr = (int *)mlx_get_data_addr(cub->img.img, \
		&cub->img.bits_per_pixel, &cub->img.line_length, &cub->img.endian);
	return (cub);
}
