# Да се напише shell скрипт, който чете от стандартния вход име на файл и символен низ, проверява дали низа се съдържа
# във файла и извежда на стандартния изход кода на завършване на командата с която сте проверили наличието на низа

# NB! Символният низ може да съдържа интервал (' ') в себе си.

#!/bin/bash

if [[ ${#} -lt 2 ]]; then
    echo "Expected 2 arguments"
    exit 1
fi

filename=${1}
shift

if [[ ! -f ${filename} ]]; then
    echo "File doesn't exist"
    exit 2
fi

if grep -q "${*}" ${filename}; then
    echo "${filename} contains ${*}"
else
    echo "${filename} doesn't contain ${*}"
fi
