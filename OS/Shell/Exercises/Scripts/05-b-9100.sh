# Опишете поредица от команди или напишете shell скрипт, които/който при известни две директории SOURCE и DESTINATION:
# - намира уникалните "разширения" на всички файлове, намиращи се някъде под SOURCE
# - за всяко "разширение" създава по една поддиректория на DESTINATION със същото име
# - разпределя спрямо "разширението" всички файлове от SOURCE в съответните поддиректории в DESTINATION

#!/bin/bash

if [[ $# -ne 2 ]]; then
    echo "Two arguments are required"
    exit 1
fi

if [[ ! -d "$1" ]] || [[ ! -d "$2" ]]; then
    echo "Only dirs expected"
    exit 1
fi

while read format; do
    
done < <(find "$1" -type f | grep -E -o "/\.[^\.]+$" | ...(for tommorow))
