# Да се напише shell скрипт, който приема произволен брой аргументи - имена на файлове.
# Скриптът да прочита от стандартния вход символен низ и за всеки от зададените файлове извежда
# по подходящ начин на стандартния изход броя на редовете, които съдържат низа.

#!/bin/bash

if [[ $# -lt 1 ]]; then
    echo "At least one file name required"
    exit 1
fi

read str

for file in $@; do
    if [[ ! -f $file ]]; then
        continue
    fi
    lines=$(grep "$str" $file | wc -l)
    if [[ lines -gt 0 ]]; then
        echo "$file - $lines" 
    fi
done
