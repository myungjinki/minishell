/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ismeta.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:17:02 by mki               #+#    #+#             */
/*   Updated: 2021/05/18 13:09:47 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_ismeta(char c)
{
	if (c == '|' || c == '&' || c == ';' || c == '(' ||\
		c == ')' || c == '<' || c == '>' || c == '`')
		return (c);
	return (0);
}
