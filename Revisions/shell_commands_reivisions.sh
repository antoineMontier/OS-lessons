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
        echo $(expr $(fibo $(expr $1 \- 1)) + $(fibo $(expr $1 \- 2)))
    fi
}

function fibo_it {
    if(($# != 1)) ; then
        echo "provide 1 argument for fibo_it, you provided $#"
    else
        case $1 in
        0)
            echo 0;;
        1)
            echo 1;;
        2)
            echo 1;;
        *)
            a=1
            b=0
            c=0
            for((i=0 ; i<$1 ; i++)) ; do
                c=$(expr $a + $b )
                b=$a
                a=$c
            done
            echo $b
        ;;
        esac
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
    0)
        echo "no args";;
    1)
        echo "one arg";;
    *)
        echo "a" ;;
    esac
    echo "after"
    print_args $*
}

print_args $*
for((i=0 ; i<=100 ; i++)) ; do
    val=$( fibo_it $i )
    echo "fibo($i) = $val"
done
