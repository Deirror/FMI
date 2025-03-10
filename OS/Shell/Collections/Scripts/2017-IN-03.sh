# Напишете скрипт, който извежда името на потребителския акаунт, в чиято home директория 
# има най-скоро променен обикновен файл и кой е този файл. Напишете скрипта сподходящите
# проверки, така че да бъде валиден инструмент

#!/bin/bash

MAX_CURRFILE_STAT=""
while read USR_HOME_DIR; do
    USRNM=$(cut -d ':' -f 1 < <(echo "$USR_HOME_DIR"))
    MAX_CURRFILE_STAT+="$(find "$USR_HOME_DIR" -type f 2>/dev/null -exec stat -c "%Z|$USRNM|%n" {} +)"$'\n'
done < <(cut -d ':' -f 6 /etc/passwd)

WINNER=$(sort -t '|' -k 1 -nr < <(echo "$MAX_CURRFILE_STAT") | head -n 1 | cut -d '|' -f 2,3 | tr '|' ' ')
echo "$WINNER"
