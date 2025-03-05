 # Напишете shell скрипт който, ако се изпълнява от root, проверява кои потребители на
 # системата нямат homedir или не могат да пишат в него

#!/bin/bash

if [[ "$EUID" -ne 0 ]] ; then
    echo "This script must be run as root"
    exit 1
fi

grep -v "/home/" /etc/passwd
grep "/home/" /etc/passwd | awk -F ':' '{cmd="stat -c \"%A\" " $6 " | cut -c 3"; cmd | getline perm; close(cmd); if (perm == "-") print $0 }'
