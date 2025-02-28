# От всички файлове в home директорията на потребителя velin, изведете дълбочината на файл, който:
# • има същия inode като този на най-скоро променения файл сред тях
# • има минимална дълбочина

find ./ -type f | xargs -I{} ls -i {} | awk -v ins=$(find ./ -type f | xargs -I{} stat --printf "%Y %n\n" {} | sort -nr | head -n 1 \
| cut -d ' ' -f 2 | xargs -r -I{} ls -i {} | cut -d ' ' -f 1) -F ' ' '{if($1 == ins) print $2}' \
| awk -F '/' 'BEGIN{min=2147000; path} {if(min > NF) {min=NF; path=$0}} END{print path}'
