/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 01:17:37 by maltun            #+#    #+#             */
/*   Updated: 2024/01/05 04:11:05 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../INCLUDE/minishell.h"

static int	quotes_check2(char *line, int *i, char q)
{
	int	j;

	j = *i;
	while (line[++j])
	{
		if (line[j] == q)
		{
			*i = j + 1;
			return (1);
		}
	}
	return (0);
}

int	quotes_check(char *line)
{
	int		i;

	i = 0;
	while (line && line[i])
	{
		if (chrchr_quotes(line[i]))
		{
			if (quotes_check2(line, &i, line[i]) == 0)
				return (-1);
		}
		else
			while (line[i] && !chrchr_quotes(line[i]))
				i++;
	}
	return (0);
}
