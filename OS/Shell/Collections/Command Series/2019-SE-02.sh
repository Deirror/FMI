# Напишете команда, която изкарва разделени с таб факултетните номера и имената на потребителите
# от специалност СИ, чиито home директории са променили статуса си (status change time) в зададения
# времеви интервал.
 
grep ",,,,SI" /etc/passwd | awk -F ':' -v mintime=1740675000 -v maxtime=1740800000 \
'{cmd="stat --printf \"%Z\" " $6; cmd | getline time; close(cmd); if(time >= mintime && time <= maxtime ) printf time":"$0"\n"}' \
| cut -d ':' -f 2,6 | cut -c 2- | sed -E "s/,,,,SI//g" | tr ':' '\t'
