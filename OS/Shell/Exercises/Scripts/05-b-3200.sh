# Да се напише shell скрипт, който приканва потребителя да въведе пълното име на директория и извежда на стандартния
# изход подходящо съобщение за броя на всички файлове и всички директории в нея

#!/bin/bash

read -p "Write absolute path to dir: " adir

if [[ ! -d ${adir} ]]; then
      echo "Dir doesn't exist"
      exit 1
fi      

file_count="$(find ${adir} -mindepth 1 -type f | wc -l)"
dir_count="$(find ${adir} -mindepth 1 -type d | wc -l)"

echo "Files: ${file_count}"
echo "Dirs: ${dir_count}"
