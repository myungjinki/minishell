# minishell

7/15

export 'a'=a; a=a

export "a"=a; a=a

export "'a'"=a; error

export a="a"; a=a

export a="'a'"; a='a'

export a=""a""; a=\"a\"

4/21

pipe

8/15

안되는 것
1. 그냥 enter만 누르면 프롬프트 나와야되는데 안나옴
2. 스페이스 한 번 누르고 엔터 누르면 터짐
3. " 한 개만 넣으면 입력대기상태가 됨... 토큰으로 나눌수가 없음 (너무 늦은감이 잇지만 구현안해도 됌 -> " + 엔터 => 에러 / 그냥 "하나 ->보너스 구현안해도 되는부분)
