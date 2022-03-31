/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw_check_sprite.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:23:37 by hzona             #+#    #+#             */
/*   Updated: 2021/12/28 13:29:21 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_srite_in_lst(t_list *tmp, int y, int x, int end)
{
	t_sprite	*spr;

	while (tmp)
	{
		spr = tmp->content;
		if (spr->x == x && spr->y == y)
		{
			spr->drawendx = end;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

static t_sprite	*checker_sprite_help(t_map *map,
	t_draw *draw, t_player *player)
{
	t_sprite	*tmp;

	tmp = (t_sprite *)malloc(sizeof(t_sprite));
	if (!tmp)
		cub_error("Error malloc sprite");
	tmp->drawstartx = draw->x;
	tmp->drawendx = draw->x;
	tmp->x = draw->mapx;
	tmp->y = draw->mapy;
	tmp->spr_tex = map->arr[draw->mapy][draw->mapx] - '2';
	tmp->dx = tmp->x + 0.5;
	tmp->dy = tmp->y + 0.5;
	tmp->spritex = tmp->dx - player->x;
	tmp->spritey = player->y - tmp->dy;
	tmp->angle = atan2(tmp->spritey, tmp->spritex) / PI * 180;
	return (tmp);
}

void	cub_check_sprite(t_cub3d *cub, t_map *map,
	t_draw *draw, t_player *player)
{
	t_sprite	*tmp;
	t_list		*lst;

	if (check_srite_in_lst(player->spr, draw->mapy, draw->mapx, draw->x))
		return ;
	tmp = checker_sprite_help(map, draw, player);
	while (tmp->angle < 0)
		tmp->angle += 2 * 180;
	while (tmp->angle - player->angle > 180)
		tmp->angle -= 2 * 180;
	while (tmp->angle - player->angle < -180)
		tmp->angle += 2 * 180;
	tmp->perpwalldist = sqrt(tmp->spritex * tmp->spritex + tmp->spritey
			* tmp->spritey) * cos((player->angle - tmp->angle) * PI / 180);
	tmp->lineheight = (int)(cub->mlx_height / tmp->perpwalldist
			/ tan(cub->player->view / 2 * PI / 180));
	tmp->drawstarty = -tmp->lineheight / 2 + cub->mlx_height / 2;
	tmp->drawendy = tmp->lineheight / 2 + cub->mlx_height / 2;
	lst = ft_lstnew(tmp);
	if (!lst)
		cub_error("Error malloc lst");
	ft_lstadd_back(&player->spr, lst);
}
