# Изпишете всички usernames от /etc/passwd с главни букви.

cut -d ':' -f 1 /etc/passwd | sed -E 's/[[:lower:]]/\U&/g'

# или

cut -d ':' -f 1 /etc/passwd | tr a-z A-Z 
