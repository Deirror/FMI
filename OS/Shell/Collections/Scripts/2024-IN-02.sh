#!/bin/bash

if [[ $# -ne 2 ]]; then
    echo "Exactly two args needed"
    exit 1
fi

DIR=$1
OUTPUT=$2

if [[ ! -d "$DIR" ]]; then
    echo "Invalid dir path is passed"
    exit 2
fi

if [[ ! -f "$OUTPUT" ]]; then
    mkdir -p "$(dirname "$OUTPUT")"
    touch "$OUTPUT"
fi

> "$OUTPUT"

while read HFILE; do
    while read CLASS_ROW; do
        CNAME="$(echo "$CLASS_ROW" | cut -d ' ' -f 2)"
        PS="$(echo "$CLASS_ROW" | tr ',' '\n' | awk -F ' ' '{print $NF}')"
        echo "$CNAME" >> "$OUTPUT"
        while read P; do
            echo "$P -> $CNAME" >> "$OUTPUT"
        done < <(echo "$PS")
    done < <(grep "^class" "$HFILE")
done < <(find "$DIR" -type f 2>/dev/null | grep ".h$")
