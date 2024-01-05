/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 01:09:01 by maltun            #+#    #+#             */
/*   Updated: 2024/01/05 04:13:29 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../INCLUDE/minishell.h"

void	lexer(t_prime *g_prime)
{
	t_list	*lex_slist;
	t_list	*lex_mlist;

	if (quotes_check(g_prime->line) == -1)
	{
		write(2, "minishell: incorrect use of quotes!\n", 37);
		g_prime->exit_code = 258;
		return ;
	}
	lex_slist = wspace_split(g_prime->line, 0, 0, 0);
	lex_mlist = metachar_split(lex_slist);
	create_nodes(g_prime, lex_mlist);
	if (syntax_check(g_prime) == -1)
		free_lexer(&g_prime->lexer);
}
