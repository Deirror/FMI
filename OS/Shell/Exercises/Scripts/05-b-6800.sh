# Да се напише shell скрипт, който получава единствен аргумент директория и отпечатва списък с всички файлове и
# директории в нея (без скритите).
# До името на всеки файл да седи размера му в байтове, а до името на всяка директория да седи броят на елементите в нея
# (общ брой на файловете и директориите, без скритите)

#a) Добавете параметър -a, който указва на скрипта да проверява и скритите файлове и директории

#!/bin/bash

if [[ $# -lt 1 || $# -gt 2 ]]; then
    echo "Inavlid number of arguments"
    exit 1
fi

if [[ ! -d $1 ]]; then
    echo "Invalid dir name"
    exit 1
fi

for file in $(find $1 -mindepth 1 -maxdepth 1) ; do
        if [[ -d $file ]]; then
                echo "$file ($(find $file -mindepth 1 -maxdepth 1 | wc -l) entries)"
        elif [[ -f $file ]] ; then
                echo "$file ($(stat -c "%s" $file)b size)"
        fi
done
