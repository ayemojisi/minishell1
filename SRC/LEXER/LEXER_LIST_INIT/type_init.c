/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 07:20:14 by maltun            #+#    #+#             */
/*   Updated: 2024/01/05 04:11:05 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../INCLUDE/minishell.h"

static void	type_match(t_lexer *temp)
{
	if (temp->type == SIGN_SIR && ft_strlen(temp->content) == 2)
		temp->type = HEREDOC;
	else if (temp->type == SIGN_SOR && ft_strlen(temp->content) == 2)
		temp->type = SIGN_DOR;
	else if (temp->type == SIGN_SIR && ft_strlen(temp->content) > 2)
		temp->type = -3;
	else if (temp->type == SIGN_PIPE && ft_strlen(temp->content) > 1)
		temp->type = -1;
	else if (temp->type == SIGN_SOR && ft_strlen(temp->content) > 2)
		temp->type = -2;
}

void	type_init(t_prime *g_prime)
{
	t_lexer	*temp;

	temp = g_prime->lexer;
	while (temp)
	{
		if (temp->type != 0)
			type_match(temp);
		temp = temp->next;
	}
}
