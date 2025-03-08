# Напишете скрипт, който получава задължителен първи позиционен параметър– директория и незадължителен втори–число.
# Скриптът трябва да проверява подадената директория и нейните под-директории и да извежда имената на:
# а) при подаден на скрипта втори параметър– всички файлове с брой hardlink-ове поне равен на параметъра
# б) прилипса на втори параметър–всички symlink-ове с несъществуващ destination(счупени symlinkове)

#!/bin/bash

if [[ $# -lt 1 || $# -gt 2 ]]; then
    echo "Invalid count of arguments"
    exit 1
fi

DIR="$1"

if [[ ! -d "$DIR" ]]; then
    echo "Dir doesn't exist"
    exit 2
fi

case '$#' in
'1')
while read SYMLINK; do
    if ! readlink -e "$SYMLINK" &>/dev/null; then
        echo "$SYMLINK"
    fi
done < <(find "$DIR" -type l);;
'2')
MIN_COUNT=$2
if [[ ! "$MIN_COUNT" =~ ^[0-9]+$ ]]; then
    echo "Argumnet not an integer"
    exit 3
fi  
while read FILE; do
    LINKS_COUNT=$(stat -c "%h" "$FILE")
    if [[ $LINKS_COUNT -ge $MIN_COUNT ]]; then
        echo "$FILE"
    fi
done < <(find "$DIR" -type f);;
esac
