/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyn_arr_mal_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarrell <cdarrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 02:47:37 by cdarrell          #+#    #+#             */
/*   Updated: 2021/11/19 17:35:52 by cdarrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	**ft_dyn_arr_mal_char(int row, int col)
{
	char	**arr;
	int		i;

	arr = (char **)malloc(row * sizeof(char *));
	if (!arr)
		return ((void *)0);
	i = -1;
	while (++i < row)
	{
		arr[i] = (char *)malloc(col * sizeof(char));
		if (arr[i] == (void *)0)
			return ((void *)0);
	}
	return (arr);
}
