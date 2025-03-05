# Вашите колеги от съседната лаборатория трябва периодично да променят правата за достъп до обекти
# във файловата система на база на текстови файл с описание на необходимата конфигурация. Всеки
# ред на файла дефинира правило, което гарантирано се състои от три низа, разделени с whitespace

# ... // условието е прекалено дълго, интересна задача е

#!/bin/bash

if [[ "$EUID" -ne 0 ]]; then
    echo "Only root can execute this script"
    exit 1
fi

if [[ $# -ne 1 ]]; then
    echo "Only one arg needed"
    exit 2
fi

if [[ !-f "$1" ]]; then
    echo "Invalid file name"
    exit 3
fi

function chperm {
    if [[ -f "$1" ]]; then
        chmod 664 "$1"
    else
        chmod 755 "$1"
    fi
    echo "Changed perm successfully on $1"
}

PERMS_FILE=$1

while read LINE; do
    DIR=$(cut -d ' ' -f 1)
    TYPE=$(cut -d ' ' -f 2)
    PERM=$(cut -d ' ' -f 3)
    if [[ ! -d "$DIR" || ! "$TYPE" =~ [ART] || ! "$PERM" =~ [0-7]{3,3} ]]; then
        echo "Invalid line $LINE"
    fi
    FILES=$(find "$DIR" -type f,d)
    while read FILE; do
        case $TYPE in
        "A")
        # ...
        "R")
        if [[ "$(stat -c "%a" $FILE)" == "$PERM" ]]; then
            chperm "$FILE"
        fi;;
        "T")
        # ...
        esac
    done < <(echo "$FILES")
done < <(cat "$PERMS_FILE")
