# Сортирайте /etc/passwd числово по поле UserID.

sort -n -k 3 -t ':' /etc/passwd
