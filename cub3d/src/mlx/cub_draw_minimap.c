/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw_minimap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:27:37 by hzona             #+#    #+#             */
/*   Updated: 2021/12/27 21:14:53 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	cube_scale_img(t_cub3d *cub, int y, int x, int colour)
{
	int		x1;
	int		y1;
	int		scale;

	scale = cub->mlx_height / 3 / cub->map->col;
	x1 = x + 1;
	y1 = y + 1;
	x1 *= scale;
	y1 *= scale;
	x *= scale;
	y *= scale;
	while (y < y1)
	{
		while (x < x1)
		{
			if (x < x1)
				cub->img.addr[y * cub->mlx_width + x] = colour;
			x++;
		}
		x -= scale;
		y++;
	}
}

static void	cub_draw_map(t_cub3d *cub)
{
	int		x;
	int		y;

	y = -1;
	while (++y < cub->map->row)
	{
		x = -1;
		while (++x < cub->map->col)
		{
			if (cub->map->arr[y][x] == '1')
				cube_scale_img(cub, y, x, 0xffffff);
			if (cub->map->arr[y][x] == 'D')
				cube_scale_img(cub, y, x, 0xff0000);
			if (cub->map->arr[y][x] >= '2' && cub->map->arr[y][x] <= '9')
				cube_scale_img(cub, y, x, 0x00ff00);
		}
	}
}

static void	cube_scale_img2(t_cub3d *cub, int y, int x, int scale)
{
	int	x1;
	int	y1;

	x1 = x - scale;
	y1 = y - scale;
	while (y1 < y + scale)
	{		
		while (x1 < x + scale)
		{
			if (sqrt((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y)) < scale)
			{
				cub->img.addr[y1 * cub->mlx_width + x1] = 0xff0000;
			}
			x1++;
		}
		x1 = x - scale;
		y1 ++;
	}
}

static void	cub_draw_player(t_cub3d *cub, double x, double y)
{
	int		scale;

	scale = cub->mlx_height / 3 / cub->map->col;
	cube_scale_img2(cub, y * scale, x * scale, scale / 3);
	while (x > 0 && y > 0 && cub->map->arr[(int)y][(int)x] != '1')
	{
		x += 0.1 * cos (cub->player->angle * PI / 180);
		y -= 0.1 * sin (cub->player->angle * PI / 180);
		cub->img.addr[(int)(y * scale) *cub->mlx_width
			+ (int)(x * scale)] = 0xff0000;
	}
}

void	cub_draw_minimap(t_cub3d *cub)
{
	cub_draw_map(cub);
	cub_draw_player(cub, cub->player->x, cub->player->y);
}
