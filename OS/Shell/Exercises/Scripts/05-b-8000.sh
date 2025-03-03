# Напишете shell script, който получава като единствен аргумент име на потребител и за всеки негов процес изписва
# съобщение за съотношението на RSS към VSZ. Съобщенията да са сортирани, като процесите с най-много заета виртуална
# памет са най-отгоре

if [[ $# -ne 1 ]] ; then
    echo "Expected 1 argument - user name"
    exit 1
fi

username=$(grep "${1}" /etc/passwd | awk -F ':' '{print $1}')

ps -A -o user,pid,tty,pid,rss,vsz --sort -vsz | grep "^${username}" | awk '{print $5/$6}'
