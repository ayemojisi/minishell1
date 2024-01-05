/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:55:06 by maltun            #+#    #+#             */
/*   Updated: 2024/01/05 04:11:05 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../INCLUDE/minishell.h"

void	create_nodes(t_prime *g_prime, t_list *lex_mlist)
{
	t_list	*temp;

	temp = lex_mlist;
	while (temp)
	{
		if (!strchr_metachar(temp->content) || strchr_quotes(temp->content))
			lexer_add_node(&g_prime->lexer, temp->content, 0);
		else
			lexer_add_node(&g_prime->lexer, temp->content, \
				chrchr_metachar(*(char *)temp->content));
		lex_mlist = temp;
		temp = temp->next;
		free(lex_mlist->content);
		free(lex_mlist);
	}
}
