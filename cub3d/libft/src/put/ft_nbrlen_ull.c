/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_ull.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarrell <cdarrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 02:46:44 by cdarrell          #+#    #+#             */
/*   Updated: 2021/11/19 17:36:24 by cdarrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_nbrlen_ull(unsigned long long int nbr)
{
	int	len;

	len = 0;
	while (nbr || len == 0)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}
