# 42TESTERS-MINISHELL

WARNING - INCOMPLETE FOR THE MOMENT /!\

1 - cd to the folder with your fonctions

2 - git clone https://github.com/Mazoise/42TESTERS-MINISHELL.git

3 - cd 42TESTERS-MINISHELL

4 - bash tester.sh

5 - check diff.txt in case of errors

If you want to change the path to your project's Makefile or deactivate Norminette, check in tester.sh (lines 74 & 99)

If you have an infinite loop when running the simple command below in bash, look up for the macros S_ISFIFO & S_ISREG ...
example :
        echo "echo hello" | ./minishell

If you need other tips or don't understant something, please contact me on slack (mchardin)
Don't hesitate to make a pull request if you find ways to improve my tester.

Thanks to @Syndraum (roalvare), the best mate ! 
