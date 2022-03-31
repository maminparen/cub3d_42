/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ull.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarrell <cdarrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 02:46:24 by cdarrell          #+#    #+#             */
/*   Updated: 2021/11/19 17:36:50 by cdarrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_putnbr_ull(unsigned long long int nbr)
{
	if (nbr >= 10)
		ft_putnbr_ull(nbr / 10);
	ft_putchar_fd('0' + (nbr % 10), 1);
}
