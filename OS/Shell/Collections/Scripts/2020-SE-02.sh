#  Напишете shell скрипт, който приема задължителен параметър - име на файл. Файлът е
# log файл на HTTP сървър,в който се записват всички получени от сървъра request-и, които клиентите са изпратили
# ... (виж pdf-a)
# За всеки от top 3 сайта, към които има най-много заявки, скриптът трябва да изведев долния формат:
# • брой на HTTP/2.0 заявките
# • брой на не-HTTP/2.0 заявките
# • top 5 клиента, направили най-много заявки, завършили с код, по-голям от 302 (и броя на съответните им зявки)

#!/bin/bash

if [[ $# -ne 1 ]]; then
    echo "One filename is expected"
    exit 1
fi

if [[ ! -f "$1" ]]; then
    echo "invalid filename"
    exit 2
fi

while read SITE; do
    SITE_LINES=(grep "$SITE" "$1")
    COUNT_HTTP2=$(echo "$SITE_LINES" | grep -o "HTTP/2.0" | wc -l)
    COUNT_NOHTTP2=$(echo "$SITE_LINES" | grep -v "HTTP/2.0" | wc -l)
    echo "$SITE HTTP/2.O: $COUNT_HTTP2 non-HTTP/2.0: $COUNT_NOHTTP2"
done < <(cut -d ' ' -f 2 "$1" | sort | uniq | head -n 3)

TOP5_USERS=$(awk -F ' ' "{col=NF-4; if($col == '302') print $1;" "$1" | sort | uniq -c | head -n 5)
echo "$TOP5_USERS"
