# Намерете и изведете разделени с двоеточие (’:’) 
# успешността и информацията за полезния товар на
# най-скорощния полет, който е изстрелян от космодрума с най-много неуспешни полети

awk -v lsf="$(grep -E 'Failure' ./spacex.txt | cut -d '|' -f 2 | sort | uniq -c | sort -nr | head -n 1 | sed -E 's/^[^0-9]*//g' | cut -d ' ' -f 2)" \
-F '|' 'BEGIN{asap=0; payload; outcome} {if($2 == lsf) {if($1 > asap) {asap=$1; payload=$4; outcome=$3}}} END{print outcome":"payload}' ./spacex.txt
