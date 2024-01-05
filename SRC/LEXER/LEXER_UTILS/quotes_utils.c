/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:36:50 by maltun            #+#    #+#             */
/*   Updated: 2024/01/05 04:11:05 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../INCLUDE/minishell.h"

int	chrchr_quotes(char c)
{
	return (c == D_QUOTES || c == S_QUOTES);
}

int	strchr_quotes(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (chrchr_quotes(str[i]))
			return (1);
	}
	return (0);
}
