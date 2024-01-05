/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metachar_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:49:05 by maltun            #+#    #+#             */
/*   Updated: 2024/01/05 04:11:05 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../INCLUDE/minishell.h"

int	chrchr_metachar(char c)
{
	if (c == PIPE)
		return (SIGN_PIPE);
	else if (c == SOR)
		return (SIGN_SOR);
	else if (c == SIR)
		return (SIGN_SIR);
	else
		return (TEXT);
}

int	strchr_metachar(char *content)
{
	int	i;

	i = 0;
	while (content[i])
	{
		if (chrchr_metachar(content[i]))
			return (1);
		i++;
	}
	return (0);
}
