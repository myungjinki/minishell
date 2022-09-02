/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_defs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 09:40:28 by jachoi            #+#    #+#             */
/*   Updated: 2021/01/02 01:08:52 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEFS_H
# define FT_DEFS_H
# define SPEC_OFFSET 0
# define FLAG_OFFSET 9
# define SPEC_CHAR 1
# define SPEC_STR 2
# define SPEC_PTR 4
# define SPEC_DECIMAL 8
# define SPEC_INT 16
# define SPEC_UINT 32
# define SPEC_SMALL_HEX 64
# define SPEC_BIG_HEX 128
# define SPEC_PERCENT 256
# define FLAG_MINUS 512
# define FLAG_ZERO 1024
# ifdef __linux__
#  define IS_LINUX 1
# else
#  define IS_LINUX 0
# endif
# ifdef _DEBUG
#  undef IS_LINUX
#  define IS_LINUX 0
# endif
#endif
