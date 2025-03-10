# // бъгаво условие, виж в pdf-a

#!/bin/bash

if [[ $# -ne 1 ]]; then
    echo "Exactly one arg expected"
    exit 1
fi 

DIR="$1"

if [[ ! -d "$DIR" ]]; then
    echo "Log dir with the name - $DIR - doesn't exist"
    exit 2
fi  

FR_COUNT_MSG=""

while read FRIEND; do
    COUNT=0
    while read FILE; do
        COUNT=$(( COUNT + $(wc -l < "$FILE") ))
    done < <(find "$DIR" -type f | grep -E "^${DIR}/[^/]+/[^/]+/${FRIEND}/[0-9]{4}-[0-9]{2}-[0-9]{2}-[0-9]{2}-[0-9]{2}-[0-9]{2}\.txt$")
    FR_COUNT_MSG+="$FRIEND $COUNT"$'\n'
done < <(find "$DIR" -type f | grep -E "^${DIR}/[^/]+/[^/]+/[^/]+/[0-9]{4}-[0-9]{2}-[0-9]{2}-[0-9]{2}-[0-9]{2}-[0-9]{2}\.txt$" | cut -d '/' -f 4 | sort | uniq)

echo "$FR_COUNT_MSG" | sort -t ' ' -k 2 -nr | head
