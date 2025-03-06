# Напишете скрипт reconcile.sh, който по подаден файл описващ желано състояние на файловата система, 
# осигурява, че то е спазено...(Виж в pdf-a на скелетони за повече инфо)

#!/bin/bash

if [[ $# -ne 1 ]]; then
    echo "Exactly one argument required"
    exit 1
fi

SYS_STATUS_FILE="$1"

if [[ ! -f $SYS_STATUS_FILE ]]; then
    echo "File with wanted file sys status doesn't exist"
    exit 2
fi

while read LINE; do
    ARGS_COUNT=$(sed "s/ /\n/g" | wc -l)
    if [[ $ARGS_COUNT -lt 2 || $ARGS_COUNT -gt 4]]; then
        echo "Invalid number of arguments - $LINE"
        CONTINUE
    fi
    FILE_PATH=$(cut -d ' ' -f 1)
    TYPE=$(cut -d ' ' -f 2)
    case "$TYPE" in
    "file")
    ;;
    "dir")
    ;;
    "symlink")
    ;;
    "nonexistant")
    ;;
    *)
    echo "Unknown type - $LINE";;
    esac
done < <(cat "$SYS_STATUS_FILE")
