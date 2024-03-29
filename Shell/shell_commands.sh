#! /usr/bin/bash

#write a script to count the number executable files in the current directory
function nb_execution {
    nb=0
    for i in `ls`; do
        if [ -x $i -a -f $i ] #-x = executable // -a = and // -f = file (not a directory)
        then 
            nb=$[ $nb + 1 ] ; 
        fi
    done
    echo "executable file number : $nb"
}

#write a script to calculate the total octet size of the executables files in the current directory
function total_size {
    nb=0
    for i in `ls`; do
        if [ -x $i -a -f $i ]
        then
            set `wc -c $i`      #wc -c counts the number of char + add the file name at the end of line ; set folds in $1 the char number and $2 the file name
            nb=$[ $nb +  $1 ] ;
        fi
    done
    echo "executable file total bytes : $nb"
}

#write a script to display every .c of the directory

function print_c {
    find . -name "*.c" -print
}

#write a script to delete every ~ or .bak file in the arborescence
function rm_useless {
    find . \( -name "*~" -o -name "*.bak" \) -exec rm {} \;     # '\' stands for despeciallisation of the parenthesis ; -o stands for OR ; {} stands for everything he found
}

nb_execution