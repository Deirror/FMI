# Да се напише shell скрипт, който получава при стартиране като параметър в командния ред идентификатор на потребител.
# Скриптът периодично (sleep(1)) да проверява дали потребителят е log-нат, и ако да - да прекратява изпълнението си,
# извеждайки на стандартния изход подходящо съобщение

#!/bin/bash

if [[ $# -ne 1 ]]; then
    echo "Invalid number of arguments"
    exit 1
fi

if ! cut -d ':' -f 3 /etc/passwd | grep -q "$1"; then
    echo "Invalid uid"
    exit 1
fi

username="$(id -un $1)"

while true; do
    if who | grep -q "$username"; then
        echo "$username is logged in"
        break
    fi
    echo "$username is not online"
    sleep 1
done
