/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_init_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergun <iergun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:58:32 by maltun            #+#    #+#             */
/*   Updated: 2024/01/05 12:47:52 by iergun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../INCLUDE/minishell.h"

static t_expander	*expander_listnew(char *content, t_lexer *lexer, int env)
{
	t_expander	*new;

	new = (t_expander *)malloc(sizeof(t_expander));
	if (!new)
		return (NULL);
	new->content = content;
	new->type = lexer->type;
	new->env = env;
	new->ex_content = NULL;
	if (env == -1)
		new->ex_content = ft_strdup(lexer->content);
	new->next = NULL;
	return (new);
}

static t_expander	*expander_lstlast(t_expander *lst)
{
	t_expander	*temp;

	if (!lst)
		return (0);
	temp = lst;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

static void	expander_lstadd_back(t_expander **lst, t_expander *new)
{
	if (new)
	{
		if (!(*lst))
		{
			*lst = new;
			return ;
		}
		expander_lstlast(*lst)->next = new;
		new->next = 0;
	}
}

void	expander_add_node(t_expander **expand, char *str, t_lexer *lex, int env)
{
	if (!str)
	{
		free_expander(expand);
	}
	else
		expander_lstadd_back(expand, expander_listnew(str, lex, env));
}
