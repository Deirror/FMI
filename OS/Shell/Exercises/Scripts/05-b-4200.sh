# Имате компилируем (a.k.a няма синтактични грешки) source file на езика C. Напишете shell script, който да покaзва
# колко е дълбоко най-дълбокото nest-ване (влагане)

#!/bin/bash

if [[ ${#} -ne 1 ]] ; then
    echo "Expected one argument"
    exit 1
fi

if [[ ! -f "${1}" ]]; then
    echo "File doesn't exist"
    exit 1
fi

max=0
count=0

while read ch; do
    if [[ "$ch" == "{" ]]; then
        count=$(( count + 1 ))
    else
        if [[ ${max} -lt ${count} ]]; then
            max=${count}
        fi
        count=$(( count - 1 ))
    fi
done < <(grep -E -o "[{}]" "${1}")

echo "The deepest nesting is the level - ${max}"
