#!/usr/bin/env bash

fpath="./srcprep/fapi.txt"
i=0
func=0

echo "    Fortran API:" > $fpath

while IFS='' read -r lineraw; do
    line=$(echo $lineraw | sed -E 's/^[[:space:]]*//')
    case $line in
        "function"*"("*")"*)
            func=1
            echo  -n "        o $line" >> $fpath
            ;;
        "subroutine"*"("*")"*)
            func=1
            echo  -n "        o $line" >> $fpath
            ;;
        "end function"*)
            func=0
            ;;
        "end subroutine"*)
            func=0
            ;;
        "!! "*)
            if [[ $func == 1 ]]; then
                echo     "  $(echo $line | sed -E 's/!! //g')" >> $fpath
            fi
            ;;
        *"::"*"!!"*)
            if [[ $func == 1 ]]; then
                echo    "             o $(echo $line | sed -E 's/!/ /g')" >> $fpath
            fi
            ;;
        *)
            ;;
    esac
done < $1
