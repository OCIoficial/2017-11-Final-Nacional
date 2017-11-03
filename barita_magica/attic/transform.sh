#!/usr/bin/env bash

mkdir -p cases/txt
mkdir cases/img

for i in {0..9}; do
    mkdir cases/txt/$i
    mkdir cases/img/$i
done

for f in imagenes_iniciales/*.png;
do
    for i in 3 6 9 357 354 351 360
    do
        for x in -4 -2 0 2 4
        do
            for y in -4 -2 0 2 4
            do
                filename=$(basename "$f")
                extension="${filename##*.}"
                filename="${filename%.*}"

                out=$(printf "%s_rot_%d_%d_%d.png" $filename $i $x $y)
                echo $out

                filename=$(basename "$out")
                extension="${filename##*.}"
                filename="${filename%.*}"
                folder=$(echo $filename | cut -f1 -d "_")

                convert -background none -distort SRT "32,32 1 $i $((32+$x )),$(( 32+$y ))" $f cases/img/$folder/$out
                python bitmap_to_matrix.py cases/img/$folder/$out > cases/txt/$folder/$out.txt
            done
        done
    done
done