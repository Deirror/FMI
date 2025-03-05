# В текущата директория има само обикновени файлове (без директории). Да се напише
# bash script, който приема 2 позиционни параметъра– числа, който мести файловете от текущата ди
# ректория към нови директории (a, b и c, които трябва да бъдат създадени), като определен файл се
# мести към директория ’a’, само ако той има по-малко редове от първи позиционен параметър, мести
# към директория ’b’, ако редове са между първи и втори позиционен параметър и в ’c’ в останалите случаи

#!/bin/bash

if [[ $# -ne 2 ]]; then
    echo "Exatcly 2 numbers are required"
    exit 1
fi

for num in $@; do
    if [[ ! "$num" =~ [0-9]+ ]]; then
        echo "Only whole numbers allowed"
        exit 2
    fi
done

mkdir -p ./a ./b ./c

while read file; do
    lines=$(cat "$file" | wc -l)
    if [[ lines -lt $1 ]]; then
        mv "$file" ./a
    elif [[ lines -ge $1 && lines -le $2 ]]; then
        mv "$file" ./b
    else
        mv "$file" ./c
    fi
done < <(find ./ -type f)
