# Изведете статистика за най-често срещаните символи в трите файла.

 cat dir5/file{1,2,3} | sed 's/./&\n/g' | sort | uniq -c | sort -nr | awk '{if(NF>1) print}'
