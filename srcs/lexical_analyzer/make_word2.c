/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_word2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 18:05:13 by sehan             #+#    #+#             */
/*   Updated: 2021/06/11 19:14:24 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyzer.h"

void	malloc_argv(t_word *word, int *i, int *j, int size)
{
	(*i)++;
	*j = -1;
	word[*i].argv = (char **)malloc(sizeof(char *) * (size + 1));
	word[*i].argv[size] = 0;
}
