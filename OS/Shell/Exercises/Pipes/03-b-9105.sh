# Да се преброят само песните на Beatles и Pink

find songs | grep -E "Pink -|Beatles -" | cut -d '/' -f2 | sort | wc -l
