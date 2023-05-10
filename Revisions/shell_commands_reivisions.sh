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

for ((i=0 ; i<20 ; i++))
do
    fibo_string $i
done