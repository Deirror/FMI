# Да се напише shell скрипт, който приема произволен брой аргументи - имена на файлове или директории.
# Скриптът да извежда за всеки аргумент подходящо съобщение:
#	- дали е файл, който може да прочетем
#	- ако е директория - имената на файловете в нея, които имат размер, по-малък от броя на файловете в директорията

#!/bin/bash

if [[ $# -lt 1 ]]; then
    echo "At least one argument required"
    exit 1
fi

for o in "$@"; do
    if [[ ! -f "$o" && ! -d "$o" ]]; then
        continue
    fi
    if [[ -f "$o" && -r "$o" ]]; then
        echo "$o is readble"
    elif [[ -d "$o" ]]; then
        dir_count=$(find "$o" -mindepth 1 -maxdepth 1 -type d | wc -l)
        echo "$o :"
        find "$o" -mindepth 1 -maxdepth 1 -type f -size -"${dir_count}c"
    fi
done
