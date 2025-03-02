# Да се напише shell скрипт, който чете от стандартния вход имената на 3 файла,
# обединява редовете на първите два (man paste), подрежда ги по азбучен ред и
# резултата записва в третия файл

#!/bin/bash

read -p "Write three file names: " file1 file2 file3

flag=false

if [[ ! -f ${file1} ]]; then
    echo "First file doesn't exist"
    flag=true
fi
if [[ ! -f ${file2} ]]; then
    echo "Second file doesn't exist"
    flag=true
fi
if [[ ! -f ${file3} ]]; then
    echo "Third file doesn't exist"
    flag=true
fi

if [[ "${flag}" == "true" ]]; then
    exit 1
fi

$(paste ${file1} ${file2} | sort > ${file3})
cat ${file3}
