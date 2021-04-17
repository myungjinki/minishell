/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 12:59:52 by sehan             #+#    #+#             */
/*   Updated: 2021/04/14 13:04:56 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_stoi(char *str)
{
	int result;
	int len;

	len = ft_strlen(str) - 1;
	result = 0;
	while (len >= 0)
	{
		result = result * 256 + str[len];
		len--;
	}
	return (result);
}
