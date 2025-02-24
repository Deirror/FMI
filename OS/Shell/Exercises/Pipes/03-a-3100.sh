# Запазете само потребителските имена от /etc/passwd във файл users във вашата home директория.

cut -d ':' -f 1 /etc/passwd > ./usrnm
