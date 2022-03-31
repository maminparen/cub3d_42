/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:34:01 by hzona             #+#    #+#             */
/*   Updated: 2021/12/28 13:28:19 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	cub_close(void)
{	
	exit(0);
}

static int	cub_hook_key(int key, t_cub3d *cub)
{
	cub->active_key[key] = 1;
	return (0);
}

int	cub_release_key(int key, t_cub3d *cub)
{
	cub->active_key[key] = 0;
	return (0);
}

int	mouse_move(int x, int y, t_cub3d *cub)
{
	if (abs(cub->player->mouse_x - x) < 10 )
		return (0);
	if (cub->mouse >= 0 && cub->mouse < cub->player->mouse_x - x)
		cub->mouse = cub->player->mouse_x - x ;
	if (cub->mouse <= 0 && cub->mouse > cub->player->mouse_x - x)
		cub->mouse = cub->player->mouse_x - x ;
	cub->mouse /= 2;
	cub->player->mouse_x = x;
	y = 0;
	return (0);
}

void	cub_hook(t_cub3d *cub)
{
	mlx_hook(cub->mlx_win, 17, 0, cub_close, cub);
	mlx_hook(cub->mlx_win, 2, 1L << 0, cub_hook_key, cub);
	mlx_hook(cub->mlx_win, 3, 1L << 0, cub_release_key, cub);
	mlx_hook(cub->mlx_win, 6, 1L << 8, mouse_move, cub);
	mlx_mouse_hide(cub->mlx, cub->mlx_win);
}
