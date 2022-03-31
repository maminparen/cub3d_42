/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw_sprite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:29:38 by hzona             #+#    #+#             */
/*   Updated: 2021/12/28 13:35:55 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	cub_draw_sprite_line(t_cub3d *cub, t_sprite *spr, int move)
{
	int		y;
	int		texy;
	int		color;

	y = spr->drawstarty;
	while (y < spr->drawendy)
	{
		if (y > 0 && y < cub->mlx_height)
		{
			if (spr->spr_tex != 0)
				move = 0;
			texy = (int)((y - spr->drawstarty) * \
				cub->map->spr[spr->spr_tex + move].height / spr->lineheight);
			color = cub->map->spr[spr->spr_tex + move]. \
					data[texy * cub->map->tex->width + spr->texx];
			if (color != -16777216 && \
					cub->player->zbuffer[spr->x_start] > spr->perpwalldist)
				cub->img.addr[y * cub->mlx_width + spr->x_start] = color;
		}
		y++;
	}
}

void	cub_draw_texture2(t_cub3d *cub, t_sprite *spr, int move)
{
	spr->center = (int)((((cub->player->angle + cub->player->view / 2 \
		- spr->angle)) * cub->mlx_width) / cub->player->view);
	spr->x_start = spr->center - spr->lineheight / 2;
	spr->xx_start = spr->x_start;
	spr->x_end = spr->center + spr->lineheight / 2;
	while (spr->x_start < spr->x_end)
	{
		if (spr->x_start > spr->drawstartx && spr->x_start < spr->drawendx)
		{
			spr->texx = (int)((spr->x_start - spr->xx_start) * \
				cub->map->spr[spr->spr_tex].width / spr->lineheight);
			cub_draw_sprite_line(cub, spr, move);
		}
		spr->x_start++;
	}
}

void	sort_range_texture(t_list **tex)
{
	t_list		*first;
	t_list		*tmp;
	t_sprite	*tspr;
	t_sprite	*tspr2;

	first = *tex;
	while (first->next)
	{
		tspr = first->content;
		tspr2 = first->next->content;
		tmp = first;
		if (tspr->perpwalldist < tspr2->perpwalldist)
		{
			first->content = first->next->content;
			first->next->content = tspr;
			first = *tex;
		}
		else
			first = first->next;
	}
}

void	cub_draw_sprite(t_cub3d *cub, int move)
{
	t_list	*tmp;

	tmp = cub->player->spr;
	if (cub->player->spr != NULL && ft_lstsize(cub->player->spr) > 1)
		sort_range_texture(&tmp);
	while (tmp)
	{
		cub_draw_texture2(cub, tmp->content, move);
		tmp = tmp->next;
	}
	ft_lstclear(&cub->player->spr, free);
	cub->player->spr = NULL;
}
