#! /usr/bin/bash

function count_files {
    nb=0
    for i in `ls`; do
        nb=$[ $nb + 1 ]
    done
    echo "file number $nb"
}



count_files