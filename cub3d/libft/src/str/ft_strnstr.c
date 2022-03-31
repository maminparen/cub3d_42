/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarrell <cdarrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:39:12 by cdarrell          #+#    #+#             */
/*   Updated: 2021/11/19 17:37:42 by cdarrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!(*needle))
		return ((char *)haystack);
	i = 0;
	while (!(!haystack && len == 0) && *haystack)
	{
		j = 0;
		while (*(needle + j) && i + j < len)
		{
			if (*(needle + j) == *(haystack + j))
				j++;
			else
			{
				j = 0;
				break ;
			}
		}
		if (*(needle + j) == '\0')
			return ((char *)haystack);
		i++;
		haystack++;
	}
	return ((void *)0);
}
