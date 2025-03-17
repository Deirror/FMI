# Напишете серия от команди, които извеждат детайли за файловете и директориите в
# текущата директория, които имат същите права за достъп както най-големият файл
# в /etc директорията

# slow as f***
find ~/ -name '.*' -prune -o -perm $(find /etc 2>/dev/null | xargs -I{} stat -c '%n*%s' {} | sort -t '*' -k 2 -nr | \
head -n 1 | cut -d '*' -f 1 | xargs -I{} stat -c '%a' {}) 2>/dev/null

# blazingly fast solution
find ~/ -name '.*' -prune -o -perm $(find /etc/ -type f 2>/dev/null -print0 | xargs -r -0 wc -c 2>/dev/null | grep "/etc/" | \
sort -nr | head -n 1 | sed -E "s/[^\/]+//" | xargs stat -c "%a")
