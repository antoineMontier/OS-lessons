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

delete_o