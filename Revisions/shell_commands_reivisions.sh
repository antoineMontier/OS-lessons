#! /usr/bin/bash

function count_files {
    nb=0
    for i in `ls`; do
        nb=$[ $nb + 1 ]
    done
    echo "file number $nb"
}

function fibo {
    if(($1<=1)) ; then 
        echo $1 
    else 
        one=$(expr $1 - 1)
        fibo_one=$(fibo $one)
        two=$(expr $1 - 2)
        fibo_two=$(fibo $two)
        calc=$(expr $fibo_one + $fibo_two)
        echo $calc
    fi
}

function fibo_string {
    nb=$(fibo $1)
    echo "fibo($1) = $nb"
}

function factorial {
    if(($# != 1)) ; then
        echo "provide 1 argument for factorial function"
    elif (($1 <= 1)) ; then
        echo 1
    else
        echo $(expr $1 \* $(factorial $(expr $1 \- 1)))
    fi
}

function factorials {
    for((i=0 ; i\<11 ; i++)) ; do 
        nb=$(factorial $i)
        echo "$i! = $nb"
    done
}

# delete .o files if .c files exist
function delete_o {
    for file_o in $(find . -name "*.o") ; do
        for file_c in $(find . -name "*.c") ; do
            echo "file_o = $file_o  file_c = $file_c"
            if [ "$(basename "$file_o" .o)" == "$(basename "$file_c" .c)" ] ; then
                exec rm $file_o
            fi
        done 
    done
}

# function that counts number of executable files in the directory
function exec_count {
    file_list=`ls`
    nb=0
    for i in $file_list; do
        if [ -x $i ] ; then
            nb=$(expr $nb \+ 1)
        fi
    done
    echo $nb
}

# function that counts number of directories in a directory
function dir_count {
    file_list=`ls`
    nb=0
    for i in $file_list ; do
        if ! [ -f $i ] ; then
            nb=$(expr $nb \+ 1)
        fi
    done
    echo $nb
}

# function that prints args
function print_args {
    echo "executable name : $0"
    nb=0
    for i in $* ; do
        echo "\$$nb = $i"
        nb=$[ $nb + 1 ]
    done
    echo "\$# = $nb"
}

function arg_inversion {
    echo "before"
    print_args $*
    case $# in
    1)
        echo "one arg";;
    2)
        set -- $2 $1;;
    3) 
        set - $3 $2 $1;;
    4)
        set -- $4 $3 $2 $1;;
    5) 
        set -- $5 $4 $3 $2 $1;;
    6) 
        set -- $6 $5 $4 $3 $2 $1;;
    *)
        echo "unknown arg";;
    #set -- $4 $3 $2 $3 $1 $0
    esac
    echo "after"
    print_args $*
}

arg_inversion $*
