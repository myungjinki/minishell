/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 10:12:00 by jachoi            #+#    #+#             */
/*   Updated: 2020/10/22 20:06:20 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H
# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>

bool				ft_isdigit(char c);
char				*ft_itoa(int64_t n);
int					ft_max(int a, int b);
void				ft_memcpy(char *d, char *s, size_t l);
void				ft_memset(char *d, char c, size_t l);
int					ft_min(int a, int b);
int					ft_numlen(int64_t n, int base);
int					ft_unumlen(uint64_t n, int base);
char				*ft_uitoa(uint64_t n, int base);
size_t				ft_slen(const char *s);
#endif
