# Да се напише shell скрипт, който приема файл и директория. Скриптът проверява в подадената директория и нейните
# под-директории дали съществува копие на подадения файл и отпечатва имената на намерените копия, ако съществуват такива

if [[ $# -ne 2 ]] ; then
    echo "Invalid number of arguments"
    exit 1
fi

for file in $(find $2 -type f) ; do
    diff -q $1 $file > /dev/null
    if [[ $? -eq 0 ]] ; then
          echo "$file"
    fi
done
