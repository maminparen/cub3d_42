/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw_wall2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:36:40 by hzona             #+#    #+#             */
/*   Updated: 2021/12/28 13:28:59 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	cub_draw_texture(t_cub3d *cub, \
		t_map *map, t_draw *draw)
{
	while (draw->y < draw->drawend)
	{
		draw->texy = (int)draw->texpos & (map->tex->width - 1);
		draw->texpos += draw->step;
		if (draw->side == 1 && draw->mapy < cub->player->y)
			draw->tn = 0;
		else if (draw->side == 1)
			draw->tn = 1;
		else if (draw->side == 0 && draw->mapx < cub->player->x)
			draw->tn = 2;
		else
			draw->tn = 3;
		cub->img.addr[draw->y * cub->mlx_width + draw->x] = \
			map->tex[draw->tn].data[draw->texy * map->tex->width + draw->texx];
		if (draw->door)
			cub->img.addr[draw->y * cub->mlx_width + draw->x] = \
			cub->map->door->data[draw->texx
				* cub->map->tex->width + draw->texy];
		draw->y++;
	}
	draw->door = 0;
}

void	cub_draw_celing(t_cub3d *cub, t_draw *draw)
{
	while (draw->y < draw->drawstart)
	{
		cub->img.addr[draw->y * cub->mlx_width + draw->x] = cub->map->c_colour;
		draw->y++;
	}
}

void	cub_draw_flour(t_cub3d *cub, t_draw *draw)
{
	while (draw->y < cub->mlx_height)
	{
		cub->img.addr[draw->y * cub->mlx_width + draw->x] = cub->map->f_colour;
		draw->y++;
	}
}

void	cub_draw_wall2(t_cub3d *cub, t_draw *draw)
{
	draw->y = 0;
	cub_draw_celing(cub, draw);
	draw->texx = (int)(draw->wallx * cub->map->tex->height);
	if ((draw->side == 0 && draw->cos > 0) || \
		(draw->side == 1 && draw->sin < 0))
		draw->texx = cub->map->tex->width - draw->texx - 1;
	draw->step = (double)cub->map->tex->height / draw->lineheight;
	draw->texpos = (draw->drawstart - \
			cub->mlx_height / 2 + draw->lineheight / 2) * draw->step;
	cub_draw_texture(cub, cub->map, draw);
	cub_draw_flour(cub, draw);
}
