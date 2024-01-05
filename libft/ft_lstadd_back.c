/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 03:45:49 by maltun            #+#    #+#             */
/*   Updated: 2024/01/05 04:11:05 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list	**lst, t_list	*new)
{
	if (new)
	{
		if (!*lst)
		{
			*lst = new;
			return ;
		}
		ft_lstlast(*lst)->next = new;
		new->next = 0;
	}
}
