/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_arg_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 00:25:14 by maltun            #+#    #+#             */
/*   Updated: 2024/01/05 04:11:05 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../INCLUDE/minishell.h"

int	env_name_control(char *env)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (!env || env[i] == ' ' || env[i] == '=')
		return (0);
	if (ft_isalpha(env[i]) || env[i] == '_')
		flag = 1;
	while (env[i] && env[i] != ' ' && env[i] != '=' && flag == 1)
	{
		if ((!ft_isdigit(env[i]) && !ft_isalpha(env[i]) && env[i] != '_')
			|| !flag)
			return (0);
		i++;
	}
	if (env[i] != '=' && env[i])
		return (0);
	return (1);
}

int	env_arg_control(t_prime *g_prime, char *env)
{
	if (env_name_control(env))
		return (1);
	command_error(env, "export", "not a valid identifier", g_prime);
	g_prime->exit_code = 1;
	return (0);
}
