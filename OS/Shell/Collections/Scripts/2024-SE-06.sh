# Напишете скрипт reconcile.sh, който по подаден файл описващ желано състояние на файловата система, 
# осигурява, че то е спазено...(Виж в pdf-a на скелетони за повече инфо)

#!/bin/bash

if [[ $# -ne 1 ]]; then
    echo "ERR> Exactly one argument required"
    exit 1
fi

SYS_STATUS_FILE="$1"

if [[ ! -f $SYS_STATUS_FILE ]]; then
    echo "ERR> File - wanted file sys status - doesn't exist"
    exit 2
fi

while read LINE; do
    ARGS_COUNT=$(sed "s/ /\n/g" | wc -l)
    if [[ $ARGS_COUNT -lt 2 || $ARGS_COUNT -gt 4]]; then
        echo "ERR> Invalid number of arguments - $LINE"
        contimue
    fi
    FILE_PATH=$(cut -d ' ' -f 1)
    TYPE=$(cut -d ' ' -f 2)
    if [[ $# -eq 2 ]]; then
        if [[ "$TYPE" != "nonexistant" ]]; then
            echo "ERR> Invalid type on line - $LINE"
            continue
        fi
        if [[ -e "$FILE_PATH" ]]; then
            echo "ERR> File exists on line - $LINE"
            rm -ri "$FILE_PATH"
        else
            echo "OK> File is nonexistant"
        fi
    else
        if [[ $# -eq 3 ]]; then
            PERM=$(cut -d ' ' -f 3)
            if [[ ! -e "$FILE_PATH" ]]; then
                echo "> Creating file $FILE_PATH"
            fi
        else
            OWNERS=$(cut -d ' ' -f 3) 
            PERM=$(cut -d ' ' -f 4) 
        fi
    fi
done < <(cat "$SYS_STATUS_FILE")


# ------------------
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
