# Използвайки файл population.csv, намерете коя държава има най-много население през 2016. 
grep ",2016," ~/ppl | tr ',' ' ' | awk 'BEGIN{max=0; c=""} {if(max < $NF) {max=$NF; c=$1;}} END{print c"-"max}'

# А коя е с най-малко население?
grep ",2016," ~/ppl | tr ',' ' ' | awk 'BEGIN{min=2147483647; c=""} {if(min > $NF) {min=$NF; c=$1;}} END{print c"-"min}'
