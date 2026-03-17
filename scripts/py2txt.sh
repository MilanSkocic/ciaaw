#!/usr/bin/env bash

fpath="./srcprep/pyapi.txt"
i=0

echo "    Python API:" > $fpath

while IFS='' read -r lineraw; do
    line=$(echo $lineraw | sed -E 's/^[[:space:]]*//')
    case $line in
        "def"*":"*)
            echo "        o $(echo $line | sed -E 's/def //g;;s/:*$//g')" >> $fpath
            ;;
        *)
            ;;
    esac
done < $1
