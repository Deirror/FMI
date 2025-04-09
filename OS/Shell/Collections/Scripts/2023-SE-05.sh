# Казваме, че командата foo заема памет 𝑋, когато 𝑋 е сумата на заетата физическа памет (rss) на
# всички процеси, чиято команда (comm) е foo
# Напишете скрипт, който поглежда процесите на системата през една секунда, докато спрат да съществуват команди,
# чиято заета памет е над 65536.
# След това, скриптът трябва да изведе всички команди, които са заемали памет над 65536 в поне половината “поглеждания”

#!/bin/bash

THRESHOLD=65536
TIMES=0
tmp_dir=$(mktemp -d)
counts_file="$tmp_dir/counts.txt"

> "$counts_file"

while true; do
    TIMES=$((TIMES + 1))
    snapshot=$(mktemp)
    ps -e -o rss=,comm= | awk '{arr[$2]+=$1} END {for (i in arr) print i, arr[i]}' > "$snapshot"

    any_over=false

    while read -r cmd mem; do
        if [ "$mem" -gt "$THRESHOLD" ]; then
            echo "$cmd" >> "$counts_file"
            any_over=true
        fi
    done < "$snapshot"

    rm "$snapshot"

    if ! $any_over; then
        break
    fi

    sleep 1
done

sort "$counts_file" | uniq -c | awk -v times="$TIMES" '$1 >= times/2 { print $2 }'

rm -r "$tmp_dir"
