#  Chord Pro е текстов формат за представяне на текстове на песни, анотирани с акорди.
# Всяка поредица от символи, оградена в квадратни скоби, ще наричаме акорд. 
# Първите един или два символа на акорда наричаме основен тон.
# Напишете скрипт transpose.sh, който приема един аргумент (неотрицателно число 𝑁). 
# Скриптът трябва да чете текст във формàта ChordPro от stdin и да изписва 
# аналогичен текст на stdout, заменяйки единствено основните тонове

#!/bin/bash

if [[ $# -ne 1 ]]; then
    echo "One arg needed"
    exit 1
fi

if [[ "$1" =~ ^(0|[1-9][0-9]*)$ ]]; then
    echo "Whole positive integer expected"
    exit 1
fi

N=$(( $1 % 12 ))

if [[ $N -eq 0 ]]; then
    echo "N is equal to zero, so nothing to change..."
    exit 0
fi

TEXT_FILE=$(mktemp)
cat >> "$TEXT_FILE"

CHORD_FILE=$(mktemp)

echo -e "1 A\n2 Bb\n3 B\n4 C\n5 Db\n6 D\n7 Eb\n8 E\n9 F\n10 Gb\n11 G\n12 Ab" > "$CHORD_FILE"

MOD_CHORD_FILE=$(mktemp)

function replchord() {
    local CHORD=$1

    LINE=$(grep "$CHORD$" "$CHORD_FILE" | cut -d ' ' -f1)
    SRCH=$(( $LINE + $N ))

    if [[ $SRCH -gt 12 ]]; then
       SRCH=$(( $SRCH - 12 ))
    fi

    echo "$(grep "^$SRCH" "$CHORD_FILE" | cut -d ' ' -f2)"
}

while read CHORD; do
    NEW_CHORD=$(replchord "$CHORD")
    echo -e "$CHORD $NEW_CHORD" >> "$MOD_CHORD_FILE"
done < <(cut -d ' ' -f2 "$CHORD_FILE")

while read -r LINE; do
    if [[ "$LINE" =~ \[(A|Bb|B|C|Db|D|Eb|E|F|Gb|G|Ab)[a-zA-Z0-9]*\] ]]; then
        for CHORD in $(echo "$LINE" | grep -oP '\[(A|Bb|B|C|Db|D|Eb|E|F|Gb|G|Ab)[a-zA-Z0-9]*\]'); do
            chord_name=$(echo "$CHORD" | tr -d '[]')
            NEW_CHORD=$(grep "^$chord_name " "$MOD_CHORD_FILE" | cut -d ' ' -f2)
            LINE=$(echo "$LINE" | sed "s/\[$chord_name\]/[$NEW_CHORD]/g")
        done
    fi
    
    echo "$LINE"
done < "$TEXT_FILE"

rm -f "$CHORD_FILE"
rm -f "$TEXT_FILE"
rm -f "$MOD_CHORD_FILE"


