# Да се напише shell скрипт, който приема два параметъра - име на директория и число.
# Скриптът да извежда на стандартния изход имената на всички обикновени файлове във директорията,
# които имат размер, по-голям от подаденото число

#!/bin/bash

if [[ $# -ne 2 ]]; then
    echo "Expected two arguments"
    exit 1
fi

if [[ ! -d $1 ]]; then
    echo "Invalid dirname"
    exit 1
fi

if [[ ! "$2" =~ ^[0-9]+$ ]]; then
    echo "Second argument is not a number"
    exit 1
fi

while read file; do
    size=$(ls -s $file | cut -d ' ' -f 1)
    if [[ $size -gt $2 ]]; then
        echo "$file has $size bytes"
    fi
done < <(find $1 -mindepth 1 -maxdepth 1 -type f)
