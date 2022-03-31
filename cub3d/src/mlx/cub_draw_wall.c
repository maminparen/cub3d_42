/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:36:32 by hzona             #+#    #+#             */
/*   Updated: 2021/12/27 21:56:16 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_find_step_and_sidedist(t_cub3d *cub, t_draw *draw)
{
	draw->cos = cos(draw->angle * PI / 180);
	draw->sin = sin(draw->angle * PI / 180);
	draw->deltadistx = 1 / fabs(draw->cos);
	draw->deltadisty = 1 / fabs(draw->sin);
	draw->mapy = (int)cub->player->y;
	draw->mapx = (int)cub->player->x;
	draw->stepy = -1;
	if (draw->sin > 0)
		draw->sidedisty = (cub->player->y - draw->mapy) * draw->deltadisty;
	else
	{
		draw->stepy = 1;
		draw->sidedisty = (draw->mapy + 1 - cub->player->y) * draw->deltadisty;
	}
	draw->stepx = 1;
	if (draw->cos > 0)
		draw->sidedistx = (draw->mapx + 1 - cub->player->x) * draw->deltadistx;
	else
	{
		draw->stepx = -1;
		draw->sidedistx = (cub->player->x - draw->mapx) * draw->deltadistx;
	}
}

void	draw_find_hit_wall(t_cub3d *cub, \
		t_map *map, t_draw *draw, t_player *player)
{
	draw->hit = 0;
	draw->door = 0;
	draw->side = 0;
	while (draw->hit == 0 && draw->door == 0)
	{
		if (draw->sidedistx < draw->sidedisty)
		{
			draw->sidedistx += draw->deltadistx;
			draw->mapx += draw->stepx;
			draw->side = 0;
		}
		else
		{
			draw->sidedisty += draw->deltadisty;
			draw->mapy += draw->stepy;
			draw->side = 1;
		}
		if (map->arr[draw->mapy][draw->mapx] == '1')
			draw->hit = 1;
		if (map->arr[draw->mapy][draw->mapx] > '1' && \
			map->arr[draw->mapy][draw->mapx] <= '1' + map->sprite_tex_num)
			cub_check_sprite(cub, map, draw, player);
		if (map->arr[draw->mapy][draw->mapx] == 'D' && draw->door == 0)
			draw->door = 1;
	}
}

void	draw_find_perpwalldist_wallx(t_cub3d *cub, t_draw *draw)
{
	if (draw->side == 0)
		draw->perpwalldist = (draw->sidedistx - draw->deltadistx) \
			* cos((cub->player->angle - draw->angle) * PI / 180);
	else
		draw->perpwalldist = (draw->sidedisty - draw->deltadisty) \
			* cos((cub->player->angle - draw->angle) * PI / 180);
	draw->lineheight = (int)(cub->mlx_height / draw->perpwalldist \
		/ tan(cub->player->view / 2 * PI / 180));
	if (draw->side == 0)
		draw->wallx = \
			cub->player->y - (draw->sidedistx - draw->deltadistx) * draw->sin;
	else
		draw->wallx = \
			cub->player->x + (draw->sidedisty - draw->deltadisty) * draw->cos;
	draw->wallx -= floor((draw->wallx));
	draw->drawstart = -draw->lineheight / 2 + cub->mlx_height / 2;
	if (draw->drawstart < 0)
		draw->drawstart = 0;
	draw->drawend = draw->lineheight / 2 + cub->mlx_height / 2;
	if (draw->drawend >= cub->mlx_height)
		draw->drawend = cub->mlx_height - 1;
}

void	cub_draw_wall(t_cub3d *cub)
{
	t_draw	draw;

	draw.angle_start = cub->player->angle + cub->player->view / 2;
	draw.angle_end = cub->player->angle - cub->player->view / 2;
	draw.angle_step = cub->player->view / cub->mlx_width;
	draw.angle = draw.angle_start;
	draw.x = 0;
	while (draw.angle > draw.angle_end)
	{
		draw_find_step_and_sidedist(cub, &draw);
		draw_find_hit_wall(cub, cub->map, &draw, cub->player);
		draw_find_perpwalldist_wallx(cub, &draw);
		cub_draw_wall2(cub, &draw);
		cub->player->zbuffer[draw.x] = draw.perpwalldist / \
			cos((cub->player->angle - draw.angle) * PI / 180);
		draw.angle -= draw.angle_step;
		draw.x++;
	}
}
