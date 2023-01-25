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

function clearf { #clear .log and .aux files (founded from HOME : ~)
    find /HOME -name "*.aux" -exec rm
    find /HOME -name "*.log" -exec rm
}

function clearf2 {
    find $HOME \( -name "*.log"  -o -name "*.aux" \) -exec rm -f {} \; 2>dev/null #dev/null is a trash file
}

ps_pdf_rm() {
    if [ $# -ne 1 ] ; then
        echo -e "ps_pdf_rm needs the path as an argument \n"
        exit 1
    fi
    acutalPath=pwd
    cd $1
    rm *.pdf
    rm *.ps
    cd $acutalPath
}



function clearall { #calls clear + delete X.ps and X.pdf if X.dvi exists
    clearf2
    for [ i in `find $HOME -name "*.dvi"`]
    do
        file_name = ${i%dvi} #parse the output
        #to merge two strings, just write them next to another
        if [ -f $file_name"ps" ] ; then
            \rm -f $file_name"ps"
        fi
        if [ -f $file_name"pdf" ] ; then    #-f stands for find
            \rm -f $file_name"pdf"
        fi
    done 
}