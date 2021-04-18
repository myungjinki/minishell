# minishell

7/15

export 'a'=a; a=a
export "a"=a; a=a
export "'a'"=a; error
export a="a"; a=a
export a="'a'"; a='a'
export a=""a""; a=\"a\"
