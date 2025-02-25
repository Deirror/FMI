# Вземете факултетните номера на студентите (описани във файла
# <РЕПО>/exercises/data/mypasswd.txt) от СИ и ги запишете във файл si.txt сортирани.
cp /srv/fmi-os/exercises/data/mypasswd.txt ./

# Студент е част от СИ, ако home директорията на този потребител (според
# <РЕПО>/exercises/data/mypasswd.txt) се намира в /home/SI директорията.

grep "/home/SI" ~/tm | cut -d ':' -f1 | cut -c 2- | grep -v "[a-zA-Z]" | sort -nr > si.txt 
