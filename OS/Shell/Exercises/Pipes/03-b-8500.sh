# За всяка група от /etc/group изпишете "Hello, <група>", като ако това е вашата група, напишете "Hello, <група> - I am here!".

 cut -d ':' -f 3 /etc/group | awk -v mg="$(id -g)" '{ printf "Hello, "$1; if($1 == mg) printf " - I am here!\n"; else printf "\n" }'   
