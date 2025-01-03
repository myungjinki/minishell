# ############################################################################ #
#                                                                              #
#                                                         :::      ::::::::    #
#    misc.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cacharle <me@cacharle.xyz>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/10 13:06:19 by cacharle          #+#    #+#              #
#    Updated: 2020/10/24 13:39:48 by charles          ###   ########.fr        #
#                                                                              #
# ############################################################################ #

from suite import suite


@suite()
def suite_shlvl(test):
    """ test for the SHLVL variable """
    test("echo $SHLVL")
    test("echo $SHLVL", exports={"SHLVL": ""})
    test("echo $SHLVL", exports={"SHLVL": " 1"})
    test("echo $SHLVL", exports={"SHLVL": " 2"})
    test("echo $SHLVL", exports={"SHLVL": " 3"})
    test("echo $SHLVL", exports={"SHLVL": " ' 3'"})
    test("echo $SHLVL", exports={"SHLVL": " '\t3'"})
    test("echo $SHLVL", exports={"SHLVL": " '\t\f\r 3'"})
    test("echo $SHLVL", exports={"SHLVL": " '3 '"})
    test("echo $SHLVL", exports={"SHLVL": " '3\t'"})
    test("echo $SHLVL", exports={"SHLVL": " '3\r'"})
    test("echo $SHLVL", exports={"SHLVL": " '3\t\f\r '"})
    test("echo $SHLVL", exports={"SHLVL": " '3     a'"})
    test("echo $SHLVL", exports={"SHLVL": " '3\t\t\ta'"})
    test("echo $SHLVL", exports={"SHLVL": " 0"})
    test("echo $SHLVL", exports={"SHLVL": " -0"})
    test("echo $SHLVL", exports={"SHLVL": " -1"})
    test("echo $SHLVL", exports={"SHLVL": " 255"})
    test("echo $SHLVL", exports={"SHLVL": " 256"})
    test("echo $SHLVL", exports={"SHLVL": " 2000000"})
    test("echo $SHLVL", exports={"SHLVL": " -2000000"})
    test("echo $SHLVL", exports={"SHLVL": " 2147483647"})
    test("echo $SHLVL", exports={"SHLVL": " -2147483648"})
    test("echo $SHLVL", exports={"SHLVL": " 2147483648"})
    test("echo $SHLVL", exports={"SHLVL": " -2147483649"})
    test("echo $SHLVL", exports={"SHLVL": " 3147483648"})
    test("echo $SHLVL", exports={"SHLVL": " -3147483649"})
    test("echo $SHLVL", exports={"SHLVL": " 4294967295"})
    test("echo $SHLVL", exports={"SHLVL": " 4294967296"})
    test("echo $SHLVL", exports={"SHLVL": " -9223372036854775808"})
    test("echo $SHLVL", exports={"SHLVL": " 9223372036854775807"})
    test("echo $SHLVL", exports={"SHLVL": " -9223372036854775809"})
    test("echo $SHLVL", exports={"SHLVL": " 9223372036854775808"})
    test("echo $SHLVL", exports={"SHLVL": " 18446744073709551615"})
    test("echo $SHLVL", exports={"SHLVL": " 18446744073709551616"})
    test("echo $SHLVL", exports={"SHLVL": " +1"})
    test("echo $SHLVL", exports={"SHLVL": " +2"})
    test("echo $SHLVL", exports={"SHLVL": " +3"})
    test("echo $SHLVL", exports={"SHLVL": " +0"})
    test("echo $SHLVL", exports={"SHLVL": " +255"})
    test("echo $SHLVL", exports={"SHLVL": " +256"})
    test("echo $SHLVL", exports={"SHLVL": " +2000000"})
    test("echo $SHLVL", exports={"SHLVL": " +2147483647"})
    test("echo $SHLVL", exports={"SHLVL": " ++1"})
    test("echo $SHLVL", exports={"SHLVL": " ++2"})
    test("echo $SHLVL", exports={"SHLVL": " ++3"})
    test("echo $SHLVL", exports={"SHLVL": " ++0"})
    test("echo $SHLVL", exports={"SHLVL": " ++255"})
    test("echo $SHLVL", exports={"SHLVL": " ++256"})
    test("echo $SHLVL", exports={"SHLVL": " ++2000000"})
    test("echo $SHLVL", exports={"SHLVL": " ++2147483647"})
    test("echo $SHLVL", exports={"SHLVL": " --1"})
    test("echo $SHLVL", exports={"SHLVL": " --2"})
    test("echo $SHLVL", exports={"SHLVL": " --3"})
    test("echo $SHLVL", exports={"SHLVL": " --0"})
    test("echo $SHLVL", exports={"SHLVL": " --255"})
    test("echo $SHLVL", exports={"SHLVL": " --256"})
    test("echo $SHLVL", exports={"SHLVL": " --2000000"})
    test("echo $SHLVL", exports={"SHLVL": " --2147483647"})
    test("echo $SHLVL", exports={"SHLVL": " bonjour"})
    test("echo $SHLVL", exports={"SHLVL": " 0_"})
    test("echo $SHLVL", exports={"SHLVL": " _0"})
    test("echo $SHLVL", exports={"SHLVL": " 0123456789"})
    test("echo $SHLVL", exports={"SHLVL": " -0123456789"})
    test("echo $SHLVL", exports={"SHLVL": " 00000000000000000000000000000000000000000000001"})
    test("echo $SHLVL", exports={"SHLVL": " 00000000000000000000000000000000000000000000000"
         "00000000000000000000000000000000000000000000001"})
