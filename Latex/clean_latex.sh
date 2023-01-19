#! /usr/bin/bash

#count the arg numbers after calling the ./clean_latex.sh arg1 arg2 arg3
check_if_one_arg_v1() {               
    if [ $1 -ne 1 ] ; then                       #$1 is the first argument $2 the second.... ; -ne stands for non equals
        echo -e "no arguments \n" # -e stands for expression
        exit 1
    fi
}

check_if_one_arg_v2() {               
    if [ $# -ne 1 ] ; then                       #$1 is the first argument $2 the second.... ; -ne stands for non equals
        echo -e "no arguments \n" # -e stands for expression
        exit 1
    fi
}

check_if_one_arg_v1 $#       # $# stands for number of arguments of the function / script
check_if_one_arg_v2 $*       # $* copy the arguments