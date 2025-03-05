# Напишете shell скрипт, който по подаден един позиционен параметър, ако този параметър
# е директория, намира всички symlink-ове в нея и под-директориите ѝ с несъществуващ destination

#!/bin/bash

if [[ $# -ne 1 ]]; then
    echo "Only one arg needed"
    exit 1
fi

if [[ ! -d "$1" ]]; then
    echo "Not a directory"
    exit 2
fi

while read file; do
    if [[ ! -e "$file" ]]; then
        echo "$file"
    fi
done < <(find "$1" -type l 2>/dev/null | xargs -I{} readlink {})
