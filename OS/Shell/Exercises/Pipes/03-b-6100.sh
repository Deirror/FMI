# Отпечатайте последната цифра на UID на всички редове между 28-ми и 46-ред в /etc/passwd

sed -n '28,46p' /etc/passwd | cut -d ':' -f 3 | awk '{print substr($0, length($0), 1)}'

# или

 cut -d ':' -f 3 /etc/passwd | head -n 46 | tail -n 28 | sed 's/.*\(.\)$/\1/'
