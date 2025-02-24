# Изведете целите редове от /etc/passwd за хората от 03-a-5003

 cut -d ':' -f 5 /etc/passwd | cut -d ',' -f 1 | cut -d ' ' -f 2 | grep -E '^.{1,6}$' | sort | uniq | xargs -I{} grep -w {} /etc/passwd
