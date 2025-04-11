# Вие сте част от екип от физици от бъдещето, които анализират данни, събрани от различни наблюдателни точки в космоса. 
# Разполагате с файлове с данни, които съдържат информация за разстоянието от наблюдателната точка до различни черни дупки в космоса

 #!/bin/bash

if [[ $# -ne 3 ]]; then
    echo "Three args needed"
    exit 1
fi

POINT_1=$1
POINT_2=$2
BLACK_HOLE=$3

if [[ ! -f "$POINT_1" ]]; then
    echo "File 1 is invalid"
    exit 2
fi

if [[ ! -f "$POINT_2" ]]; then
    echo "File 2 is invalid"
    exit 2
fi

LINES=$(grep "${BLACK_HOLE}" "${POINT_1}" | cut -d ':' -f2 | cut -d ' ' -f2- | sed "s/megaparsecs/${POINT_1}/g")
LINES+=$'\n'"$(grep "${BLACK_HOLE}" "${POINT_2}" | cut -d ':' -f2 | cut -d ' ' -f2- | sed "s/megaparsecs/${POINT_2}/g")"

echo "$LINES" | sort -n | head -n 1
