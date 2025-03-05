# Намерете имената на топ 5 файловете в текущата директория с най-много hardlinks

find ~/ -maxdepth 1 -type f | grep -v -E "/\.[.]*" | xargs -I{} ls -l {} | cut -d ' ' -f 2,9 | sort -nr | head -n 5
