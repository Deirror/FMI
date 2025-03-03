# Напишете shell script, който да приема параметър име на директория, от която взимаме файлове, и опционално експлицитно
# име на директория, в която ще копираме файлове. Скриптът да копира файловете със съдържание, променено преди по-малко
# от 45 мин, от първата директория във втората директория. Ако втората директория не е подадена по име, нека да получи
# такова от днешната дата във формат, който ви е удобен. При желание новосъздадената директория да се архивира

#!/bin/bash

cp_dir_name=''

if [[ $# -eq 1 ]]; then
    if [[ ! -d $1 ]]; then
        echo "Dir doesn't exist: $1"
        exit 1 
    fi
    cp_dir_name='./$(date +"%d-%m-%y")'
    if [[! -d $cp_dir_name]]; then
        mkdir -p ./$cp_dir_name
    fi
elif [[ $# -eq 2 ]]; then
    flag=false
    if [[ ! -d $1 ]]; then
        echo "Dir doesn't exist: $1"; flag=true
    fi
    if [[ ! -d $2 ]]; then
        echo "Dir doesn't exist: $2"; flag=true
    fi
    if [[ $flag == true ]]; then
        exit 1
    fi
    cp_dir_name='$2'
else
    echo "Invalid count of arguments"
    exit 1
fi

find $1 -mindepth 1 -maxdepth 1  -type f -mmin 45 -print0 | xargs -0 -r -I{} mv {} $cp_dir_name
