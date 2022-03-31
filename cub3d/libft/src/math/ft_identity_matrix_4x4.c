/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_identity_matrix_4x4.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarrell <cdarrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 02:47:05 by cdarrell          #+#    #+#             */
/*   Updated: 2021/10/30 02:47:07 by cdarrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_identity_matrix_4x4(float T[4][4])
{
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (i == j)
				T[i][j] = 1;
			else
				T[i][j] = 0;
		}
	}
}
