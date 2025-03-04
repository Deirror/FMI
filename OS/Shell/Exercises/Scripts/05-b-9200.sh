# Да се напише shell скрипт, който получава произволен брой аргументи файлове, които изтрива.
# Ако бъде подадена празна директория, тя бива изтрита. Ако подадения файл е директория с поне 1 файл, тя не се изтрива.
# За всеки изтрит файл (директория) скриптът добавя ред във log файл с подходящо съобщение

# а) Името на log файла да се чете от shell environment променлива, която сте конфигурирали във вашия .bashrc
cat >> ~/.bashrc
export RMLOG_FILE=~/logs/remove.log
source ~/.bashrc

#!/bin/bash

LOG_DIR="${HOME}/tmp/logs"
LOG_FILE="${LOG_DIR}/remove/log"

if [[ ! -d "$LOGD_DIR" ]]; then
    mkdir -p "$LOG_DIR"
    if [[ ! -f "$LOG_FILE" ]]; then
        touch "$LOG_FILE"
    fi
fi

if [[ $# -lt 1 ]]; then
    echo "Not enough arguments passed"
    exit 1
fi

for file in $@; do
    if [[ -f "$file" ]]; then
        rm "$file"
        echo "[$(date +"%Y-%m-%d %H:%M:%S")] Removed file $file" >> $LOG_FILE 
    elif [[ -d "$file" ]]; then
        if [[ $(find "$file" | wc -l) -eq 1 ]]; then
            rmdir "$file"
            echo "[$(date +"%Y-%m-%d %H:%M:%S")] Removed directory $file" >> $LOG_FILE
        fi
    fi
done

# б) Добавете параметър -r на скрипта, който позволява да се изтриват непразни директории рекурсивно
# в) Добавете timestamp на log съобщенията във формата: 2018-05-01 22:51:36

#Примери:
#$ export RMLOG_FILE=~/logs/remove.log
#$ ./rmlog -r f1 f2 f3 mydir/ emptydir/
#$ cat $RMLOG_FILE
#[2018-04-01 13:12:00] Removed file f1
#[2018-04-01 13:12:00] Removed file f2
#[2018-04-01 13:12:00] Removed file f3
#[2018-04-01 13:12:00] Removed directory recursively mydir/
#[2018-04-01 13:12:00] Removed directory emptydir/
