/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergun <iergun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:22:11 by maltun            #+#    #+#             */
/*   Updated: 2023/11/22 20:11:57 by iergun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_cmd_line(t_struct *list)
{
	if (list->cmd)
		free(list->cmd);
	list->cmd = readline("\033[36mMinishell: \033[33m");
	if (list->cmd && ft_strlen(list->cmd) != 0)
		add_history(list->cmd);
}

int	main(int ac, char **av, char **env)
{
	t_struct	*list;
	t_lexer		*lexer;

	if (check_arg(av, ac))
		return (2);
	list = ft_calloc(1, sizeof(t_struct));
	lexer = ft_calloc(1, sizeof(t_lexer));
	(void)ac;
	(void)av;
	(void)env;
	printf("\033[H\033[J");
	while (1)
	{
		get_cmd_line(list);
		cmd_control(list);
		word_by_word(list, lexer);
		while (lexer->next)
		{
			printf("(word: %s) (token: %u) (index :%d)\n", lexer->str, lexer->token, lexer->i);
			lexer = lexer->next;
		}
	}
	return (0);
}
