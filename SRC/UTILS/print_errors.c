/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:39:21 by maltun            #+#    #+#             */
/*   Updated: 2024/01/05 04:14:51 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDE/minishell.h"

int	synerr_print(t_prime *g_prime, char *str, int f)
{
	if (f == 1)
		write(2, "minishell: ", 12);
	else
		write(2, "minishell: syntax error near unexpected token ", 47);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	g_prime->exit_code = 258;
	return (-1);
}

void	file_error(char *filename, char *str, int *fd, t_prime *g_prime)
{
	write(2, "minishell: ", 11);
	write(2, filename, ft_strlen(filename));
	write(2, ": ", 2);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	*fd = 2;
	g_prime->exit_code = 1;
}

void	print_error(t_prime *g_prime, char *str)
{
	write(2, "minishell: ", 11);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	g_prime->exit_code = 258;
	return ;
}

int	command_error(char *arg, char *cmd, char *str, t_prime *g_prime)
{
	write(2, "minishell: ", 11);
	if (cmd)
		write(2, cmd, ft_strlen(cmd));
	write(2, ": ", 2);
	if (arg)
	{
		write(2, arg, ft_strlen(arg));
		write(2, ": ", 2);
	}
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	g_prime->exit_code = 1;
	g_prime->parser->outfile = 1;
	return (1);
}
