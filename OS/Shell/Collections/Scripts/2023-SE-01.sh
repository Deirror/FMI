# ...виж pdf-a
#!/bin/bash

if [[ $# -ne 2 ]]; then
	echo "Exactly two args needed"
	exit 1
fi

BAD_WORDS=$1
DIR=$2

if [[ ! -f $BAD_WORDS ]]; then
	echo "Invalid file of bad words"
	exit 2
fi

if [[ ! -d $DIR ]]; then
	echo "Dir is nonexistent"
	exit 3
fi

while read FILE; do
	while read BAD_WORD; do
		LEN=$(echo "$BAD_WORD" | wc -c)
		sed -i "s/${BAD_WORD/\*{$LEN}/g" "$FILE"
	done < <(cat "$BAD_WORDS")
done < <(find "$DIR" -type f | grep -E ".txt$")
