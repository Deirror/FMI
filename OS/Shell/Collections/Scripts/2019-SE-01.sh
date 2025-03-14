# Напишете скрипт,който четe редове oт STDIN. Скриптa
# трябва да обработва само редовете, които съдържат цели положителни или отрицателни числа;
# останалите редове се игнорират. Скриптът трябва да извежда на STDOUT:
# всички уникални числа, чиято абсолютна стойност е равна на максималната абсолютна стойност сред всички числа
#!bin/bash

MAX_NUM=''
NUMS=""
while read LINE; do
    if [[ ! "$LINE" =~ ^-?(0|[1-9][0-9]*)$ ]]; then
        continue
    fi
    ABS_NUM=$(( LINE < 0 ? -LINE : LINE ))
    NUMS+=$'\n'"$ABS_NUM"
    if [[ -z $MAX_NUM ]];
        then
        MAX_NUM=$ABS_NUM
        continue
    fi;
    MAX_NUM=$(( ABS_NUM > MAX_NUM ? ABS_NUM : MAX_NUM ))
done
if grep -q -- "^-${MAX_NUM}$" <<< "$NUMS"; then
    echo -e "-$MAX_NUM\n${MAX_NUM}"
else
    echo "$MAX_NUM"
fi
