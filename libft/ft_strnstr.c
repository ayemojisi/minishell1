/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 03:48:44 by maltun            #+#    #+#             */
/*   Updated: 2024/01/05 04:11:05 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (src[0] == '\0')
		return ((char *)dest);
	else
	{
		i = -1;
		while (++i < size && dest[i])
		{
			j = 0;
			while (dest[i + j] == src[j] && (i + j) < size)
			{
				if (src[j + 1] == '\0')
					return ((char *)dest + i);
				j++;
			}
		}
	}
	return (NULL);
}
