# Министерството на Истината ви поставя спешна задача: да напишете скрипт replace.sh, който за
# мества думи в определени текстове.
# replace.sh
# приема следните два типа валидни аргументи:
# • Файл:произволен низ, не-започващ с тире, интерпретиран като име на файл
# • Замяна: аргумент от вида-R<дума1>=<дума2>
# Редът на аргументите няма значение, а броят им може да е произволен.
# ...
# коментар: скрипта бачка

#!/bin/bash

if [[ $# -lt 2 ]]; then
    echo "Two or more args needed"
    exit 1
fi

ARGS=""

for ARG in $@; do
    ARGS+="$ARG"$'\n'
done

FILENAME=$(grep -v "^-R" <<< "$ARGS")
if [[ $(wc -l <<< "$FILENAME") -ne 1 ]]; then
    echo "Inavlid format of arg is passed"
    exit 2
fi

if [[ ! -f "$FILENAME" ]]; then
    echo "Filename is invalid"
    exit 3
fi

REPWD=$(echo "$ARGS" | grep "^-R")

declare -A WDMP# unordered map в bash xD

while read ARG; do
    ARG=$(echo "$ARG" | sed "s/^-R//")
    TREP=$(echo "$ARG" | cut -d '=' -f 1)
    WITH=$(echo "$ARG" | cut -d '=' -f 2)
    WDMP["$WITH"]=$(pwgen -1 10)
    sed -E -i "/^[^#]/s/\b${TREP}\b/${WDMP[${WITH}]}/g" "$FILENAME"
done < <(echo "$REPWD")

while read ARG; do
    ARG=$(echo "$ARG" | sed "s/^-R//")
    TREP=$(echo "$ARG" | cut -d '=' -f 1)
    WITH=$(echo "$ARG" | cut -d '=' -f 2)
    sed -E -i "/^[^#]/s/\b${WDMP[${WITH}]}\b/${WITH}/g" "$FILENAME"
done < <(echo "$REPWD")
