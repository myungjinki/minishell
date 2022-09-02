# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    preprocess.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/15 18:25:00 by charles           #+#    #+#              #
#    Updated: 2020/10/09 12:39:07 by cacharle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import config
import hooks
from suite import suite


@suite()
def suite_quote(test):
    """ double and single quote test, escape in quotes, quote missmatch """
    test("'echo' 'bonjour'")
    test("'echo' 'je' 'suis' 'charles'")
    test('"echo" "bonjour"')
    test('"echo" "je" "suis" "charles"')
    test('echo je\'suis\'"charles"')
    test('echo "je"suis\'charles\'')
    test('echo \'je\'"suis"charles')
    test('echo "\\""')
    test('echo "\\$"')
    test('echo "\\\\"')
    test('echo "\\a"')
    test('echo "\\A"')
    test('ls ""')
    test("ls ''")
    test('ls "" "" "" \'\' """"')
    test("ls '' '' '''' ''")
    test("'     echo' bonjour")
    test("'echo     ' bonjour")
    test('"     echo" bonjour')
    test('"echo     " bonjour')
    test("''echo bonjour")
    test('""echo bonjour')
    test("''''''''''''''''''''''''''''''''''''''''''''''''''''''''''echo bonjour")
    test('""""""""""""""""""""""""""""""""""""""""""""""""""""""""""echo bonjour')
    test("echo'' bonjour")
    test('echo"" bonjour')
    test("echo'''''''''''''''''''''''''''''''''''''''''''''''''''''''''' bonjour")
    test('echo"""""""""""""""""""""""""""""""""""""""""""""""""""""""""" bonjour')
    test("ec''ho bonjour")
    test('ec""ho bonjour')
    test("ec''''''''''''''''''''''''''''''''''''''''''''''''''''''''''ho bonjour")
    test('ec""""""""""""""""""""""""""""""""""""""""""""""""""""""""""ho bonjour')
    test("'''''''e''''''''''c''''''''''''h''''''''o''''''''''''''''''''' bonjour")
    test('"""""""e""""""""""c""""""""""""h""""""""o""""""""""""""""""""" bonjour')
    test("echo '\"'")
    test("echo '\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"'")
    test('echo "\'"')
    test('echo "\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'\'"')
    test("echo '", hook=hooks.error_line0, hook_status=hooks.platform_status(2, 1))
    test('echo "', hook=hooks.error_line0, hook_status=hooks.platform_status(2, 1))
    test("echo '''", hook=hooks.error_line0, hook_status=hooks.platform_status(2, 1))
    test('echo """', hook=hooks.error_line0, hook_status=hooks.platform_status(2, 1))
    test("echo '''''''''''''''''''''''''''''''''''''''''''", hook=hooks.error_line0, hook_status=hooks.platform_status(2, 1))
    test('echo """""""""""""""""""""""""""""""""""""""""""', hook=hooks.error_line0, hook_status=hooks.platform_status(2, 1))
    test("echo 'AH\\'")
    test('echo "AH\\"', hook=hooks.error_line0, hook_status=hooks.platform_status(2, 1))
    test('echo "AH\\""')
    test("echo '\\''", hook=hooks.error_line0, hook_status=hooks.platform_status(2, 1))
    test('echo "\\""')
    test('echo "\\\\""', hook=hooks.error_line0, hook_status=hooks.platform_status(2, 1))


@suite()
def suite_interpolation(test):
    """environment variable interpolation tests, valid name, escape in variable"""
    test("echo $TEST",             exports={"TEST": "bonjour"})
    test("echo $TES",              exports={"TEST": "bonjour"})
    test("echo $TEST_",            exports={"TEST": "bonjour"})
    test('echo "|$TEST|"',         exports={"TEST": "bonjour"})
    test('echo "|$TES|"',          exports={"TEST": "bonjour"})
    test('echo "|$TEST_|"',        exports={"TEST": "bonjour"})
    test("echo '|$TEST|'",         exports={"TEST": "bonjour"})
    test("echo '|$TES|'",          exports={"TEST": "bonjour"})
    test("echo '|$TEST_|'",        exports={"TEST": "bonjour"})
    test("echo $A$B$C",            exports={"A": "foo", "B": "bar", "C": "baz"})
    test('echo "$A$B$C"',          exports={"A": "foo", "B": "bar", "C": "baz"})
    test("echo '$A$B$C'",          exports={"A": "foo", "B": "bar", "C": "baz"})
    test("echo $A,$B,$C",          exports={"A": "foo", "B": "bar", "C": "baz"})
    test('echo "$A,$B,$C"',        exports={"A": "foo", "B": "bar", "C": "baz"})
    test("echo '$A,$B,$C'",        exports={"A": "foo", "B": "bar", "C": "baz"})
    test('echo $A"$B"$C"A"$B"$C"', exports={"A": "foo", "B": "bar", "C": "baz"})
    test("echo $A'$B'$C'A'$B'$C'", exports={"A": "foo", "B": "bar", "C": "baz"})
    test('echo $A"$B"$C"A"$B"$C"', exports={"A": "foo ", "B": " bar  ", "C": "baz "})
    test("echo $A'$B'$C'A'$B'$C'", exports={"A": "foo ", "B": " bar  ", "C": "baz "})
    test("echo $A")
    test("echo $A$B")
    test("echo $A$B$C")
    test("echo $A$B$C$D")
    test("echo [$A]", exports={"A": r"bonjour\je"})
    test("echo [$A]", exports={"A": r"\b\\o\\\nj\\\\\\\our\\je\\\\"})
    test("echo [$A]", exports={"A": r"   \b\\o\\\nj\\\\\\\our\\je\\\\"})
    test("echo [$A]", exports={"A": r"\b\\o\\\nj\\\\\\\our\\je\\\\   "})
    test("echo [$A]", exports={"A": r"  \b\\o\\\nj\\\\\\\our\\je\\\\ "})
    test("echo [$A]", exports={"A": r"a  \b\\o\\\nj\\\\\\\our\\je\\\\ b"})
    test("echo [$A]", exports={"A": r" a  \b\\o\\\nj\\\\\\\our\\je\\\\ b "})
    test("echo [$A]", exports={"A": r" "})
    test("echo [$A]", exports={"A": r"    "})
    test("echo [$A]", exports={"A": r"\ "})
    test("echo [$A]", exports={"A": r" \  "})
    test(r"echo \ \ \ \ \ \ \ $A\ \ \ \ \ \ ", exports={"A": "bonjour"})
    test(r"echo \ \ \ \ \ \ \ $A\ \ \ \ \ \ ", exports={"A": "bonjour je suis"})
    test(r"echo \ \ \ \ \ \ \ $A\ \ \ \ \ \ ", exports={"A": "  bonjour je suis  "})
    test('echo $A',      exports={"A": "bonjour je suis splited"})
    test('echo $A',      exports={"A": "bonjour     je     suis    splited"})
    test('echo $A',      exports={"A": "   bonjour     je     suis    splited   "})
    test('echo [$A]',    exports={"A": "bonjour je suis splited"})
    test('echo [$A]',    exports={"A": "bonjour     je     suis    splited"})
    test('echo [$A]',    exports={"A": "   bonjour     je     suis    splited   "})
    test('echo "[$A]"',  exports={"A": "bonjour je suis splited"})
    test('echo "[$A]"',  exports={"A": "bonjour     je     suis    splited"})
    test('echo "[$A]"',  exports={"A": "   bonjour     je     suis    splited   "})
    test('echo \\ $A',   exports={"A": "bonjour je suis splited"})
    test('echo \\ $A',   exports={"A": "bonjour     je     suis    splited"})
    test('echo \\ $A',   exports={"A": "   bonjour     je     suis    splited   "})
    test('echo $A\\ ',   exports={"A": "bonjour je suis splited"})
    test('echo $A\\ ',   exports={"A": "bonjour     je     suis    splited"})
    test('echo $A\\ ',   exports={"A": "   bonjour     je     suis    splited   "})
    test('echo $A$A$A',  exports={"A": "   bonjour     je     suis    splited   "})
    test("echo $A",      exports={"A": "'" + config.LOREM + "'"})
    test('echo "$A"',    exports={"A": "'" + config.LOREM + "'"})
    test("echo '$A'",    exports={"A": "'" + config.LOREM + "'"})
    test("$ECHO $ECHO",  exports={"ECHO": "echo"})
    test("$A$B bonjour", exports={"A": "ec", "B": "ho"})
    test("$LS",          exports={"LS": "ls -l"}, setup="touch a b c")
    test("echo $")
    test("echo \\$")
    test("echo \\$\\$\\$\\$")
    test("echo \\$$\\$$")
    test("echo $\\A $\\B",     exports={"A": "a", "B": "b"})
    test("echo $\\A$\\B",      exports={"A": "a", "B": "b"})
    test("echo $A",            exports={"A": " "})
    test("echo $A",            exports={"A": "  "})
    test("echo $A",            exports={"A": "   "})
    test("echo $A",            exports={"A": "    "})
    test("echo $A",            exports={"A": "  a "})
    test("echo $A",            exports={"A": "                                "})
    test("echo $A",            exports={"A": "                     a          "})
    test("echo @$A@",          exports={"A": " "})
    test("echo @ $A@",         exports={"A": " "})
    test("echo @$A @",         exports={"A": " "})
    test("echo @$A@",          exports={"A": "       "})
    test("echo '@'$A'@'",      exports={"A": " "})
    test("echo '@' $A'@'",     exports={"A": " "})
    test("echo '@'$A '@'",     exports={"A": " "})
    test('echo "@"$A"@"',      exports={"A": " "})
    test('echo "@" $A"@"',     exports={"A": " "})
    test('echo "@"$A "@"',     exports={"A": " "})
    test('echo @"$A"@',        exports={"A": " "})
    test('echo @ "$A"@',       exports={"A": " "})
    test('echo @"$A" @',       exports={"A": " "})
    test('echo @"$A"@',        exports={"A": "       "})
    test("echo '@'\"$A\"'@'",  exports={"A": " "})
    test("echo '@' \"$A\"'@'", exports={"A": " "})
    test("echo '@'\"$A\" '@'", exports={"A": " "})
    test('echo "@""$A""@"',    exports={"A": " "})
    test('echo "@" "$A""@"',   exports={"A": " "})
    test('echo "@""$A" "@"',   exports={"A": " "})
    test('echo $A$B$C',        exports={"A": "", "B": "", "C": ""})


@suite()
def suite_escape(test):
    """ escape test, in command, with space, before quote """
    test(r"echo \a")
    test(r"\e\c\h\o bonjour")
    test(r"echo charles\ ")
    test(r"echo \ \ jesuis\ \ charles")
    test(r"echo \ \ jesuis\; \ charles")
    test(r"echo \ \ jesuis\&\& \ charles")
    test(r"echo \ \ jesuis\|\| \ charles")
    test(r"echo \ \ jesuis \|\| \ charles")
    test(r"echo \ \ jesuis\; \ charles")
    test(r"echo \ \ \ \ \ \ \ \ ")
    test(r"echo \ \ \ \ \ \ \ \               \ \ \ \ \ \ ")
    test(r"echo \$PATH")
    test(r"echo \$\P\A\T\H")
    test(r"echo\ bonjour")
    test(r"\ echo bonjour")
    test(r" \ echo bonjour")
    test(r"                 \ echo bonjour")
    test(r" \                 echo bonjour")
    test(r"                 \                    echo bonjour")
    test(r'/bin/echo " \  "')
    test(r'/bin/echo " \" "')
    test(r'/bin/echo " \' "')
    test(r'/bin/echo " \a "')
    test(r'/bin/echo " \b "')
    test(r'/bin/echo " \| "')
    test(r'/bin/echo " \! "')
    test(r'/bin/echo " \@ "')
    test(r'/bin/echo " \$ "')
    test(r'/bin/echo " \$LESS "')
    test(r'/bin/echo " \$? "')
    test(r'/bin/echo " \\ "')
    test(r'/bin/echo " \\\ "')
    test(r'/bin/echo " \\\\ "')
    test(r'/bin/echo " \\\\\ "')
    test(r'/bin/echo " \\\\\\ "')
    test(r'/bin/echo " \\\\\\\ "')
    test(r'/bin/echo " \\\\\\\\ "')
    test(r"/bin/echo ' \  '")
    test(r"/bin/echo ' \" '")
    test(r"/bin/echo ' \a '")
    test(r"/bin/echo ' \b '")
    test(r"/bin/echo ' \| '")
    test(r"/bin/echo ' \! '")
    test(r"/bin/echo ' \@ '")
    test(r"/bin/echo ' \$ '")
    test(r"/bin/echo ' $LESS '")
    test(r"/bin/echo ' \$? '")
    test(r"/bin/echo ' \\ '")
    test(r"/bin/echo ' \\\ '")
    test("echo \\", hook=hooks.delete_escape)
    test("echo \"\\\"\"'bonjour'")


@suite()
def suite_spaces(test):
    """ field splitting with spaces and tabs """
    test("echo foo")
    test("echo                    foo")
    test("             echo foo")
    test("echo foo             ")
    test("         echo           foo             ")
    test("echo\t\t\t\t\t\t\t\t\t\tfoo")
    test("\t\t\t\t\t\techo\tfoo")
    test("echo\tfoo\t\t\t\t\t\t")
    test("\t\t\t\techo\t\t\t\tfoo\t\t\t\t")
    test("")
    test("                                          ")
    test("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t")
    test("            \t\t\t           \t\t\t       ")


# @suite(bonus=True)
# def suite_glob(test):
#     test("echo *")
#     test("echo *", setup="touch a b c")
#     test("echo *.c", setup="touch a b c foo.c bar.c")
#     test("echo src/*.c", setup="mkdir src; touch src/a src/b src/c src/foo.c src/bar.c")
#     test("echo */*.c", setup="mkdir src; touch src/a src/b src/c src/foo.c src/bar.c")
#     test("echo */*.c",
#             setup="mkdir src; touch src/a src/b src/c src/foo.c src/bar.c;\
#                    mkdir inc; touch inc/a inc/b inc/c inc/foo.c inc/bar.c")
#     test("echo */*.h",
#             setup="mkdir src; touch src/a src/b src/c src/foo.c src/bar.c;\
#                    mkdir inc; touch inc/a inc/b inc/c inc/foo.h inc/bar.h")
#     test("echo l1/*/l3/*/*",
#             setup="mkdir -p l1/l2_1/l3; mkdir -p l1/l2_2; cd l1/l2_1/l3;\
#                    mkdir src; touch src/a src/b src/c src/foo.c src/bar.c;\
#                    mkdir inc; touch inc/a inc/b inc/c inc/foo.h inc/bar.h;\
#                    cd ../../..; cd l1/l2_2; touch bonjour je suis")
#
#     test("echo */*/*/*/*.c",
#             setup="mkdir -p l1/l2/l3; cd l1/l2/l3;\
#                    mkdir src; touch src/a src/b src/c src/foo.c src/bar.c;\
#                    mkdir inc; touch inc/a inc/b inc/c inc/foo.h inc/bar.h")
#     test("echo */*/*/*/*.h",
#             setup="mkdir -p l1/l2/l3; cd l1/l2/l3;\
#                    mkdir src; touch src/a src/b src/c src/foo.c src/bar.c;\
#                    mkdir inc; touch inc/a inc/b inc/c inc/foo.h inc/bar.h")
#
#     test("echo */*/*/*.c",
#             setup="mkdir -p l1/l2/l3; cd l1/l2/l3;\
#                    mkdir src; touch src/a src/b src/c src/foo.c src/bar.c;\
#                    mkdir inc; touch inc/a inc/b inc/c inc/foo.h inc/bar.h")
#     test("echo */*/*/*.h",
#             setup="mkdir -p l1/l2/l3; cd l1/l2/l3;\
#                    mkdir src; touch src/a src/b src/c src/foo.c src/bar.c;\
#                    mkdir inc; touch inc/a inc/b inc/c inc/foo.h inc/bar.h")
#
#     test("echo */*/*/*/*/*.c",
#             setup="mkdir -p l1/l2/l3; cd l1/l2/l3;\
#                    mkdir src; touch src/a src/b src/c src/foo.c src/bar.c;\
#                    mkdir inc; touch inc/a inc/b inc/c inc/foo.h inc/bar.h")
#     test("echo */*/*/*/*/*.h",
#             setup="mkdir -p l1/l2/l3; cd l1/l2/l3;\
#                    mkdir src; touch src/a src/b src/c src/foo.c src/bar.c;\
#                    mkdir inc; touch inc/a inc/b inc/c inc/foo.h inc/bar.h")
#
#     test("echo /*")
#     test("echo /etc/*")
#     test("echo /usr/include/*.h")
#     # test("echo /*/*", timeout=10)
#     # test("echo /usr/*/*", timeout=10)
#     test("echo /usr/*")
#     test("echo /dev/*")
#     test("echo /etc/*")
#     test("echo /root/*")
#     test("echo /usr*")
#     test("echo /dev*")
#     test("echo /etc*")
#     test("echo /root*")
#
#     test("echo *nothing")
#     test("echo nothing*")
#     test("echo *nothing*")
#
#     test("echo a*b", setup="touch ab aab aaaaab aaaaaaaab acccccb acb abbbb")
#     test("echo a**b", setup="touch ab aab aaaaab aaaaaaaab acccccb acb abbbb")
#     test("echo a***b", setup="touch ab aab aaaaab aaaaaaaab acccccb acb abbbb")
#     test("echo a****b", setup="touch ab aab aaaaab aaaaaaaab acccccb acb abbbb")
#
#     test("echo **")
#     test("echo **", setup="touch a b c")
#     test("echo **", setup="mkdir d; touch d/a d/b d/c")
#     test("echo */*", setup="mkdir d; touch d/a d/b d/c")
#     test("echo */a", setup="mkdir d; touch d/a d/b d/c")
#     test("echo d/*", setup="mkdir d; touch d/a d/b d/c")
#
#     test("*")
#     test("*", setup="touch a b c")
#     test("*.c", setup="touch a b c foo.c bar.c")
#     test("src/*.c", setup="mkdir src; touch src/a src/b src/c src/foo.c src/bar.c")
#     test("*/*.c", setup="mkdir src; touch src/a src/b src/c src/foo.c src/bar.c")
#     test("*/*.c",
#             setup="mkdir src; touch src/a src/b src/c src/foo.c src/bar.c;\
#                    mkdir inc; touch inc/a inc/b inc/c inc/foo.c inc/bar.c")
#
#     test("export A=*; echo $A")
#     test("A=*; echo $A")
#
#     test("echo *", setup="mkdir d1; touch d1/a d1/b d1/c; ln -s d1 d1link")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; ln -s d1 d1link")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; ln -s d1 .d1link")
#     test("echo */*", setup="mkdir .d1; touch .d1/a .d1/b .d1/c; ln -s .d1 d1link")
#     test("echo .*/*", setup="mkdir d1; touch d1/a d1/b d1/c; ln -s d1 .d1link")
#     test("echo .*/*", setup="mkdir .d1; touch .d1/a .d1/b .d1/c; ln -s .d1 d1link")
#
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 000 d1/a")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 001 d1/a")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 002 d1/a")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 003 d1/a")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 004 d1/a")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 005 d1/a")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 006 d1/a")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 007 d1/a")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 010 d1/a")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 020 d1/a")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 030 d1/a")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 040 d1/a")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 050 d1/a")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 060 d1/a")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 070 d1/a")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 100 d1/a")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 200 d1/a")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 300 d1/a")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 400 d1/a")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 500 d1/a")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 600 d1/a")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 700 d1/a")
#
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 755 d1/a")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 644 d1/a")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 311 d1/a")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 111 d1/a")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 222 d1/a")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 333 d1/a")
#
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 000 d1")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 001 d1")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 002 d1")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 003 d1")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 004 d1")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 005 d1")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 006 d1")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 007 d1")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 010 d1")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 020 d1")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 030 d1")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 040 d1")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 050 d1")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 060 d1")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 070 d1")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 100 d1")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 200 d1")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 300 d1")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 400 d1")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 500 d1")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 600 d1")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 700 d1")
#
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 755 d1")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 644 d1")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 311 d1")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 111 d1")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 222 d1")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 333 d1")
#
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 0777 d1/a")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 1000 d1/a")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 2000 d1/a")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 3000 d1/a")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 4000 d1/a")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 5000 d1/a")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 6000 d1/a")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 7000 d1/a")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 1777 d1/a")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 2777 d1/a")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 3777 d1/a")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 4777 d1/a")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 5777 d1/a")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 6777 d1/a")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 7777 d1/a")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 0000 d1/a")
#
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 0777 d1")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 1000 d1")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 2000 d1")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 3000 d1")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 4000 d1")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 5000 d1")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 6000 d1")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 7000 d1")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 1777 d1")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 2777 d1")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 3777 d1")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 4777 d1")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 5777 d1")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 6777 d1")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 7777 d1")
#     test("echo */*", setup="mkdir d1; touch d1/a d1/b d1/c; chmod 0000 d1")
#
#     test("echo *", setup="touch a; ln -s a b")
#     test("echo *", setup="touch a; ln -s a b; ln -s b c")
#     test("echo *", setup="touch a; ln -s a b; ln -s b c; ln -s c d")
#     test("echo d/*", setup="mkdir d; touch a b c d/d d/e d/f")
#     test("echo d/*", setup="mkdir d; touch a b c d/d d/e d/f; chmod 000 d")
#     test(r"echo \*", setup="touch a b c")
#     test(r"echo \*\*", setup="touch a b c")
#     test(r"echo \ *", setup="touch a b c")
#     test(r"echo *\.c", setup="touch a.c b.c c.c")
#     test(r"echo *.\c", setup="touch a.c b.c c.c")
#     test(r"echo *.c\ ", setup="touch a.c b.c c.c")
#     test("echo $A$B",
#             setup="mkdir src; touch src/a src/b src/c src/foo.c src/bar.c;\
#                    mkdir inc; touch inc/a inc/b inc/c inc/foo.c inc/bar.c",
#             exports={"A": "*", "B": "/*.c"})
#     test("echo $A$B",
#             setup="mkdir src; touch src/a src/b src/c src/foo.c src/bar.c;\
#                    mkdir inc; touch inc/a inc/b inc/c inc/foo.c inc/bar.c",
#             exports={"A": "*/.", "B": "*.c"})
