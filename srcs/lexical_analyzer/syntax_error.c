/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 11:04:05 by mki               #+#    #+#             */
/*   Updated: 2021/05/11 11:35:51 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyzer.h"

int		syntax_error(int num)
{
	if (num == ERROR_QUOTE)
		printf("wrong quote syntax\n");
	else if (num == ERROR_BACKSLASH)
		printf("wrong backslash syntax\n");
	return (1);
}