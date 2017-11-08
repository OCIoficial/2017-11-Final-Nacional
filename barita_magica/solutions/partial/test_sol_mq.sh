#!/usr/bin/env bash

# asume que existen los archivos ./txt/{0..9}/*.txt

for f in `ls txt`
do
    for d in `ls txt/$f`
    do
        echo $f `python mquezada.py < txt/$f/$d` >> sol_mq.out
    done
done
