# Напишете shell скрипт, който приема един позиционен параметър-число. Ако скриптът
# се изпълнява като root, да извежда обобщена информация за общото количество активна памет 
# (RSS-resident set size, non-swapped physical memory that a task has used) на процесите на всеки потребител.
# Ако за някой потребител обобщеното число надвишава подадения параметър, да изпраща подходящи
# сигнали за прекратяване на процеса с най-много активна памет на потребителя

#!/bin/bash

if [[ "$EUID" -ne 0 ]] ; then
        echo "This script must be run as root"
        exit 1
fi

if [[ $# -ne 1 ]] ; then
    echo "Expected 1 argument - number"
    exit 1
fi

echo ${1} | egrep -q "[-]{0,1}[0-9]*"

if [[ ${?} -ne 0 ]] ; then
    echo "Expected 1 argument - number"
    exit 1
fi

results=$(ps -e -o uid,pid,rss | tail -n +2 |sort -k1n | awk 'BEGIN{uid=$1;rss=0} {if (uid!=$1) {print uid " " rss; uid=$1;rss=$3} else rss+=$3} END{print uid " " rss}')

while read line ; do
    user=$(echo "${line}" | awk '{print $1}')
    sum=$(echo "${line}" | awk '{print $2}')
    echo "${user} ${sum}"
    if [[ ${sum} -gt ${1} ]] ; then
                pid=$(ps -u "${user}" -o uid,pid,rss | tail -n +2 | sort -k3nr | head -n1 | awk '{print $2}')
        kill pid
    fi
done < <(echo "${results}")
