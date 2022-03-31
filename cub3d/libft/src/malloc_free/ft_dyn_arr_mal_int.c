/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyn_arr_mal_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarrell <cdarrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 02:47:42 by cdarrell          #+#    #+#             */
/*   Updated: 2021/11/19 17:35:55 by cdarrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	**ft_dyn_arr_mal_int(int row, int col)
{
	int	**arr;
	int	i;

	arr = (int **)malloc(row * sizeof(int *));
	if (!arr)
		return ((void *)0);
	i = -1;
	while (++i < row)
	{
		arr[i] = (int *)malloc(col * sizeof(int));
		if (arr[i] == (void *)0)
			return ((void *)0);
	}
	return (arr);
}
