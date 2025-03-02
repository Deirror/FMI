# Да се напише shell скрипт, който приема точно един параметър и проверява дали подаденият му параметър се състои само от букви и цифри

#!/bin/bash

if [[ ${#} -ne 1 ]] then
    echo "More than one arguments passed"
    exit 1
fi

if echo "${1}" | grep -q -E '^[a-zA-Z0-9]*$' ; then
        echo "yes"
else
        echo "no"
fi

# или

#!/bin/bash

grep -q -E -v '^[a-zA-Z0-9]*$' <(echo "${1}")
echo "${?}"
