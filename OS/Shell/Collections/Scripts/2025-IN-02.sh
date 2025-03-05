# Вашите колеги от съседната лаборатория имат нужда да автоматизират периодичното създаване на
# определен вид конфигурационни файлове на база на съществуващ текстови файл (map.txt) с изисквания.
# Всеки ред на файла гарантирано се състои от три думи (малки латински букви), разделени с whitespace

#!/bin/bash

if [[ $# -ne 2 ]]; then
    echo "Expected two args"
    exit 1
fi

DOMAIN=$1
MAP=$2

if [[ ! -f "$MAP" ]]; then
    echo "$MAP doesn't exist as a file"
    exit 2
fi

while read TEAM; do
    echo "; team $TEAM"
    grep "$TEAM" "$MAP" | awk -F ' ' -v domain=$DOMAIN '{ printf $2"\tIN NS\t"$1"."domain".\n" }'
done < <(cat "$MAP" | cut -d ' ' -f 3 | sort | uniq)
