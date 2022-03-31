/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:33:51 by hzona             #+#    #+#             */
/*   Updated: 2022/01/19 12:30:33 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	move_calc(int *move, int frame)
{
	static int	revers;

	if (frame % 15 == 0 && revers == 0 && *move != 3)
		*move += 1;
	else if (frame % 15 == 0 && *move != 0)
	{
		*move -= 1;
		revers = 1;
	}
	if ((*move) == 0)
		revers = 0;
}

int	ft_update(void *param)
{
	t_cub3d		*cub;
	static int	frame;
	static int	move;

	cub = (t_cub3d *)param;
	frame++;
	open_door(cub, frame, -1);
	update_move(cub);
	if (cub->mouse > 0)
		cub->mouse --;
	if (cub->mouse < 0)
		cub->mouse ++;
	move_calc(&move, frame);
	cub_draw(cub, move);
	return (0);
}

int	main(int argc, char **argv)
{
	t_cub3d	*cub;

	if (argc == 2)
	{
		cub = cub_init(argv[1]);
		cub_hook(cub);
		mlx_loop_hook(cub->mlx, *ft_update, cub);
		mlx_loop(cub->mlx);
	}
	else
		cub_error("Error: Wrong enter");
	return (0);
}
