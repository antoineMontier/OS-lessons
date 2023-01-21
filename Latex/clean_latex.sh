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

function clear { #clear .log and .aux files (founded from HOME : ~)
    find /HOME -name "*.aux" -exec rm
    find /HOME -name "*.log" -exec rm
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

function simpleRemove {
    rm *.pdf
    rm *.ps
}

function clearall { #calls clear + delete X.ps and X.pdf if X.dvi exists
    clear
    find /HOME -name "*.dvi" -exec simpleRemove 
}