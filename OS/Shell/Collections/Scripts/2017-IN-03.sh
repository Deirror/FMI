# Напишете скрипт, който извежда името на потребителския акаунт, в чиято home директория 
# има най-скоро променен обикновен файл и кой е този файл. Напишете скрипта сподходящите
# проверки, така че да бъде валиден инструмент

#!/bin/bash


while read USR_HOME_DIR; do
    MAX_CURRFILE_STAT="$(find "$USR_HOME_DIR" -type f 2>/dev/null | xargs -r -I{} stat -c "%Z\|%p" {} | sort -rn | head -n 1)"
    TIMESTMP=$(cut -d '\|' -f 1 < <(echo "$MAX_CURRFILE_STAT"))
    PATH=$(cut -d '\|' -f 2 < <(echo "$MAX_CURRFILE_STAT"))
done < <(cut -d ':' -f 6 etc/passwd)
