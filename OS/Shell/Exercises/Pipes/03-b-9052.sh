# Използвайки файл population.csv, намерете през коя година в България има най-много население

grep "Bulgaria" ~/ppl | sort -t ',' -k 4 -nr | head -n 1 | cut -d ',' -f 3
