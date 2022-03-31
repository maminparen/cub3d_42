/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:33:44 by hzona             #+#    #+#             */
/*   Updated: 2021/12/28 13:46:35 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	player_rotate(t_cub3d	*cub, char key)
{
	if (cub->mouse != 0)
		cub->player->rotspeed *= 2;
	if (key == 123)
	{
		cub->player->angle += cub->player->rotspeed;
		if (cub->player->angle >= 360)
			cub->player->angle = 0;
		if (cub->player->angle <= -360)
			cub->player->angle = 0;
	}
	else if (key == 124)
	{
		cub->player->angle -= cub->player->rotspeed;
		if (cub->player->angle >= 360)
			cub->player->angle = 0;
		if (cub->player->angle <= -360)
			cub->player->angle = 0;
	}
	if (cub->mouse != 0)
		cub->player->rotspeed /= 2;
}

void	player_updown(t_cub3d *cub, double tmp_x, double tmp_y)
{
	if (cub->active_key[13] == 1)
	{
		if (cub->map->arr[(int)(cub->player->y)]
		[(int)(cub->player->x + tmp_x)] == '0')
			cub->player->x += tmp_x;
		if (cub->map->arr[(int)(cub->player->y + tmp_y)]
		[(int)(cub->player->x)] == '0')
			cub->player->y += tmp_y;
	}
	else if (cub->active_key[1] == 1)
	{
		if (cub->map->arr[(int)(cub->player->y)]
		[(int)(cub->player->x - tmp_x)] == '0')
			cub->player->x -= tmp_x;
		if (cub->map->arr[(int)(cub->player->y - tmp_y)]
		[(int)(cub->player->x)] == '0')
			cub->player->y -= tmp_y;
	}
}

void	player_leftright(t_cub3d *cub, double tmp_x, double tmp_y)
{
	if (cub->active_key[2] == 1)
	{
		if (cub->map->arr[(int)(cub->player->y)]
		[(int)(cub->player->x - tmp_y)] == '0'
			&& cub->map->arr[(int)(cub->player->y + tmp_x)]
			[(int)(cub->player->x)] == '0')
		{
			cub->player->x -= tmp_y;
			cub->player->y += tmp_x;
		}
	}
	else if (cub->active_key[0] == 1)
	{
		if (cub->map->arr[(int)(cub->player->y)]
		[(int)(cub->player->x + tmp_y)] == '0'
			&& cub->map->arr[(int)(cub->player->y - tmp_x)]
			[(int)(cub->player->x)] == '0')
		{
			cub->player->x += tmp_y;
			cub->player->y -= tmp_x;
		}
	}
}

void	update_move(t_cub3d	*cub)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = cub->player->movespeed * cos(cub->player->angle * PI / 180);
	tmp_y = -cub->player->movespeed * sin(cub->player->angle * PI / 180);
	if (cub->active_key[53] == 1)
		cub_close();
	else if (cub->active_key[123] == 1 || cub->mouse > 0)
		player_rotate(cub, 123);
	else if (cub->active_key[124] == 1 || cub->mouse < 0)
		player_rotate(cub, 124);
	player_updown(cub, tmp_x, tmp_y);
	player_leftright(cub, tmp_x / 2, tmp_y / 2);
	return ;
}

void	open_door(t_cub3d *cub, int frame, int i)
{
	static int	open_door;
	static int	doorx;
	static int	doory;
	static int	first;

	while (++i < 9 && cub->active_key[14] == 1 && first == 0)
	{
		if (cub->map->arr[((int)cub->player->y + i % 3 - 1)]
			[(int)(cub->player->x + i / 3 - 1)] == 'D')
		{
			cub->map->arr[((int)cub->player->y + i % 3 - 1)]
			[(int)(cub->player->x + i / 3 - 1)] = '0';
			open_door = frame;
			doorx = (int)(cub->player->x + i / 3 - 1);
			doory = (int)(cub->player->y + i % 3 - 1);
			first = 1;
		}
	}
	if (open_door + 100 < frame && doorx != (int)cub->player->x
		&& doory != (int)cub->player->y && first)
	{
		open_door = 1000000000;
		cub->map->arr[doory][doorx] = 'D';
		first = 0;
	}
}
