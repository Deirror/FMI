# да приемем, че файловете, които съдържат C код, завършват на `.c` или `.h`.
# Колко на брой са те в директорията `/usr/include`?
find /usr/include/ -type f -name "*.[hc]" | wc -l

# Колко реда C код има в тези файлове?
find /usr/include/ -type f -name "*.[hc]" | xargs -I{} wc -l {} | awk 'BEGIN{cnt=0} {cnt+=$1} END{print cnt}'
