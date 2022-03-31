/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_read_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:38:57 by hzona             #+#    #+#             */
/*   Updated: 2021/12/27 20:38:58 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	parsing_player(t_map *map, int i, char z)
{
	if (map->player_z != '\0')
		cub_error("Error map: more then one player");
	map->player_x = i;
	map->player_y = map->row;
	map->player_z = z;
}

static int	parsin_check_map(char *s, t_map *map)
{
	int	i;

	i = -1;
	while (*(s + ++i))
	{
		if ((s[i] >= '0' && s[i] <= '1') || s[i] == ' ')
			;
		else if (s[i] >= '2' && s[i] <= '2' + map->sprite_tex_num)
			map->sprites_num += 1;
		else if (s[i] == 'D')
			map->doors_num += 1;
		else if (s[i] == 'N' || s[i] == 'S' || s[i] == 'W' || s[i] == 'E')
			parsing_player(map, i, s[i]);
		else
			return (0);
	}
	if (map->col < i)
		map->col = i;
	map->row++;
	return (1);
}

void	parsing_read_line(int rd, char *line, t_map *map, t_list **head_map)
{
	t_list	*tmp;

	if (!line)
		cub_error("Error map: malloc error newline");
	if (!(map->row) && (!ft_strlen(line) || parsing_texture(line, map)))
	{
		free(line);
		return ;
	}
	if (!ft_strlen(line) && rd)
		cub_error("Error map: parsing - empty line in map");
	if (!ft_strlen(line) && !rd)
	{
		free (line);
		return ;
	}
	if (parsin_check_map(line, map))
	{
		tmp = ft_lstnew(line);
		if (!tmp)
			cub_error("Error map: cannot creat new list");
		ft_lstadd_back(head_map, tmp);
	}
	else
		cub_error("Error map: wrong symbol in map");
}
