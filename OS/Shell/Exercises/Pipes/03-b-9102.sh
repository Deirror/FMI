# Да се изведат само имената на песните

ls ~/songs | cut -d '.' -f 1 | sed -E 's/^[^-]+- //; s/ \(.*\)//'

# или

ls ~/songs | awk -F ' - ' '{print $2}' | awk -F ' (' '{print $1}'
