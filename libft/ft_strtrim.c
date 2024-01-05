/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 03:49:03 by maltun            #+#    #+#             */
/*   Updated: 2024/01/05 04:11:05 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	char	*cuttedstring;
	int		i;
	int		endofs;

	if (s != NULL)
	{
		i = 0;
		while (s[i] && ft_strchr(set, s[i]))
			i++;
		endofs = ft_strlen(s) - 1;
		while (endofs > i && ft_strchr(set, s[endofs]))
			endofs--;
		cuttedstring = ft_substr(s, i, endofs - i + 1);
		return (cuttedstring);
	}
	return (NULL);
}
