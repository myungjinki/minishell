/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:06:59 by mki               #+#    #+#             */
/*   Updated: 2021/04/25 16:11:39 by mki              ###   ########.fr       */
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

# define	COMMAND				0x01
# define	OPTIONS				0x02
# define 	QUOTE				0x03
# define 	DQUOTE				0x04
# define	STRING				0x05
# define	CHARACTER			0x06

# define	WHITESPACE			0x20
# define	EXCLAMATION			0x21
# define	DOUBLE_QUOTE		0x22
# define	HASH				0x23
# define	DOLLAR_SIGN			0x24
# define	PERCENT				0x25
# define	AMPERSNAD			0x26
# define	SINGLE_QUOTE		0x27	
# define	L_PARENT			0x28
# define	R_PARENT			0x29
# define	ASTERISK			0x2A
# define	SEMICOLON			0x3B
# define	QUESTION_MARK		0x3F
# define 	BACKSLASH			0x5C
# define 	VERTICAL_BAR		0x7C

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

// void	lexer(char *s);
// void	parser(t_mini *, char *, char **);
void	token(t_mini *, char **);

#endif
