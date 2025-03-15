# Напишете шел скрипт, който приема множество параметри. Общ вид на извикване:
# ./foo.sh [-n N] FILE1...
# В общияслучай параметрите се третират като имена на (.log) файлове, които трябва да бъдат обработени
# от скрипта, със следното изключение: ако първият параметър е стрингът-n, то вторият параметър е число,
# дефиниращо стойност на променливата N, която ще ползваме в скрипта. 
# Лог файловете са текстови, като всеки ред има следния формат:
# • време: timestamp във формат YYYY-MM-DD HH:MM:SS
# • интервал
# • данни: поредица от символи с произволна дължина
# За удобство приемаме, че редовете във всеки файл са сортирани по време възходящо
# (виж цялото условие в pdf-а)

#!/bin/bash

if [[ $# -eq 0 ]]; then
    echo "At least one parameter must be passed"
    exit 1
fi

N=10 # default value

if [[ "$1" == "-n" ]]; then
    shift
    if [[ $# -eq 0 ]]; then
        echo "There must be a parameter after -n"
        exit 2
    fi
    if [[ ! "$1" =~ ^(0|[1-9][0-9]*)$ ]]; then
        echo "Parameter after -n must be a valid number"
        exit 3
    fi
    N=$1
    shift
    if [[ $# -eq 0 ]]; then
        echo "There must be filenames after the number"
        exit 4
    fi
fi

MOD_LINES=""

for FILENAME in "$@"; do
    while read -r LINE; do
        IDF="$(echo "$LINE" | sed 's/\.log$//')"
        DATE="$(echo "$LINE" | cut -d ' ' -f 1,2)"
        DATA="$(echo "$LINE" | cut -d ' ' -f 3-)"      
        if [[ -z "$MOD_LINES" ]]; then
            MOD_LINES="$DATE $IDF $DATA"
        else
            MOD_LINES+=$'\n'"$DATE $IDF $DATA"
        fi
    done < <(tail -n "$N" "$FILENAME")
done 

echo "$MOD_LINES" | sort -k1,1 -k2,2 -t ' '
