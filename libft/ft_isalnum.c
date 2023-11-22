/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:10:33 by maltun            #+#    #+#             */
/*   Updated: 2022/12/11 14:26:22 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z'))
		return (1);
	return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z'));
}
