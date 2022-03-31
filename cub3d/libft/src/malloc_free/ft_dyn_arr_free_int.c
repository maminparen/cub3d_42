/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyn_arr_free_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarrell <cdarrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 02:47:32 by cdarrell          #+#    #+#             */
/*   Updated: 2021/11/19 17:35:49 by cdarrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_dyn_arr_free_int(int **arr, int row)
{
	int	i;

	i = -1;
	while (++i < row)
		free(arr[i]);
	free(arr);
}
