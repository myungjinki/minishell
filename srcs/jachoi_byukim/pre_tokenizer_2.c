/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_tokenizer_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byukim <byukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 02:47:42 by byukim            #+#    #+#             */
/*   Updated: 2021/01/16 02:47:44 by byukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		escape_count(char *src, int s)
{
	int		escape_num;

	escape_num = 1;
	while (s - escape_num >= 0 && src[s - escape_num] == '\\')
		escape_num++;
	return (escape_num);
}
