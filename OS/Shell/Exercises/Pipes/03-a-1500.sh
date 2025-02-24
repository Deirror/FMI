# Изведете броя на байтовете в /etc/passwd.

wc -c /etc/passwd | cut -d ' ' -f 1

# Изведете броя на символите в /etc/passwd.

wc -m /etc/passwd | cut -d ' ' -f 1

# Изведете броя на редовете  в /etc/passwd.

wc -l /etc/passwd | cut -d ' ' -f 1
