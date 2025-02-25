# Отпечатайте правата (permissions) и имената на всички файлове, до които имате
# read достъп, намиращи се в директорията /tmp (hint: 'man find', вижте -readable)

find /tmp -readable 2>/dev/null | xargs -I{} ls -l {} | grep -v 'total' | awk '{printf $1" "$NF"\n"}'
