# Използвайки файл population.csv, намерете колко е общото население на света през 2008 година
awk -F ',' 'BEGIN{cnt=0} {if($3 == "2008") cnt+=$4} END{print cnt}' ppl         

# А през 2016?
awk -F ',' 'BEGIN{cnt=0} {if($3 == "2016") cnt+=$4} END{print cnt}' ppl         
