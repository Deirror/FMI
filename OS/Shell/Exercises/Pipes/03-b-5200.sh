# Намерете броя на символите, различни от буквата 'а' във файла /etc/passwd

sed "s/./&\n/g" /etc/passwd | sort | uniq -c | awk 'BEGIN{count=0} {if($2!="a" && $2!="а") count+=$1} END{print count}'

# или

sed -E 's/[aа]//g' /etc/passwd | wc -m
