# Намерете и изведете разделени с таб името и масата на обекта, който е едновременно:
# • най-близкият до локалната звезда
# • отсъщиятипкатотипананай-далечният долокалната звезда обект

awk -v ltype="$(sort -t ';' -k 3 -nr planets.txt | head -n 1 | cut -d ';' -f 2)" -F ';' '{if($2 == ltype) print $0}' \ 
planets.txt | sort -t ';' -k 3 -n | head -n 1 | cut -d ';' -f 1,4 | tr ';' '\t'
