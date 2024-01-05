/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 03:48:25 by maltun            #+#    #+#             */
/*   Updated: 2024/01/05 04:11:05 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *source, size_t size)
{
	size_t	i;
	size_t	j;

	if (!dest && !size)
		return (0);
	i = ft_strlen(dest);
	if (i >= size)
		return (size + ft_strlen(source));
	j = -1;
	while (source[++j] && (i + j) < (size - 1))
		dest[i + j] = source[j];
	dest[i + j] = '\0';
	return (i + ft_strlen(source));
}
