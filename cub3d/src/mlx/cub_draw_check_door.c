/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw_check_door.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:16:07 by hzona             #+#    #+#             */
/*   Updated: 2021/12/28 13:30:43 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_door_in_lst(t_list *tmp, t_draw *draw)
{
	t_sprite	*spr;

	while (tmp)
	{
		spr = tmp->content;
		if (spr->x == draw->mapx && spr->y == draw->mapy)
		{
			spr->lineheightend = draw->lineheight;
			spr->drawendx = draw->x;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

static t_sprite	*checker_door_help(t_draw *draw, t_player *player)
{
	t_sprite	*tmp;

	tmp = (t_sprite *)malloc(sizeof(t_sprite));
	if (!tmp)
		cub_error("Error malloc sprite");
	tmp->drawstartx = draw->x;
	tmp->drawendx = draw->x;
	tmp->x = draw->mapx;
	tmp->y = draw->mapy;
	tmp->spr_tex = 0;
	tmp->dx = tmp->x + 0.5;
	tmp->dy = tmp->y + 0.5;
	tmp->spritex = tmp->dx - player->x;
	tmp->spritey = player->y - tmp->dy;
	tmp->angle = atan2(tmp->spritey, tmp->spritex) / PI * 180;
	return (tmp);
}

void	cub_check_door(t_cub3d *cub,
	t_draw *draw, t_player *player)
{
	t_sprite	*tmp;
	t_list		*lst;

	if (check_door_in_lst(player->door, draw))
		return ;
	tmp = checker_door_help(draw, player);
	while (tmp->angle < 0)
		tmp->angle += 2 * 180;
	while (tmp->angle - player->angle > 180)
		tmp->angle -= 2 * 180;
	while (tmp->angle - player->angle < -180)
		tmp->angle += 2 * 180;
	tmp->perpwalldist = sqrt(tmp->spritex * tmp->spritex + tmp->spritey
			* tmp->spritey) * cos((player->angle - tmp->angle) * PI / 180);
	tmp->lineheight = draw->lineheight;
	tmp->lineheightend = draw->lineheight;
	tmp->drawstarty = -tmp->lineheight / 2 + cub->mlx_height / 2;
	tmp->drawendy = tmp->lineheight / 2 + cub->mlx_height / 2;
	lst = ft_lstnew(tmp);
	if (!lst)
		cub_error("Error malloc lst");
	ft_lstadd_back(&player->door, lst);
}
