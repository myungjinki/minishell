/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:06:59 by mki               #+#    #+#             */
/*   Updated: 2021/04/25 14:21:10 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

/*
**	 	Space					U+0020
**	!	Exclamation				U+0021
**	”	Double quote			U+0022
**	#	Number sign (hash)		U+0023
**	$	Dollar sign				U+0024
**	%	Percent					U+0025
**	&	Ampersand				U+0026
**	’	Single quote			U+0027
**	(	Left parenthesis		U+0028
**	)	Right parenthesis		U+0029
**	*	Asterisk				U+002A
**	+	Plus					U+002B
**	,	Comma					U+002C
**	-	Minus					U+002D
**	.	Full stop				U+002E
**	/	Slash					U+002F
**	:	Colon					U+003A
**	;	Semicolon				U+003B
**	<	Less than				U+003C
**	=	Equal sign				U+003D
**	>	Greater than			U+003E
**	?	Question mark			U+003F
**	@	At sign					U+0040
**	[	Left bracket			U+005B
**	\	Backslash				U+005C
**	]	Right bracket			U+005D
**	^	Caret					U+005E
**	_	Underscore				U+005F
**	`	Grave accent (backtick)	U+0060
**	{	Left brace				U+007B
**	|	Vertical bar			U+007C
**	}	Right brace				U+007D
**	~	Tilde					U+007E
*/

# define	WHITESPACE			20
# define	EXCLAMATION			21
# define	DOUBLE_QUOTE		22
# define	HASH				23
# define	DOLLAR_SIGN			24
# define	PERCENT				25
# define	AMPERSNAD			26
# define	SINGLE_QUOTE		27	
# define	L_PARENT			28
# define	R_PARENT			29
# define 	PIPELINE		3
# define	COMMAND			4
# define	OPTIONS			5
# define 	BACKSLASH		6

/*
**	struct
*/

typedef struct  s_line
{
    char        *line;
}               t_line;

typedef struct	s_symbol_table
{
	int			name;
	void		*value;
}				t_symbol_table;

void	lexer(char *s);

#endif
